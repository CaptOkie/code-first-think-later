#include "adminhomewidget.h"
#include "ui_adminhomewidget.h"

AdminHomeWidget::AdminHomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminHomeWidget)
{
    ui->setupUi(this);
}

AdminHomeWidget::~AdminHomeWidget()
{
    delete ui;
}
