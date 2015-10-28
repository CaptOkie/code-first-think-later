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

    public:
        explicit LoginWidget(QWidget *parent = 0);
        ~LoginWidget();
        QMetaObject::Connection setStudentBtnHandler(const char* signal, const char* slot, const QObject* receiver);
        QMetaObject::Connection setAdminBtnHandler(const char* signal, const char* slot, const QObject* receiver);

    private:
        Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
