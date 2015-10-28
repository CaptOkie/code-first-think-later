#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        void showLogin();
        void showStudentLogin();
        void showAdminLogin();
        void showAdminHome();

    private:
        Ui::MainWindow *ui;
        int login;
        int studentLogin;
        int adminLogin;
        int adminHome;

        int addWidget(QWidget* widget);
        void changeView(int index);
};

#endif // MAINWINDOW_H
