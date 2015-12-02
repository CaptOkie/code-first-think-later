#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QMainWindow>
#include "ProjectSubsystem/projectform.h"

namespace Ui {
class AdminForm;
}

class AdminForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminForm(QWidget *parent = 0);
    ~AdminForm();

    void editProject();
    void setName(QString);

private:
    Ui::AdminForm *ui;
    ProjectForm projectForm;
};

#endif // ADMINFORM_H
