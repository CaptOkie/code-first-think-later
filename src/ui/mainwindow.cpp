#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginwidget.h"
#include "studentloginwidget.h"
#include "adminloginwidget.h"

#include "adminhomewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add LoginWidget
    LoginWidget* loginWidget = new LoginWidget(ui->stackedWidget);
    login = addWidget(loginWidget);
    connect(loginWidget, &LoginWidget::studentSelected, this, &MainWindow::showStudentLogin);
    connect(loginWidget, &LoginWidget::adminSelected, this, &MainWindow::showAdminLogin);

    // Add StudentLoginWidget
    StudentLoginWidget* studentLoginWidget = new StudentLoginWidget(ui->stackedWidget);
    studentLogin = addWidget(studentLoginWidget);
    connect(studentLoginWidget, &StudentLoginWidget::cancelled, this, &MainWindow::showLogin);

    // Add AdminLoginWidget
    AdminLoginWidget* adminLoginWidget = new AdminLoginWidget(ui->stackedWidget);
    adminLogin = addWidget(adminLoginWidget);
    connect(adminLoginWidget, &AdminLoginWidget::submitted, this, &MainWindow::attemptAdminLogin);
    connect(adminLoginWidget, &AdminLoginWidget::cancelled, this, &MainWindow::showLogin);

    // Add AdminHomeWidget
    AdminHomeWidget* adminHomeWidget = new AdminHomeWidget(ui->stackedWidget);
    adminHome = addWidget(adminHomeWidget);

    // Set the starting page
    changeView(login);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::addWidget(QWidget* widget)
{
    widget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    return ui->stackedWidget->addWidget(widget);
}

void MainWindow::changeView(int index)
{
    if (ui->stackedWidget->currentWidget() != 0) {
        ui->stackedWidget->currentWidget()->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    }
    ui->stackedWidget->setCurrentIndex(index);
    if (ui->stackedWidget->currentWidget() != 0) {
        ui->stackedWidget->currentWidget()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
}

void MainWindow::showLogin()
{
    changeView(login);
}

void MainWindow::showStudentLogin()
{
    changeView(studentLogin);
}

void MainWindow::showAdminLogin()
{
    changeView(adminLogin);
}

void MainWindow::attemptAdminLogin(QString& id)
{
    changeView(adminHome);
}
