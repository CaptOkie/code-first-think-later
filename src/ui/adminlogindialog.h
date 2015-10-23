#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QDialog>

namespace Ui {
    class AdminLoginDialog;
}

class AdminLoginDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit AdminLoginDialog(QWidget *parent = 0);
        ~AdminLoginDialog();

    private slots:
        void handleCancelButton();

    private:
        Ui::AdminLoginDialog *ui;
};

#endif // ADMINLOGINDIALOG_H
