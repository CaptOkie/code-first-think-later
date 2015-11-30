#include "proxyadmin.h"

ProxyAdmin::ProxyAdmin(int id, QString* name)
    : Admin(id, name), realAdmin(NULL)
{ }

ProxyAdmin::~ProxyAdmin()
{
    if (realAdmin)
        delete realAdmin;
}
