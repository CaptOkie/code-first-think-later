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

void PErrorDialog::showDialog()
{
    exec();
}
