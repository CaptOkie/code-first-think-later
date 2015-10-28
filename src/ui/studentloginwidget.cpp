#include "studentloginwidget.h"
#include "ui_studentloginwidget.h"

StudentLoginWidget::StudentLoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentLoginWidget)
{
    ui->setupUi(this);

    connect(ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this, &StudentLoginWidget::handleOkBtn);
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::clicked, this, &StudentLoginWidget::handleCancelBtn);
}

StudentLoginWidget::~StudentLoginWidget()
{
    delete ui;
}

void StudentLoginWidget::handleOkBtn()
{
    QString id = ui->studentInput->text();
    emit submitted(id);
}

void StudentLoginWidget::handleCancelBtn()
{
    emit cancelled();
}
