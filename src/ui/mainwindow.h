#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../db/storage.h"
#include "../db/user.h"

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
        void showHome(User*);

    private:
        Ui::MainWindow* ui;
        Storage& db;
        User* currUser;

        void changeView(QWidget* widget);
};

#endif // MAINWINDOW_H
