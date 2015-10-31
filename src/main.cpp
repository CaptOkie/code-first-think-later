#include "ui/mainwindow.h"
#include <QApplication>

#include "db/storage.h"

int main(int argc, char *argv[])
{
    Storage db;

    QApplication a(argc, argv);
    MainWindow w(db);
    w.show();

    return a.exec();
}
