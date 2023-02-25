/********************************************************************************
** Form generated from reading UI file 'userWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *vLayout;

    void setupUi(QWidget *userWidgetClass)
    {
        if (userWidgetClass->objectName().isEmpty())
            userWidgetClass->setObjectName(QString::fromUtf8("userWidgetClass"));
        userWidgetClass->resize(300, 800);
        verticalLayout = new QVBoxLayout(userWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(userWidgetClass);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 300, 770));
        vLayout = new QVBoxLayout(page);
        vLayout->setSpacing(6);
        vLayout->setContentsMargins(11, 11, 11, 11);
        vLayout->setObjectName(QString::fromUtf8("vLayout"));
        vLayout->setContentsMargins(0, 0, 0, 0);
        toolBox->addItem(page, QString::fromUtf8("\347\276\244\346\210\220\345\221\230"));

        verticalLayout->addWidget(toolBox);


        retranslateUi(userWidgetClass);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(userWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *userWidgetClass)
    {
        userWidgetClass->setWindowTitle(QApplication::translate("userWidgetClass", "userWidget", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("userWidgetClass", "\347\276\244\346\210\220\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userWidgetClass: public Ui_userWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
