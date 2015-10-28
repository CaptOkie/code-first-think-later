#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginwidget.h"
#include "studentloginwidget.h"

#include "adminlogindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LoginWidget* loginWidget = new LoginWidget(ui->stackedWidget);
    StudentLoginWidget* studentLoginWidget = new StudentLoginWidget(ui->stackedWidget);

    login = ui->stackedWidget->addWidget(loginWidget);
    studentLogin = ui->stackedWidget->addWidget(studentLoginWidget);

    ui->stackedWidget->setCurrentIndex(login);

    loginWidget->setStudentBtnHandler(SIGNAL(clicked()), SLOT(handleStudentBtn()), this);
    loginWidget->setAdminBtnHandler(SIGNAL(clicked()), SLOT(handleAdminBtn()), this);
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
    QDialog* adminDialog = new AdminLoginDialog(parentWidget());
    adminDialog->exec();
}
