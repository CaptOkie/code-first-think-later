#include <QApplication>
#include "LoginSubsystem/loginform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginForm w;
    w.show();

    return a.exec();
}
