#include "profilecontrol.h"

ProfileControl::ProfileControl(Student* stu)
    : profileForm(*this), student(stu)
{
}

ProfileControl::~ProfileControl()
{
}

void ProfileControl::start()
{
    profileForm.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            profileForm.size(),
            qApp->desktop()->availableGeometry()
        )
    );
    profileForm.setName(student);
    profileForm.show();
}
