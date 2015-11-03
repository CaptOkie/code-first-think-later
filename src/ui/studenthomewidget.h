#ifndef STUDENTHOMEWIDGET_H
#define STUDENTHOMEWIDGET_H

#include <QWidget>

#include "profiledialog.h"
#include "../db/storage.h"
#include "../db/user.h"

namespace Ui {
    class StudentHomeWidget;
}

/**
 * @brief The StudentHomeWidget class
 *
 * The widget for the student home screen.
 */
class StudentHomeWidget : public QWidget
{
        Q_OBJECT

    public:
        /**
         * @brief StudentHomeWidget Creates a new instance, which claims ownership of, and responsibility for deleting, currUser.
         * @param db The storage object.
         * @param currUser The current user.
         * @param parent The parent widget.
         */
        StudentHomeWidget(Storage& db, User* currUser, QWidget *parent = 0);
        ~StudentHomeWidget();

    private:
        Ui::StudentHomeWidget *ui;   // The UI
        Storage& db;                 // The storage object
        User* currUser;              // The current user
        ProfileDialog profileDialog; // The profile dialog

        /**
         * @brief loadProjects Loads the projects.
         */
        void loadProjects();

    private slots:
        /**
         * @brief joinProject Places the student in the selected project.
         */
        void joinProject();

        /**
         * @brief leaveProject Removes the student from the selected project.
         */
        void leaveProject();
};

#endif // STUDENTHOMEWIDGET_H
