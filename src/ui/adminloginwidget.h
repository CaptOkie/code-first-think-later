#ifndef ADMINLOGINWIDGET_H
#define ADMINLOGINWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
    class AdminLoginWidget;
}

class AdminLoginWidget : public QWidget
{
        Q_OBJECT

    public:
        explicit AdminLoginWidget(QWidget *parent = 0);
        ~AdminLoginWidget();

    signals:
        void cancelled();
        void loggedIn();

    private:
        Ui::AdminLoginWidget *ui;

    private slots:
        void handleCancelBtn();
        void handleOkBtn();
};

#endif // ADMINLOGINWIDGET_H
