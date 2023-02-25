/********************************************************************************
** Form generated from reading UI file 'ChatWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidgetClass
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *msgBrowser;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontCbx;
    QComboBox *sizeCbx;
    QToolButton *boldTBtn;
    QToolButton *italicTBtn;
    QToolButton *underlineTBtn;
    QToolButton *colorTBtn;
    QToolButton *saveTBtn;
    QToolButton *clearTBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *msgTxtEdit;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sendBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitBtn;

    void setupUi(QWidget *ChatWidgetClass)
    {
        if (ChatWidgetClass->objectName().isEmpty())
            ChatWidgetClass->setObjectName(QString::fromUtf8("ChatWidgetClass"));
        ChatWidgetClass->resize(730, 450);
        verticalLayout_5 = new QVBoxLayout(ChatWidgetClass);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_6 = new QWidget(ChatWidgetClass);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(widget_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(frame_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        msgBrowser = new QTextBrowser(widget);
        msgBrowser->setObjectName(QString::fromUtf8("msgBrowser"));

        verticalLayout->addWidget(msgBrowser);


        verticalLayout_2->addWidget(widget);

        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        fontCbx = new QFontComboBox(frame_2);
        fontCbx->setObjectName(QString::fromUtf8("fontCbx"));

        horizontalLayout->addWidget(fontCbx);

        sizeCbx = new QComboBox(frame_2);
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->setObjectName(QString::fromUtf8("sizeCbx"));

        horizontalLayout->addWidget(sizeCbx);

        boldTBtn = new QToolButton(frame_2);
        boldTBtn->setObjectName(QString::fromUtf8("boldTBtn"));
        boldTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/qingxie.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        boldTBtn->setIcon(icon);
        boldTBtn->setIconSize(QSize(26, 26));
        boldTBtn->setCheckable(true);

        horizontalLayout->addWidget(boldTBtn);

        italicTBtn = new QToolButton(frame_2);
        italicTBtn->setObjectName(QString::fromUtf8("italicTBtn"));
        italicTBtn->setMinimumSize(QSize(33, 33));
        italicTBtn->setIcon(icon);
        italicTBtn->setIconSize(QSize(26, 26));
        italicTBtn->setCheckable(true);

        horizontalLayout->addWidget(italicTBtn);

        underlineTBtn = new QToolButton(frame_2);
        underlineTBtn->setObjectName(QString::fromUtf8("underlineTBtn"));
        underlineTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/underline.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        underlineTBtn->setIcon(icon1);
        underlineTBtn->setIconSize(QSize(26, 26));
        underlineTBtn->setCheckable(true);

        horizontalLayout->addWidget(underlineTBtn);

        colorTBtn = new QToolButton(frame_2);
        colorTBtn->setObjectName(QString::fromUtf8("colorTBtn"));
        colorTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/color.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        colorTBtn->setIcon(icon2);
        colorTBtn->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(colorTBtn);

        saveTBtn = new QToolButton(frame_2);
        saveTBtn->setObjectName(QString::fromUtf8("saveTBtn"));
        saveTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/save.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        saveTBtn->setIcon(icon3);
        saveTBtn->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(saveTBtn);

        clearTBtn = new QToolButton(frame_2);
        clearTBtn->setObjectName(QString::fromUtf8("clearTBtn"));
        clearTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/clear.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        clearTBtn->setIcon(icon4);
        clearTBtn->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(clearTBtn);


        verticalLayout_2->addWidget(frame_2);

        widget_2 = new QWidget(frame_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        msgTxtEdit = new QTextEdit(widget_2);
        msgTxtEdit->setObjectName(QString::fromUtf8("msgTxtEdit"));

        horizontalLayout_2->addWidget(msgTxtEdit);


        verticalLayout_2->addWidget(widget_2);


        horizontalLayout_3->addWidget(frame_3);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(180, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_3->addWidget(widget_3);


        verticalLayout_4->addWidget(widget_4);

        frame_5 = new QFrame(widget_6);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::Box);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        sendBtn = new QPushButton(frame_5);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout_4->addWidget(sendBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        exitBtn = new QPushButton(frame_5);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        horizontalLayout_4->addWidget(exitBtn);


        verticalLayout_4->addWidget(frame_5);


        verticalLayout_5->addWidget(widget_6);


        retranslateUi(ChatWidgetClass);

        sizeCbx->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(ChatWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ChatWidgetClass)
    {
        ChatWidgetClass->setWindowTitle(QApplication::translate("ChatWidgetClass", "ChatWidget", nullptr));
        sizeCbx->setItemText(0, QApplication::translate("ChatWidgetClass", "8", nullptr));
        sizeCbx->setItemText(1, QApplication::translate("ChatWidgetClass", "9", nullptr));
        sizeCbx->setItemText(2, QApplication::translate("ChatWidgetClass", "10", nullptr));
        sizeCbx->setItemText(3, QApplication::translate("ChatWidgetClass", "11", nullptr));
        sizeCbx->setItemText(4, QApplication::translate("ChatWidgetClass", "12", nullptr));
        sizeCbx->setItemText(5, QApplication::translate("ChatWidgetClass", "13", nullptr));
        sizeCbx->setItemText(6, QApplication::translate("ChatWidgetClass", "14", nullptr));
        sizeCbx->setItemText(7, QApplication::translate("ChatWidgetClass", "15", nullptr));
        sizeCbx->setItemText(8, QApplication::translate("ChatWidgetClass", "16", nullptr));
        sizeCbx->setItemText(9, QApplication::translate("ChatWidgetClass", "17", nullptr));
        sizeCbx->setItemText(10, QApplication::translate("ChatWidgetClass", "18", nullptr));
        sizeCbx->setItemText(11, QApplication::translate("ChatWidgetClass", "19", nullptr));
        sizeCbx->setItemText(12, QApplication::translate("ChatWidgetClass", "20", nullptr));
        sizeCbx->setItemText(13, QApplication::translate("ChatWidgetClass", "21", nullptr));
        sizeCbx->setItemText(14, QApplication::translate("ChatWidgetClass", "22", nullptr));

#ifndef QT_NO_TOOLTIP
        boldTBtn->setToolTip(QApplication::translate("ChatWidgetClass", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        boldTBtn->setText(QApplication::translate("ChatWidgetClass", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        italicTBtn->setToolTip(QApplication::translate("ChatWidgetClass", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        italicTBtn->setText(QApplication::translate("ChatWidgetClass", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        underlineTBtn->setToolTip(QApplication::translate("ChatWidgetClass", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        underlineTBtn->setText(QApplication::translate("ChatWidgetClass", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        colorTBtn->setToolTip(QApplication::translate("ChatWidgetClass", "\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        colorTBtn->setText(QApplication::translate("ChatWidgetClass", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        saveTBtn->setToolTip(QApplication::translate("ChatWidgetClass", "\344\277\235\345\255\230\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        saveTBtn->setText(QApplication::translate("ChatWidgetClass", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        clearTBtn->setToolTip(QApplication::translate("ChatWidgetClass", "\346\270\205\351\231\244\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        clearTBtn->setText(QApplication::translate("ChatWidgetClass", "...", nullptr));
        sendBtn->setText(QApplication::translate("ChatWidgetClass", "\345\217\221\351\200\201", nullptr));
        exitBtn->setText(QApplication::translate("ChatWidgetClass", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWidgetClass: public Ui_ChatWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
