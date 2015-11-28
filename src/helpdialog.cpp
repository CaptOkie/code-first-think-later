#include "helpdialog.h"
#include "ui_helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &HelpDialog::close);
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

void HelpDialog::close()
{
    QDialog::reject();
}

void HelpDialog::showDialog()
{
    exec();
}
