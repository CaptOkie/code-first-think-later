#include "studentloginwidget.h"
#include "ui_studentloginwidget.h"

StudentLoginWidget::StudentLoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentLoginWidget)
{
    ui->setupUi(this);
}

StudentLoginWidget::~StudentLoginWidget()
{
    delete ui;
}

QPushButton* StudentLoginWidget::getOkBtn()
{
    return ui->buttonBox->button(QDialogButtonBox::Ok);
}

QPushButton* StudentLoginWidget::getCancelBtn()
{
    return ui->buttonBox->button(QDialogButtonBox::Cancel);
}
