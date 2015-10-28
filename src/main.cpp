#include "ui/mainwindow.h"
#include <QApplication>

#include "db/storage.h"

int main(int argc, char *argv[])
{
    Storage db = Storage();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
