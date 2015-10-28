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
        void submitted(QString& id);

    public slots:
        void handleCancelBtn();
        void handleOkBtn();

    private:
        Ui::AdminLoginWidget *ui;
};

#endif // ADMINLOGINWIDGET_H
