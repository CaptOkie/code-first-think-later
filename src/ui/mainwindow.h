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

    private slots:
        void handleStudentBtn();
        void handleAdminBtn();

    private:
        Ui::MainWindow *ui;
        int login;
        int studentLogin;
        int adminLogin;
};

#endif // MAINWINDOW_H
