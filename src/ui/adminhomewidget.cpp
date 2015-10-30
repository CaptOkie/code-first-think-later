#include "adminhomewidget.h"
#include "ui_adminhomewidget.h"

AdminHomeWidget::AdminHomeWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::AdminHomeWidget), detailsDialog(new ProjectDetailsDialog(this))
{
    ui->setupUi(this);

    connect(ui->newBtn, &QPushButton::clicked, detailsDialog, &QDialog::show);
}

AdminHomeWidget::~AdminHomeWidget()
{
    delete ui;
    delete detailsDialog;
}
