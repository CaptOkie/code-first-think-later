#ifndef PPIDFORM_H
#define PPIDFORM_H

#include <QDialog>
#include <QProgressDialog>
#include "StorageSubsystem/group.h"

namespace Ui {
    class PPIDForm;
}

class PPIDControl;

class PPIDForm : public QDialog
{
    Q_OBJECT

    public:
        explicit PPIDForm(PPIDControl& ctrl, QWidget *parent = 0);
        ~PPIDForm();

        void show(const QMap<int, Group>& groups);
        void update(const QMap<int, Group>& groups);

    private:
        PPIDControl& ctrl;
        Ui::PPIDForm* ui;
        QProgressDialog* prog;

        void load(const QMap<int, Group>& groups);

    private slots:
        void handleLaunch();
};

#endif // PPIDFORM_H
