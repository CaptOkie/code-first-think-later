#include "user.h"

User::User(Type type, QString* name)
    : type(type), name(name)
{

}

User::~User() {
    delete name;
}

User::Type User::getType() {
    return type;
}
