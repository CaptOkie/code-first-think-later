#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    connect(ui->studentBtn, &QPushButton::clicked, this, &LoginWidget::handleStudentBtn);
    connect(ui->adminBtn, &QPushButton::clicked, this, &LoginWidget::handleAdminBtn);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::handleAdminBtn()
{
    emit adminSelected();
}

void LoginWidget::handleStudentBtn()
{
    emit studentSelected();
}
