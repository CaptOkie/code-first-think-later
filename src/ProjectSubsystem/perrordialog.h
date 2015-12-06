#ifndef PERRORDIALOG_H
#define PERRORDIALOG_H

#include <QDialog>

namespace Ui {
class PErrorDialog;
}

class PErrorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PErrorDialog(QWidget *parent = 0);
    ~PErrorDialog();

    void showDialog(QString);

private:
    Ui::PErrorDialog *ui;
    void closed();
};

#endif // PERRORDIALOG_H
