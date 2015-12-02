#include "usercontrolfactory.h"

UserControlFactory::UserControlFactory()
{
}

UserControlFactory::~UserControlFactory()
{
}

UserControl* UserControlFactory::getUser(QString id, QString type){
    if (type == "admin"){
        AdminControl* admin;
        admin->user = storage.getAdmin(id.toInt()); //temporary going to fix
        return admin;
    }
    else if (type == "student"){
        StudentControl* stu;
        stu->user = storage.getStudent(id.toInt()); //temporary going to fix
        return stu;
    }
    else {
        return NULL;
    }
}
