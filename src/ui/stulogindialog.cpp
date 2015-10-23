#include "stulogindialog.h"
#include "ui_stulogindialog.h"
#include "errordialog.h"

StuLoginDialog::StuLoginDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::StuLoginDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(handleCancelButton()));
}

StuLoginDialog::~StuLoginDialog()
{
    delete ui;
}

void StuLoginDialog::handleCancelButton()
{
    QDialog* errorDialog = new ErrorDialog(parentWidget());
    errorDialog->show();
}
