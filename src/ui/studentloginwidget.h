#ifndef STUDENTLOGINWIDGET_H
#define STUDENTLOGINWIDGET_H

#include <QWidget>

namespace Ui {
    class StudentLoginWidget;
}

class StudentLoginWidget : public QWidget
{
        Q_OBJECT

    public:
        explicit StudentLoginWidget(QWidget *parent = 0);
        ~StudentLoginWidget();

    private:
        Ui::StudentLoginWidget *ui;
};

#endif // STUDENTLOGINWIDGET_H
