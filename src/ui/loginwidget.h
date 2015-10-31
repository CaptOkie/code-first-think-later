#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "../db/storage.h"
#include "../db/user.h"

namespace Ui {
    class LoginWidget;
}

class LoginWidget : public QWidget
{
        Q_OBJECT

    private:
        Ui::LoginWidget *ui;
        Storage& db;

    private slots:
        void handleLoginBtn();

    public:
        LoginWidget(Storage&, QWidget *parent = 0);
        ~LoginWidget();

    signals:
        void loggedIn(User* user);
};

#endif // LOGINWIDGET_H
