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
