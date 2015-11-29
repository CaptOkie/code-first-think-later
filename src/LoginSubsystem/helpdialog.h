#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
    class HelpDialog;
}

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = 0);
    ~HelpDialog();

private:
    Ui::HelpDialog *ui;

private slots:
    void close();

public slots:
    void showDialog();

signals:
    void closedHelp();
};

#endif // HELPDIALOG_H
