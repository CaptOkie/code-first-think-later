#include "projectdetailsdialog.h"
#include "ui_projectdetailsdialog.h"

ProjectDetailsDialog::ProjectDetailsDialog(Storage& db, QWidget *parent)
    : QDialog(parent), ui(new Ui::ProjectDetailsDialog), db(db), currProject(NULL)
{
    ui->setupUi(this);

    connect(ui->minGroupSizeInput, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &ProjectDetailsDialog::minUpdated);
    connect(ui->maxGroupSizeInput, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &ProjectDetailsDialog::maxUpdated);

    connect(this, &ProjectDetailsDialog::accepted, this, &ProjectDetailsDialog::saveProject);
}

ProjectDetailsDialog::~ProjectDetailsDialog()
{
    delete ui;
    if (currProject != NULL) {
        delete currProject;
    }
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

void ProjectDetailsDialog::saveProject()
{
    QString name = ui->projectNameInput->text();
    GroupSize groupSize(ui->minGroupSizeInput->value(), ui->maxGroupSizeInput->value());
    Project project(name, groupSize);

    if (currProject == NULL) {
        db.addProject(project);
    }
    else {
        db.updateProject(project, *currProject);
    }
    emit projectUpdated();
}

void ProjectDetailsDialog::showProject(const Project* project)
{
    if (currProject != NULL) {
        delete currProject;
        currProject = NULL;
    }

    if (project != NULL) {
        currProject = new QString(project->getName());
        ui->projectNameInput->setText(project->getName());
        ui->minGroupSizeInput->setValue(project->getGroupSize().getMin());
        ui->maxGroupSizeInput->setValue(project->getGroupSize().getMax());
    }
    else {
        ui->projectNameInput->setText("");
        ui->minGroupSizeInput->setValue(1);
        ui->maxGroupSizeInput->setValue(2);
    }
    show();
}
