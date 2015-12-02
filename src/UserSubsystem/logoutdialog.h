#ifndef LOGOUTDIALOG_H
#define LOGOUTDIALOG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class LogoutDialog;
}

class LogoutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogoutDialog(QWidget *parent = 0);
    ~LogoutDialog();

private:
    Ui::LogoutDialog *ui;

private slots:
    void close();
    void logout();
    void exit();

public slots:
    void showDialog();

signals:
    void closedHelp();
};

#endif // LOGOUTDIALOG_H
