#include "proxyadmin.h"

ProxyAdmin::ProxyAdmin(int id, QString* name, AdminStorage* storage)
    : Admin(id, name), realAdmin(NULL), storage(storage)
{ }

ProxyAdmin::~ProxyAdmin()
{
    if (realAdmin)
        delete realAdmin;

    if(storage)
        delete storage;
}
