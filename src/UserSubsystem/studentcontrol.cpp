#include "studentcontrol.h"

StudentControl::StudentControl(Student* student)
    : stuForm(), student(student)
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
    //stuForm.setName(user->getName());
    stuForm.show();
}
