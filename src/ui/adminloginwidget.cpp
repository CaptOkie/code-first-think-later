#include "adminloginwidget.h"
#include "ui_adminloginwidget.h"

AdminLoginWidget::AdminLoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminLoginWidget)
{
    ui->setupUi(this);
}

AdminLoginWidget::~AdminLoginWidget()
{
    delete ui;
}

QPushButton* AdminLoginWidget::getOkBtn()
{
    return ui->buttonBox->button(QDialogButtonBox::Ok);
}

QPushButton* AdminLoginWidget::getCancelBtn()
{
    return ui->buttonBox->button(QDialogButtonBox::Cancel);
}
