#include "proxyadmin.h"

ProxyAdmin::ProxyAdmin(int id, QString name)
    : id(id), name(name), realAdmin(NULL)
{ }

ProxyAdmin::~ProxyAdmin()
{
    if (realAdmin)
        delete realAdmin;
}
