#ifndef PROJECTDETAILSDIALOG_H
#define PROJECTDETAILSDIALOG_H

#include <QDialog>

#include "../db/project.h"
#include "../db/storage.h"

namespace Ui {
    class ProjectDetailsDialog;
}

/**
 * @brief The ProjectDetailsDialog class
 *
 * The dialog for editting the project details.
 */
class ProjectDetailsDialog : public QDialog
{
        Q_OBJECT

    public:
        /**
         * @brief ProjectDetailsDialog Creates a new instance.
         * @param db The storage object.
         * @param parent The parent widget.
         */
        explicit ProjectDetailsDialog(Storage& db, QWidget *parent = 0);
        ~ProjectDetailsDialog();

    public slots:
        /**
         * @brief showProject Shows the project information.
         * @param project THe project to edit or NULL if creating a new project.
         */
        void showProject(const Project* project);

    signals:
        /**
         * @brief projectUpdated Is emitted when the project details have been saved.
         */
        void projectUpdated();

    private:
        Ui::ProjectDetailsDialog *ui; // The UI
        Storage& db;                  // The storage object
        QString* currProject;         // The name of the current project

    private slots:
        /**
         * @brief minUpdated Updates the maximum if the minimum is equal to greater than it.
         * @param value The new value of the minimum.
         */
        void minUpdated(int value);

        /**
         * @brief maxUpdated Updates the minimum if the maximum is equal to or less than it.
         * @param value The new value of the maximum.
         */
        void maxUpdated(int value);

        /**
         * @brief saveProject Saves the new/updated project details.
         */
        void saveProject();
};

#endif // PROJECTDETAILSDIALOG_H
