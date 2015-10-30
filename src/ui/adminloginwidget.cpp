#include "adminloginwidget.h"
#include "ui_adminloginwidget.h"

AdminLoginWidget::AdminLoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminLoginWidget)
{
    ui->setupUi(this);

    connect(ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this, &AdminLoginWidget::handleOkBtn);
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::clicked, this, &AdminLoginWidget::handleCancelBtn);
}

AdminLoginWidget::~AdminLoginWidget()
{
    delete ui;
}

void AdminLoginWidget::handleOkBtn()
{
    QString id = ui->adminInput->text();
    emit loggedIn(id);
}

void AdminLoginWidget::handleCancelBtn()
{
    emit cancelled();
}
