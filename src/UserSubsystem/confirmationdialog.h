#ifndef CONFIRMATIONDIALOG_H
#define CONFIRMATIONDIALOG_H

#include <QDialog>

namespace Ui {
class ConfirmationDialog;
}

class ConfirmationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmationDialog(QWidget *parent = 0);
    ~ConfirmationDialog();

    void showDialog(QString);

private:
    Ui::ConfirmationDialog *ui;
    void confirm();
    void cancel();
};

#endif // CONFIRMATIONDIALOG_H
