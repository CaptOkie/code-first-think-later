#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginwidget.h"
#include "studentloginwidget.h"
#include "adminloginwidget.h"

#include "adminhomewidget.h"

MainWindow::MainWindow(Storage* db, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), db(db)
{
    ui->setupUi(this);

    showLogin();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeView(QWidget* widget)
{
    QWidget* old = ui->stackedWidget->currentWidget();
    ui->stackedWidget->addWidget(widget);
    if (old != 0) {
        ui->stackedWidget->removeWidget(old);
        delete old;
    }
}

void MainWindow::showLogin()
{
    LoginWidget* loginWidget = new LoginWidget();
    changeView(loginWidget);
    connect(loginWidget, &LoginWidget::studentSelected, this, &MainWindow::showStudentLogin);
    connect(loginWidget, &LoginWidget::adminSelected, this, &MainWindow::showAdminLogin);
}

void MainWindow::showStudentLogin()
{
    StudentLoginWidget* studentLoginWidget = new StudentLoginWidget();
    changeView(studentLoginWidget);
    connect(studentLoginWidget, &StudentLoginWidget::cancelled, this, &MainWindow::showLogin);
}

void MainWindow::showAdminLogin()
{
    AdminLoginWidget* adminLoginWidget = new AdminLoginWidget(ui->stackedWidget);
    changeView(adminLoginWidget);
    connect(adminLoginWidget, &AdminLoginWidget::loggedIn, this, &MainWindow::showAdminHome);
    connect(adminLoginWidget, &AdminLoginWidget::cancelled, this, &MainWindow::showLogin);
}

void MainWindow::showAdminHome()
{
    AdminHomeWidget* adminHomeWidget = new AdminHomeWidget(ui->stackedWidget);
    changeView(adminHomeWidget);
}
