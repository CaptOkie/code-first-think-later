#include "studenthomewidget.h"
#include "ui_studenthomewidget.h"

StudentHomeWidget::StudentHomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentHomeWidget)
{
    ui->setupUi(this);
}

StudentHomeWidget::~StudentHomeWidget()
{
    delete ui;
}
