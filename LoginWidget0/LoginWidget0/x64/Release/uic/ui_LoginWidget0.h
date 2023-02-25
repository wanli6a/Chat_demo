/********************************************************************************
** Form generated from reading UI file 'LoginWidget0.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET0_H
#define UI_LOGINWIDGET0_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget0Class
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *accountEdit;
    QLineEdit *passwordEdit;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *regButton;

    void setupUi(QWidget *LoginWidget0Class)
    {
        if (LoginWidget0Class->objectName().isEmpty())
            LoginWidget0Class->setObjectName(QString::fromUtf8("LoginWidget0Class"));
        LoginWidget0Class->resize(200, 146);
        widget = new QWidget(LoginWidget0Class);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 197, 142));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        accountEdit = new QLineEdit(widget);
        accountEdit->setObjectName(QString::fromUtf8("accountEdit"));

        verticalLayout->addWidget(accountEdit);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));

        verticalLayout->addWidget(passwordEdit);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        horizontalLayout->addWidget(loginButton);

        regButton = new QPushButton(widget);
        regButton->setObjectName(QString::fromUtf8("regButton"));
        regButton->setFlat(true);

        horizontalLayout->addWidget(regButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LoginWidget0Class);

        QMetaObject::connectSlotsByName(LoginWidget0Class);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget0Class)
    {
        LoginWidget0Class->setWindowTitle(QApplication::translate("LoginWidget0Class", "LoginWidget0", nullptr));
        label->setText(QApplication::translate("LoginWidget0Class", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        accountEdit->setPlaceholderText(QApplication::translate("LoginWidget0Class", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        passwordEdit->setPlaceholderText(QApplication::translate("LoginWidget0Class", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        checkBox->setText(QApplication::translate("LoginWidget0Class", "\350\256\260\344\275\217\350\264\246\345\217\267", nullptr));
        loginButton->setText(QApplication::translate("LoginWidget0Class", "\347\231\273\345\275\225", nullptr));
        regButton->setText(QApplication::translate("LoginWidget0Class", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget0Class: public Ui_LoginWidget0Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET0_H
