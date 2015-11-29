#include "studentform.h"
#include "ui_studentform.h"

StudentForm::StudentForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentForm)
{
    ui->setupUi(this);
}

StudentForm::~StudentForm()
{
    delete ui;
}
