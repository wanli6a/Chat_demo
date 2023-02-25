#include "LoginWidget0.h"
#include <QSqlQuery>
#include <QSqlError>
#include <qDebug>
#include <QMessageBox>
#include <QSettings>
#include "userWidget.h"
#pragma execution_character_set("utf-8")

LoginWidget0::LoginWidget0(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //从配置文件中读取用户名和密码
    QSettings setting("config.ini", QSettings::IniFormat);
    QString account = setting.value("section/account").toString();
    QString password = setting.value("section/password").toString();
    ui.accountEdit->setText(account);
    ui.passwordEdit->setText(password);



    //用户注册
    connect(ui.regButton, &QPushButton::clicked, this, [=]() {
        //接收用户输入
        QString account = ui.accountEdit->text();//账号和密码
        QString password = ui.passwordEdit->text();
        
        //插入数据
        QSqlQuery query;//操作数据库
        QString qs = QString("insert into users(account,password) values('%1','%2')").arg(account).arg(password);
        if (query.exec(qs) ){//如果插入成功
            QMessageBox::information(this, "注册", "注册成功");
        }
        else {
            QMessageBox::information(this, "注册", "注册失败");
            qDebug() << query.lastError().text();//输出错误信息
            return;
        }
        
        });
    //用户登录
        connect(ui.loginButton, &QPushButton::clicked, this, [=]() {

            QString account = ui.accountEdit->text();//获取账号和密码
            QString password = ui.passwordEdit->text();

            QSqlQuery query;
            QString qs = QString("select * from users where account = '%1' and password = '%2'").arg(account).arg(password);
            if (!query.exec(qs)) {//如果没有查到记录
                qDebug() << query.lastError().text();//输出错误信息
                return;
            }
            if(query.next()){
                QMessageBox::information(this, "登录", "登录成功");

                //跳转窗口：
                this->hide();//隐藏主窗口
                userWidget* uw = new userWidget();
                uw->show();

                //在配置文件中记录用户账号密码
                if(ui.checkBox->isChecked()){//选中
                    QSettings setting("config.ini",QSettings::IniFormat);
                    //将用户账号密码写到配置文件中
                    setting.beginGroup("section");//节开始
                    setting.setValue("account",account);
                    setting.setValue("password", password);
                    setting.endGroup();//结束

                }
            }
            else {
                QMessageBox::information(this, "登录", "登录失败");
            }           
            });
        
        


}

LoginWidget0::~LoginWidget0()
{}
