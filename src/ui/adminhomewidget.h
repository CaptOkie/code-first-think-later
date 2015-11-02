#ifndef ADMINHOMEWIDGET_H
#define ADMINHOMEWIDGET_H

#include <QWidget>

#include "projectdetailsdialog.h"
#include "../db/user.h"
#include "../db/storage.h"

namespace Ui {
    class AdminHomeWidget;
}

class AdminHomeWidget : public QWidget
{
        Q_OBJECT

    public:
        AdminHomeWidget(Storage&, User*, QWidget *parent = 0);
        ~AdminHomeWidget();

    private:
        Ui::AdminHomeWidget* ui;
        ProjectDetailsDialog detailsDialog;
        Storage& db;
        User* currUser;

    private slots:
        void loadProjects();
        void newProject();
        void editProject();
        void deleteProject();
};

#endif // ADMINHOMEWIDGET_H
