#ifndef ITEMDETAIL_H
#define ITEMDETAIL_H
#include <QtQuick>
#include <QObject>

class Weapon : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString classe READ classe WRITE setClasse NOTIFY classeChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString effect READ effect WRITE setEffect NOTIFY effectChanged)
    Q_PROPERTY(QString image READ image WRITE setImage NOTIFY imageChanged)

    QString m_name;
    QString m_classe;
    QString m_type;
    QString m_effect;
    QString m_image;
public:
    Weapon();
    explicit Weapon(QString name, QString classe, QString type, QString effect, QString image, QObject *parent = nullptr);
    QString name();
    QString classe();
    QString type();
    QString effect();
    QString image();

signals:
    void nameChanged(QString name);
    void classeChanged(QString classe);
    void typeChanged(QString type);
    void effectChanged(QString effect);
    void imageChanged(QString image);

    void weaponChanged();
public slots:
    void setName(QString name);
    void setClasse(QString classe);
    void setType(QString type);
    void setEffect(QString effect);
    void setImage(QString image);
};

#endif // ITEMDETAIL_H
