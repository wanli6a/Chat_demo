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

    //�������ļ��ж�ȡ�û���������
    QSettings setting("config.ini", QSettings::IniFormat);
    QString account = setting.value("section/account").toString();
    QString password = setting.value("section/password").toString();
    ui.accountEdit->setText(account);
    ui.passwordEdit->setText(password);



    //�û�ע��
    connect(ui.regButton, &QPushButton::clicked, this, [=]() {
        //�����û�����
        QString account = ui.accountEdit->text();//�˺ź�����
        QString password = ui.passwordEdit->text();
        
        //��������
        QSqlQuery query;//�������ݿ�
        QString qs = QString("insert into users(account,password) values('%1','%2')").arg(account).arg(password);
        if (query.exec(qs) ){//�������ɹ�
            QMessageBox::information(this, "ע��", "ע��ɹ�");
        }
        else {
            QMessageBox::information(this, "ע��", "ע��ʧ��");
            qDebug() << query.lastError().text();//���������Ϣ
            return;
        }
        
        });
    //�û���¼
        connect(ui.loginButton, &QPushButton::clicked, this, [=]() {

            QString account = ui.accountEdit->text();//��ȡ�˺ź�����
            QString password = ui.passwordEdit->text();

            QSqlQuery query;
            QString qs = QString("select * from users where account = '%1' and password = '%2'").arg(account).arg(password);
            if (!query.exec(qs)) {//���û�в鵽��¼
                qDebug() << query.lastError().text();//���������Ϣ
                return;
            }
            if(query.next()){
                QMessageBox::information(this, "��¼", "��¼�ɹ�");

                //��ת���ڣ�
                this->hide();//����������
                userWidget* uw = new userWidget();
                uw->show();

                //�������ļ��м�¼�û��˺�����
                if(ui.checkBox->isChecked()){//ѡ��
                    QSettings setting("config.ini",QSettings::IniFormat);
                    //���û��˺�����д�������ļ���
                    setting.beginGroup("section");//�ڿ�ʼ
                    setting.setValue("account",account);
                    setting.setValue("password", password);
                    setting.endGroup();//����

                }
            }
            else {
                QMessageBox::information(this, "��¼", "��¼ʧ��");
            }           
            });
        
        


}

LoginWidget0::~LoginWidget0()
{}
