#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "../enum/usertype.h"

namespace Ui {
    class LoginWidget;
}

class LoginWidget : public QWidget
{
        Q_OBJECT

    private:
        Ui::LoginWidget *ui;

    private slots:
        void handleLoginBtn();

    public:
        explicit LoginWidget(QWidget *parent = 0);
        ~LoginWidget();

    signals:
        void loggedIn(UserType userType);
};

#endif // LOGINWIDGET_H
