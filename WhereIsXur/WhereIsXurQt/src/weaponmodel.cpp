#include "weaponmodel.h"
#include "WeaponList.h"
#include "weapon.h"


WeaponModel::WeaponModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int WeaponModel::rowCount(const QModelIndex &parent) const
{
    if ( parent.isValid())
        return 0;

    return m_weaponList->count();
}

WeaponList *WeaponModel::list() const
{
    return m_weaponList;
}

QVariant WeaponModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto weapon = m_weaponList->at(index.row());

    switch (role) {
    case Name:
        return weapon->name();
    case Classe:
        return weapon->classe();
    case Effect:
        return weapon->effect();
    case Type:
        return weapon->type();
    case Image:
        return weapon->image();
    case Weapon:
        return QVariant::fromValue(weapon);
    default:
        break;
    }
    return QVariant();
}

bool WeaponModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {

        auto weapon = m_weaponList->at(index.row());

        switch (role) {
        case Name:
            weapon->setName(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        case Classe:
            weapon->setClasse(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        case Type:
            weapon->setType(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        case Effect:
            weapon->setEffect(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        case Image:
            weapon->setImage(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        default:
            break;
        }
        return true;
    }
    return false;
}

Qt::ItemFlags WeaponModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> WeaponModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[Name] = "name";
    roles[Classe] = "classe";
    roles[Type] = "type";
    roles[Effect] = "effect";
    roles[Image] = "image";

    return roles;
}

void WeaponModel::newElement()
{
    QString name(tr("Unknown"));
    QString classe(tr("Unknown"));
    QString type(tr("Unknown"));
    QString effect(tr("Unknown"));
    QString image(tr("Unknown"));
    QTextStream stream(&name);
    stream << "-" << m_weaponList->count();

    m_weaponList->createWeaponDetail(name, classe, type, effect, image);
}

void WeaponModel::removeRow(int index)
{
    m_weaponList->removeWeapon(index);
}

WeaponList *WeaponModel::name() const
{
    return m_weaponList;
}

void WeaponModel::setweaponList(WeaponList *weaponList)
{
    if (m_weaponList == weaponList)
        return;

    m_weaponList = weaponList;
    emit weaponListChanged(m_weaponList);
}

