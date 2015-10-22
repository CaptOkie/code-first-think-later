#ifndef STULOGINDIALOG_H
#define STULOGINDIALOG_H

#include <QDialog>

namespace Ui {
class StuLoginDialog;
}

class StuLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StuLoginDialog(QWidget *parent = 0);
    ~StuLoginDialog();

private:
    Ui::StuLoginDialog *ui;
};

#endif // STULOGINDIALOG_H
