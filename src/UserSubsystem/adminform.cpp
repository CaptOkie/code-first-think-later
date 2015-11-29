#include "adminform.h"
#include "ui_adminform.h"

AdminForm::AdminForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminForm)
{
    ui->setupUi(this);
}

AdminForm::~AdminForm()
{
    delete ui;
}
