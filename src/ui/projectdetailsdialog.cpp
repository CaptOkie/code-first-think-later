#include "projectdetailsdialog.h"
#include "ui_projectdetailsdialog.h"

ProjectDetailsDialog::ProjectDetailsDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::ProjectDetailsDialog)
{
    ui->setupUi(this);

    connect(ui->minGroupSizeInput, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &ProjectDetailsDialog::minUpdated);
    connect(ui->maxGroupSizeInput, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &ProjectDetailsDialog::maxUpdated);
}

ProjectDetailsDialog::~ProjectDetailsDialog()
{
    delete ui;
}

void ProjectDetailsDialog::minUpdated(int value)
{
    if (ui->maxGroupSizeInput->value() <= value) {
        ui->maxGroupSizeInput->setValue(value + 1);
    }
}

void ProjectDetailsDialog::maxUpdated(int value)
{
    if (ui->minGroupSizeInput->value() >= value) {
        ui->minGroupSizeInput->setValue(value - 1);
    }
}
