#include "studentcontrol.h"

StudentControl::StudentControl(Student* student)
    : stuForm(*this), student(student)//, editProfileControl()
{ }

StudentControl::~StudentControl()
{
    if (student) {
        delete student;
    }
}

void StudentControl::start()
{
    stuForm.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            stuForm.size(),
            qApp->desktop()->availableGeometry()
        )
    );
    stuForm.setName(student->getName());
    stuForm.show();
}

void StudentControl::editProfile()
{

}
