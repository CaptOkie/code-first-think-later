#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QDialog>

namespace Ui {
class adminLoginDialog;
}

class adminLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adminLoginDialog(QWidget *parent = 0);
    ~adminLoginDialog();

private:
    Ui::adminLoginDialog *ui;
};

#endif // ADMINLOGINDIALOG_H
