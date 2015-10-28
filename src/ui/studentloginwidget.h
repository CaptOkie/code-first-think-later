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
        QPushButton* getOkBtn();
        QPushButton* getCancelBtn();

    private:
        Ui::StudentLoginWidget *ui;
};

#endif // STUDENTLOGINWIDGET_H
