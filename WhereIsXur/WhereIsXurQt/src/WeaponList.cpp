#include "WeaponList.h"
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "weapon.h"


WeaponList::WeaponList(QString path, QObject *parent) : QObject(parent)
{
    m_weapons = QList<Weapon*>();

    QFile file(path);

    if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
    }

    QByteArray json = file.readAll();


    // Lire le json pour remplir la liste
    QJsonDocument doc = QJsonDocument(QJsonDocument::fromJson(json));

    QJsonObject objet(doc.object());

    QJsonArray array(objet["weapons"].toArray());

    foreach (const QJsonValue &value, array) {
        QJsonObject obj = value.toObject();

        if (obj.contains("name"), obj.contains("classe"), obj.contains("type"), obj.contains("effect"), obj.contains("image"))
        {
            createWeaponDetail(obj["name"].toString(), obj["classe"].toString(), obj["type"].toString(), obj["effect"].toString(), obj["image"].toString());
        }
    }
}

int WeaponList::count() const
{
    return m_weapons.count();
}

Weapon *WeaponList::at(int place) const
{
    return m_weapons.at(place);
}

void WeaponList::removeWeapon(int position)
{
    emit preWeaponRemoved(position);

    // No longer care for the file change
    disconnect ( m_weapons[position], &Weapon::weaponChanged, this, 0);

    m_weapons.removeAt(position);

    // Reconnect to good positions
    for ( ; position < count() ; ++position ) {
        disconnect ( m_weapons[position], &Weapon::weaponChanged, this, 0);
        connect( m_weapons[position], &Weapon::weaponChanged, this, [=](){ emit WeaponList::WeaponChanged( position ); } );
    }
    emit postWeaponRemoved();
}


void WeaponList::createWeaponDetail(QString name, QString classe, QString type, QString effect, QString image)
{
    append(new Weapon(name, classe, type, effect, image));
}

void WeaponList::append(Weapon *w)
{
    emit preWeaponAppended();
    int position = count();
    connect(w, &Weapon::weaponChanged, this, [=](){ emit WeaponList::WeaponChanged( position ); } );
    m_weapons.append(w);
    emit postWeaponAppended();
}

QList<Weapon*> WeaponList::getWeapons()
{
    return m_weapons;
}
