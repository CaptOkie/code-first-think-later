#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../db/storage.h"
#include "../enum/usertype.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(Storage&, QWidget* parent = 0);
        ~MainWindow();

    private slots:
        void showLogin();
        void showHome(UserType userType);

    private:
        Ui::MainWindow* ui;
        Storage& db;

        void changeView(QWidget* widget);
};

#endif // MAINWINDOW_H
