#include "ppidform.h"
#include "ui_ppidform.h"

#include <QVBoxLayout>
#include "groupwidget.h"
#include "ppidcontrol.h"

PPIDForm::PPIDForm(PPIDControl& ctrl, QWidget *parent)
    : QDialog(parent), ctrl(ctrl), ui(new Ui::PPIDForm), prog(NULL)
{
    ui->setupUi(this);

    connect(ui->launchBtn, &QPushButton::clicked, this, &PPIDForm::handleLaunch);
}

PPIDForm::~PPIDForm()
{
    delete ui;
    if (prog) {
        delete prog;
    }
}

void PPIDForm::show(const QMap<int, Group>& groups)
{
    load(groups);
    QDialog::show();
}

void PPIDForm::update(const QMap<int, Group>& groups)
{
    load(groups);
    prog->reset();
}

void PPIDForm::load(const QMap<int, Group>& groups)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QMap<int, Group>::const_iterator it;
    for (it = groups.constBegin(); it != groups.constEnd(); ++it) {
        layout->addWidget(new GroupWidget(*it, this));
    }
    setLayout(layout);
}

void PPIDForm::handleLaunch()
{
    if (prog == NULL) {
        prog = new QProgressDialog("Creating groups...", "Cancel", 0, 0, this);
        prog->setCancelButton(NULL);
        prog->setWindowModality(Qt::WindowModal);
    }
    prog->show();
    ctrl.group();
}
