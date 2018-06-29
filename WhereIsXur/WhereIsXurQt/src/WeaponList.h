#ifndef LISTITEM_H
#define LISTITEM_H

#include <QObject>

class Weapon;

class WeaponList : public QObject
{
    Q_OBJECT
    QList<Weapon*> m_weapons;
public:
    WeaponList(QString path, QObject *parent = nullptr);
    void append(Weapon* w);

    Weapon *at(int place) const;
    QList<Weapon*> getWeapons();
    int count() const;
    void createWeaponDetail(QString name, QString classe, QString type, QString effect, QString image);
    void removeWeapon(int position);

signals:
    void preWeaponAppended();
    void postWeaponAppended();

    void preWeaponRemoved(int index);
    void postWeaponRemoved();

    void WeaponChanged(int row);
};

#endif // LISTITEM_H
