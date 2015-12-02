#include <QApplication>
#include <QDesktopWidget>

#include "LoginSubsystem/logincontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginControl control;
    control.start();

    return a.exec();
}
