#include "weapon.h"

Weapon::Weapon() : m_name("Unknown"), m_classe("Unknown"), m_type("Unknown"), m_effect("Unknown"), m_image("Unknown")
{
}

Weapon::Weapon(QString name, QString classe, QString type, QString effect, QString image, QObject *parent)
    : QObject(parent), m_name(name), m_classe(classe), m_type(type), m_effect(effect), m_image(image)
{
    connect(this, &Weapon::classeChanged, this, &Weapon::weaponChanged );
    connect(this, &Weapon::nameChanged, this, &Weapon::weaponChanged );
    connect(this, &Weapon::typeChanged, this, &Weapon::weaponChanged );
    connect(this, &Weapon::effectChanged, this, &Weapon::weaponChanged );
    connect(this, &Weapon::imageChanged, this, &Weapon::weaponChanged );
}

QString Weapon::name() {
    return m_name;
}

QString Weapon::classe() {
    return m_classe;
}

QString Weapon::effect() {
    return m_effect;
}

QString Weapon::type() {
    return m_type;
}
QString Weapon::image() {
    return m_image;
}

void Weapon::setName(QString name) {
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void Weapon::setClasse(QString classe) {
    if (m_classe == classe)
        return;

    m_effect = classe;
    emit nameChanged(m_classe);
}

void Weapon::setEffect(QString effect) {
    if (m_effect == effect)
        return;

    m_effect = effect;
    emit nameChanged(m_effect);
}

void Weapon::setType(QString type) {
    if (m_type == type)
        return;

    m_type = type;
    emit nameChanged(m_type);
}

void Weapon::setImage(QString image) {
    if (m_image == image)
        return;

    m_image = image;
    emit imageChanged(m_image);
}

