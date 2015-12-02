#include "studentcontrol.h"

StudentControl::StudentControl()
{
}

StudentControl::~StudentControl()
{

}

void StudentControl::start()
{
    stuForm = new StudentForm();
    stuForm->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    stuForm->size(),
                    qApp->desktop()->availableGeometry()
                )
            );
    //stuForm->setName(user->getName());
    stuForm->show();
}
