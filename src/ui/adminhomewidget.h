#ifndef ADMINHOMEWIDGET_H
#define ADMINHOMEWIDGET_H

#include <QWidget>

#include "projectdetailsdialog.h"
#include "../db/user.h"
#include "../db/storage.h"

namespace Ui {
    class AdminHomeWidget;
}

/**
 * @brief The AdminHomeWidget class
 *
 * The widget for the administrator's home screen.
 */
class AdminHomeWidget : public QWidget
{
        Q_OBJECT

    public:
        /**
         * @brief AdminHomeWidget Creates a new instance, which claims ownership of, and responsibility for deleting, currUser.
         * @param db The storage object.
         * @param currUser The current user.
         * @param parent The parent widget.
         */
        AdminHomeWidget(Storage& db, User* currUser, QWidget *parent = 0);
        ~AdminHomeWidget();

    private:
        Ui::AdminHomeWidget* ui;            // The UI
        ProjectDetailsDialog detailsDialog; // The details dialog used to edit/create projects
        Storage& db;                        // The storage object
        User* currUser;                     // The current user

    private slots:
        /**
         * @brief loadProjects Loads the list of projects from the storage.
         */
        void loadProjects();

        /**
         * @brief newProject Shows the details dialog when the new button is clicked.
         */
        void newProject();

        /**
         * @brief editProject Shows the selected project in the details dialog when the edit button is clicked.
         */
        void editProject();

        /**
         * @brief deleteProject Deletes the selected project.
         */
        void deleteProject();
};

#endif // ADMINHOMEWIDGET_H
