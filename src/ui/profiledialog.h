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
        explicit ProfileDialog(QWidget* parent = 0);
        ~ProfileDialog();

    public slots:
        void showProfile(const User&);

    private:
        Ui::ProfileDialog *ui;
};

#endif // PROFILEDIALOG_H
