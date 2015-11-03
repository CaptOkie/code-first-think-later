#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <QDialog>

#include "../db/user.h"
#include "../db/storage.h"

namespace Ui {
    class ProfileDialog;
}

/**
 * @brief The ProfileDialog class
 *
 * The dialog for the student to edit their profile.
 */
class ProfileDialog : public QDialog
{
        Q_OBJECT

    public:
        /**
         * @brief ProfileDialog Creates a new instance.
         * @param user The user whose profile is to be shown.
         * @param db The storage object.
         * @param parent The parent widget.
         */
        explicit ProfileDialog(const User& user, Storage& db, QWidget* parent = 0);
        ~ProfileDialog();

    public slots:
        /**
         * @brief showProfile Loads the user data from the database and shows the profile.
         */
        void showProfile();

    private:
        Ui::ProfileDialog *ui; // The UI
        const User& user;      // The user
        Storage& db;           // The storage object
};

#endif // PROFILEDIALOG_H
