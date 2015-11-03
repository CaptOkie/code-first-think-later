#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <QDialog>

#include "../db/user.h"

namespace Ui {
    class ProfileDialog;
}

class ProfileDialog : public QDialog
{
        Q_OBJECT

    public:
        explicit ProfileDialog(const User&, QWidget* parent = 0);
        ~ProfileDialog();

    public slots:
        void showProfile();

    private:
        Ui::ProfileDialog *ui;
        const User& user;
};

#endif // PROFILEDIALOG_H
