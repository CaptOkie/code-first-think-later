#ifndef ADMINLOGINWIDGET_H
#define ADMINLOGINWIDGET_H

#include <QWidget>

namespace Ui {
    class AdminLoginWidget;
}

class AdminLoginWidget : public QWidget
{
        Q_OBJECT

    public:
        explicit AdminLoginWidget(QWidget *parent = 0);
        ~AdminLoginWidget();

    private:
        Ui::AdminLoginWidget *ui;
};

#endif // ADMINLOGINWIDGET_H
