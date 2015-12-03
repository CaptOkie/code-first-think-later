#ifndef PROJECTFORM_H
#define PROJECTFORM_H

#include <QDialog>

namespace Ui {
class ProjectForm;
}

class ProjectControl;

class ProjectForm : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectForm(ProjectControl&, QWidget *parent = 0);
    ~ProjectForm();

    void close();
    void showDialog();
    void setName(QString);
    void setValue(QString, int);

private:
    Ui::ProjectForm *ui;
    ProjectControl& ctrl;
};

#endif // PROJECTFORM_H
