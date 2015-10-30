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
        void showAdminHome(QString& id);

    private:
        Ui::MainWindow *ui;

        void changeView(QWidget* widget);
};

#endif // MAINWINDOW_H
