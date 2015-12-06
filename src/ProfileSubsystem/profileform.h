#ifndef PROFILEFORM_H
#define PROFILEFORM_H

#include <QDialog>
#include "StorageSubsystem/student.h"
#include "questionwidget.h"

namespace Ui {
class ProfileForm;
}

class ProfileControl;

class ProfileForm : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileForm(ProfileControl& ctrl, const Student& student, QWidget *parent = 0);
    ~ProfileForm();
    void show(const QMap<int, Question*>& questions);

private:
    Ui::ProfileForm *ui;
    ProfileControl& ctrl;
    QHash<int, QuestionWidget*> data;
};

#endif // PROFILEFORM_H
