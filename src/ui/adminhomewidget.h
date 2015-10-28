#ifndef ADMINHOMEWIDGET_H
#define ADMINHOMEWIDGET_H

#include <QWidget>

namespace Ui {
    class AdminHomeWidget;
}

class AdminHomeWidget : public QWidget
{
        Q_OBJECT

    public:
        explicit AdminHomeWidget(QWidget *parent = 0);
        ~AdminHomeWidget();

    private:
        Ui::AdminHomeWidget *ui;
};

#endif // ADMINHOMEWIDGET_H
