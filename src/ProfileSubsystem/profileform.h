#ifndef PROFILEFORM_H
#define PROFILEFORM_H

#include <QDialog>

namespace Ui {
class ProfileForm;
}

class ProfileControl;

class ProfileForm : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileForm(ProfileControl&, QWidget *parent = 0);
    ~ProfileForm();

private:
    Ui::ProfileForm *ui;
    ProfileControl& ctrl;
};

#endif // PROFILEFORM_H
