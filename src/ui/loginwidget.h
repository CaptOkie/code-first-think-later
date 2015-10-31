#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "../db/storage.h"
#include "../enum/usertype.h"

namespace Ui {
    class LoginWidget;
}

class LoginWidget : public QWidget
{
        Q_OBJECT

    private:
        Ui::LoginWidget *ui;
        QRegExp idRegex;
        Storage& db;

    private slots:
        void handleLoginBtn();

    public:
        LoginWidget(Storage&, QWidget *parent = 0);
        ~LoginWidget();

    signals:
        void loggedIn(UserType userType);
};

#endif // LOGINWIDGET_H
