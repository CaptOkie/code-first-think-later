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

void PPIDForm::show(const QMap<int, Group*>& groups)
{
    load(groups);
    QDialog::exec();
}

void PPIDForm::update(const QMap<int, Group*>& groups)
{
    load(groups);
    prog->reset();
}

void PPIDForm::load(const QMap<int, Group*>& groups)
{
    qDeleteAll(ui->scrollAreaWidgetContents->children());
    QLayout* layout = ui->scrollAreaWidgetContents->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
        ui->scrollAreaWidgetContents->setLayout(layout);
    }

    QMap<int, Group*>::const_iterator it;
    for (it = groups.constBegin(); it != groups.constEnd(); ++it) {
        layout->addWidget(new GroupWidget(**it, this));
    }
}

void PPIDForm::handleLaunch()
{
    if (prog == NULL) {
        prog = new QProgressDialog("Creating groups...", "Cancel", 0, 0, this);
        prog->setWindowTitle("Progress");
        prog->setCancelButton(NULL);
        prog->setWindowModality(Qt::WindowModal);
        prog->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    }
    prog->show();
    ctrl.group();
}
