#ifndef PROJECTDETAILSDIALOG_H
#define PROJECTDETAILSDIALOG_H

#include <QDialog>

namespace Ui {
    class ProjectDetailsDialog;
}

class ProjectDetailsDialog : public QDialog
{
        Q_OBJECT

    public:
        explicit ProjectDetailsDialog(QWidget *parent = 0);
        ~ProjectDetailsDialog();

    private:
        Ui::ProjectDetailsDialog *ui;
};

#endif // PROJECTDETAILSDIALOG_H
