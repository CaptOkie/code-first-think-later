#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginwidget.h"
#include "studentloginwidget.h"
#include "adminloginwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LoginWidget* loginWidget = new LoginWidget(ui->stackedWidget);
    StudentLoginWidget* studentLoginWidget = new StudentLoginWidget(ui->stackedWidget);
    AdminLoginWidget* adminLoginWidget = new AdminLoginWidget(ui->stackedWidget);

    login = ui->stackedWidget->addWidget(loginWidget);
    studentLogin = ui->stackedWidget->addWidget(studentLoginWidget);
    adminLogin = ui->stackedWidget->addWidget(adminLoginWidget);

    ui->stackedWidget->setCurrentIndex(login);

    connect(loginWidget->getStudentBtn(), &QPushButton::clicked, this, &MainWindow::handleStudentBtn);
    connect(loginWidget->getAdminBtn(), &QPushButton::clicked, this, &MainWindow::handleAdminBtn);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleStudentBtn()
{
    ui->stackedWidget->setCurrentIndex(studentLogin);
}

void MainWindow::handleAdminBtn()
{
    ui->stackedWidget->setCurrentIndex(adminLogin);
}
