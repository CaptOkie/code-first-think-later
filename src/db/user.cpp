#include "user.h"

User::User(int id, Type type, QString* name)
    : id(id), type(type), name(name)
{ }

User::User(int id, Type type, const QString& name)
    : id(id), type(type), name(new QString(name))
{ }

User::User(const User& copy)
    : id(copy.getId()), type(copy.getType()), name(new QString(copy.getName()))
{ }

User::~User() {
    delete name;
}

int User::getId() const {
    return id;
}

User::Type User::getType() const {
    return type;
}

QString& User::getName() const {
    return *name;
}
