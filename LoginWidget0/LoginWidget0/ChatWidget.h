#pragma once

#include <QWidget>
#include "ui_ChatWidget.h"
#include <QUdpSocket>

class ChatWidget : public QWidget
{
	Q_OBJECT

	enum MsgType{Msg,UsrEnter,UsrLeft};

public:
	ChatWidget(QWidget *parent,QString name);
	~ChatWidget();

private:
	Ui::ChatWidgetClass ui;

signals:
	//�رմ��ڷ��͹ر���Ϣ
	void closeWidget();

public:
	//�ر��¼�
	void closeEvent(QCloseEvent *);


public:
	void sndMsg(MsgType type);//�㲥UDP��Ϣ
	//void usrEnter(QString username);//�������û�����
	void usrLeft(QString usrname, QString time);//�����û��뿪
	QString getUsr();//��ȡ�û���
	QString getMsg();//��ȡ������Ϣ
private:
	QUdpSocket* udpSocket;
	qint16 port;//�˿�
	QString uName;//�û���

	void ReceiveMessage();//����UDP��Ϣ

};
