#ifndef WEAPONMODEL_H
#define WEAPONMODEL_H

#include <QAbstractListModel>

class WeaponList;

class WeaponModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(WeaponList *weaponList READ name WRITE setweaponList NOTIFY weaponListChanged)
    WeaponList* m_weaponList;

public:
    explicit WeaponModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;

    WeaponList *list() const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QHash<int, QByteArray> roleNames() const;
    enum {
        Weapon = Qt::UserRole,
        Name,
        Classe,
        Type,
        Effect,
        Image
    };

    void setList(WeaponList *list);

    Q_INVOKABLE void newElement();
    Q_INVOKABLE void removeRow(int index);

    WeaponList *name() const;
public slots:
    void setweaponList(WeaponList* weaponList);
signals:
    void weaponListChanged(WeaponList* weaponList);
};

#endif // WEAPONMODEL_H
