#include "user.h"

User::User(int id, Type type, QString* name)
    : id(id), type(type), name(name)
{

}

User::~User() {
    delete name;
}

int User::getId() {
    return id;
}

User::Type User::getType() {
    return type;
}

QString& User::getName() {
    return *name;
}
