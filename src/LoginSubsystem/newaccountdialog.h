#ifndef NEWACCOUNTDIALOG_H
#define NEWACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class NewAccountDialog;
}

class NewAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewAccountDialog(QWidget *parent = 0);
    ~NewAccountDialog();

private:
    Ui::NewAccountDialog *ui;

private slots:
    void close();

public slots:
    void showDialog();
};

#endif // NEWACCOUNTDIALOG_H
