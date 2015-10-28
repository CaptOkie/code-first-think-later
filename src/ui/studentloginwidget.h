#ifndef STUDENTLOGINWIDGET_H
#define STUDENTLOGINWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
    class StudentLoginWidget;
}

class StudentLoginWidget : public QWidget
{
        Q_OBJECT

    public:
        explicit StudentLoginWidget(QWidget *parent = 0);
        ~StudentLoginWidget();

    signals:
        void cancelled();
        void submitted(QString& id);

    private:
        Ui::StudentLoginWidget *ui;

    private slots:
        void handleCancelBtn();
        void handleOkBtn();
};

#endif // STUDENTLOGINWIDGET_H
