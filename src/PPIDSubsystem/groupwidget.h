#ifndef GROUPWIDGET_H
#define GROUPWIDGET_H

#include <QGroupBox>

#include "StorageSubsystem/group.h"

class GroupWidget : public QGroupBox
{
    Q_OBJECT

    public:
        explicit GroupWidget(const Group& group, QWidget *parent = 0);
        ~GroupWidget();
};

#endif // GROUPWIDGET_H
