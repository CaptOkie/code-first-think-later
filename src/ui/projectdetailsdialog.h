#ifndef PROJECTDETAILSDIALOG_H
#define PROJECTDETAILSDIALOG_H

#include <QDialog>

#include "../db/project.h"
#include "../db/storage.h"

namespace Ui {
    class ProjectDetailsDialog;
}

class ProjectDetailsDialog : public QDialog
{
        Q_OBJECT

    public:
        ProjectDetailsDialog(Storage&, QWidget *parent = 0);
        ~ProjectDetailsDialog();

    signals:
        void projectUpdated();

    private:
        Ui::ProjectDetailsDialog *ui;
        Storage& db;
        QString* currProject;

    public slots:
        void showProject(const Project*);

    private slots:
        void minUpdated(int value);
        void maxUpdated(int value);
        void saveProject();
};

#endif // PROJECTDETAILSDIALOG_H
