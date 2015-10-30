#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../db/storage.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(Storage* db = 0, QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void showLogin();
        void showStudentLogin();
        void showAdminLogin();
        void showAdminHome();

    private:
        Ui::MainWindow *ui;
        Storage* db;

        void changeView(QWidget* widget);
};

#endif // MAINWINDOW_H
