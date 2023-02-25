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
	//关闭窗口发送关闭消息
	void closeWidget();

public:
	//关闭事件
	void closeEvent(QCloseEvent *);


public:
	void sndMsg(MsgType type);//广播UDP消息
	//void usrEnter(QString username);//处理新用户加入
	void usrLeft(QString usrname, QString time);//处理用户离开
	QString getUsr();//获取用户名
	QString getMsg();//获取聊天信息
private:
	QUdpSocket* udpSocket;
	qint16 port;//端口
	QString uName;//用户名

	void ReceiveMessage();//接收UDP消息

};
