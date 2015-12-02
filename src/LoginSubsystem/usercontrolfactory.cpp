#include "usercontrolfactory.h"

UserControlFactory::UserControlFactory()
{
}

UserControlFactory::~UserControlFactory()
{
}

UserControl* UserControlFactory::getUser(QString id, QString type){
    if (type == "admin"){
        AdminControl* admin = new AdminControl();
        admin->user = storage.getAdmin(id.toInt());
        if (admin->user == NULL){
            delete admin;
            return NULL;
        }
        return admin;
    }
    else if (type == "student"){
        StudentControl* stu = new StudentControl();
        stu->user = storage.getStudent(id.toInt());
        if (stu->user == NULL){
            delete stu;
            return NULL;
        }
        return stu;
    }
    else {
        return NULL;
    }
}
