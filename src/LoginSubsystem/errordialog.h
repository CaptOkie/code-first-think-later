#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QDialog>

namespace Ui {
    class ErrorDialog;
}

class ErrorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorDialog(QWidget *parent = 0);
    ~ErrorDialog();

private:
    Ui::ErrorDialog *ui;

private slots:
    void close();

public slots:
    void showDialog(QString);

signals:
    void closedHelp();
};



#endif // ERRORDIALOG_H
