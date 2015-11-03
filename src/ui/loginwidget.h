#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "../db/storage.h"
#include "../db/user.h"

namespace Ui {
    class LoginWidget;
}

/**
 * @brief The LoginWidget class
 *
 * The widget for users to login.
 */
class LoginWidget : public QWidget
{
        Q_OBJECT

    public:
        /**
         * @brief LoginWidget Creates a new instance.
         * @param db The storage object.
         * @param parent The parent widget.
         */
        explicit LoginWidget(Storage& db, QWidget *parent = 0);
        ~LoginWidget();

    signals:
        /**
         * @brief loggedIn Emits the signal when a user successfully logs in.
         * @param user The user that logged in.
         */
        void loggedIn(User* user);

    private:
        Ui::LoginWidget *ui; // The UI
        Storage& db;         // The storage object

    private slots:
        /**
         * @brief attemptLogin Attempts a login when the login button is clicked.
         */
        void attemptLogin();
};

#endif // LOGINWIDGET_H
