/********************************************************************************
** Form generated from reading UI file 'adminlogindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGINDIALOG_H
#define UI_ADMINLOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AdminLoginDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AdminLoginDialog)
    {
        if (AdminLoginDialog->objectName().isEmpty())
            AdminLoginDialog->setObjectName(QStringLiteral("AdminLoginDialog"));
        AdminLoginDialog->resize(400, 300);
        AdminLoginDialog->setStyleSheet(QLatin1String("QDialog {\n"
"	background-image: url(:/images/images/adminLoginBackground.jpg);\n"
"}"));
        horizontalLayout = new QHBoxLayout(AdminLoginDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(AdminLoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(AdminLoginDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        buttonBox = new QDialogButtonBox(AdminLoginDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(AdminLoginDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AdminLoginDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AdminLoginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AdminLoginDialog);
    } // setupUi

    void retranslateUi(QDialog *AdminLoginDialog)
    {
        AdminLoginDialog->setWindowTitle(QApplication::translate("AdminLoginDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("AdminLoginDialog", "Name", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminLoginDialog: public Ui_AdminLoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGINDIALOG_H
