#ifndef PROFILEFORM_H
#define PROFILEFORM_H

#include <QDialog>

namespace Ui {
class ProfileForm;
}

class ProfileForm : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileForm(QWidget *parent = 0);
    ~ProfileForm();

private:
    Ui::ProfileForm *ui;
};

#endif // PROFILEFORM_H
