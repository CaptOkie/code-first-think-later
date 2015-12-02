#include "usercontrolfactory.h"
#include "StorageSubsystem/admin.h"
#include "StorageSubsystem/student.h"

UserControlFactory::UserControlFactory()
    : storage()
{ }

UserControlFactory::~UserControlFactory()
{ }

UserControl* UserControlFactory::getUser(int id, Type type){

    Admin* admin = NULL;
    Student* student = NULL;
    switch (type) {
        case AdminType:
            admin = storage.getAdmin(id);
            if (admin) {
                return new AdminControl(admin);
            }
            break;
        default:
            student = storage.getStudent(id);
            if (student) {
                return new StudentControl(student);
            }
            break;
    }

    return NULL;
}
