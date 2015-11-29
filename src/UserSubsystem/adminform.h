#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QMainWindow>

namespace Ui {
class AdminForm;
}

class AdminForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminForm(QWidget *parent = 0);
    ~AdminForm();

private:
    Ui::AdminForm *ui;
};

#endif // ADMINFORM_H
