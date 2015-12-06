#include "perrordialog.h"
#include "ui_perrordialog.h"

PErrorDialog::PErrorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PErrorDialog)
{
    ui->setupUi(this);

    connect(ui->whoopsButton, &QPushButton::released, this, &PErrorDialog::closed);
}

PErrorDialog::~PErrorDialog()
{
    delete ui;
}

void PErrorDialog::closed()
{
    QDialog::accept();
}

void PErrorDialog::showDialog(QString type)
{
    if (type == "name"){
        ui->descLabel->setText("Please enter a value for the Project name.");
        ui->label->setText("Empty Name Error");
    }
    else {
        ui->descLabel->setText("Please ensure that the Min and Max Group Sizes are both greater than 0 and off by a value of 1 or greater. Furthermore, please ensure that the Min is also less than the Max.");
        ui->label->setText("Group Size Error");
    }
    exec();
}
