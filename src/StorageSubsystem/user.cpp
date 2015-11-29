#include "user.h"

User::User(int id, QString* name)
    : id(id), name(name)
{ }

User::User(const User& user)
    : id(user.getId()), name(new QString(user.getName()))
{ }

User::~User()
{
    delete name;
}

int User::getId() const
{
    return id;
}

const QString& User::getName() const
{
    return *name;
}
