#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
    class LoginWidget;
}

class LoginWidget : public QWidget
{
        Q_OBJECT

    private:
        Ui::LoginWidget *ui;

    private slots:
        void handleStudentBtn();
        void handleAdminBtn();

    public:
        explicit LoginWidget(QWidget *parent = 0);
        ~LoginWidget();

    signals:
        void studentSelected();
        void adminSelected();
};

#endif // LOGINWIDGET_H
