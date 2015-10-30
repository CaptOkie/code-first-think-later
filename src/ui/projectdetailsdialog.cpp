#include "projectdetailsdialog.h"
#include "ui_projectdetailsdialog.h"

ProjectDetailsDialog::ProjectDetailsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectDetailsDialog)
{
    ui->setupUi(this);
}

ProjectDetailsDialog::~ProjectDetailsDialog()
{
    delete ui;
}
