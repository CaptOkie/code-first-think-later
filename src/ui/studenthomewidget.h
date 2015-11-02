#ifndef STUDENTHOMEWIDGET_H
#define STUDENTHOMEWIDGET_H

#include <QWidget>

#include "profiledialog.h"
#include "../db/storage.h"
#include "../db/user.h"

namespace Ui {
    class StudentHomeWidget;
}

class StudentHomeWidget : public QWidget
{
        Q_OBJECT

    public:
        StudentHomeWidget(Storage&, User*, QWidget *parent = 0);
        ~StudentHomeWidget();

    private:
        void loadProjects();

        Ui::StudentHomeWidget *ui;
        Storage& db;
        User* currUser;
        ProfileDialog profileDialog;

    private slots:
        void joinProject();
        void leaveProject();
        void showProfile();
};

#endif // STUDENTHOMEWIDGET_H
