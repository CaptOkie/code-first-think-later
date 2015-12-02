#ifndef STUDENTFORM_H
#define STUDENTFORM_H

#include "logoutdialog.h"

#include <QMainWindow>

namespace Ui {
class StudentForm;
}

class StudentForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentForm(QWidget *parent = 0);
    ~StudentForm();
    void setName(QString);

private:
    Ui::StudentForm *ui;
    LogoutDialog logoutDialog;

private slots:
    void logout();
};

#endif // STUDENTFORM_H
