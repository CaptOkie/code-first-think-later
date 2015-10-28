#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
    class LoginWidget;
}

class LoginWidget : public QWidget
{
        Q_OBJECT

    private:
        Ui::LoginWidget *ui;

    public:
        explicit LoginWidget(QWidget *parent = 0);
        ~LoginWidget();
        QPushButton* getStudentBtn();
        QPushButton* getAdminBtn();
};

#endif // LOGINWIDGET_H
