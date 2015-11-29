#ifndef STUDENTFORM_H
#define STUDENTFORM_H

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

private:
    Ui::StudentForm *ui;
};

#endif // STUDENTFORM_H
