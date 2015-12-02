#include <QApplication>
#include <QDesktopWidget>

#include "LoginSubsystem/loginform.h"

void center(QWidget &widget ,int WIDTH , int HEIGHT)
{
    int x, y;
    int screenWidth;
    int screenHeight;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    widget.setGeometry(x, y, WIDTH, HEIGHT);
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginForm w;
    center(w, w.width(), w.height());
    w.show();

    return a.exec();
}
