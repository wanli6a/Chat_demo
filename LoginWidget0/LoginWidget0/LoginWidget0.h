#pragma once

#include <QtWidgets/QWidget>
#include "ui_LoginWidget0.h"

class LoginWidget0 : public QWidget
{
    Q_OBJECT

public:
    LoginWidget0(QWidget *parent = nullptr);
    ~LoginWidget0();

private:
    Ui::LoginWidget0Class ui;
};
