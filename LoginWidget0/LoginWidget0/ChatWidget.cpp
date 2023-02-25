#include "ChatWidget.h"
#include <QMessageBox>
#include <QDateTime>
#include <QColorDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#pragma execution_character_set("utf-8")

ChatWidget::ChatWidget(QWidget *parent,QString name)
	: QWidget(parent)
{
	ui.setupUi(this);

	//初始化操作
	udpSocket = new QUdpSocket(this);
	//用户名获取
	uName = name;
	//端口号
	this->port = 9999;

	//绑定端口号   绑定模式  共享地址  断线重连
	udpSocket->bind(this->port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

	//发送新用户进入
	//sndMsg(UsrEnter);

	//点击发送按钮发送消息
	connect(ui.sendBtn, &QPushButton::clicked, [=]() {
		sndMsg(Msg);
		});

	//监听别人发送的数据
	connect(udpSocket, &QUdpSocket::readyRead, this, &ChatWidget::ReceiveMessage);

	/////////字体设置等功能
	//1.字体
	connect(ui.fontCbx, &QFontComboBox::currentFontChanged, [=](const QFont &font) {
		ui.msgTxtEdit->setCurrentFont(font);
		ui.msgTxtEdit->setFocus();
		});
	//2.字号
	void(QComboBox:: * cbxsingal)(const QString & text) = &QComboBox::currentIndexChanged;
	connect(ui.sizeCbx, cbxsingal, [=](const QString &text) {
		ui.msgTxtEdit->setFontPointSize(text.toDouble());
		ui.msgTxtEdit->setFocus();
				});
	//3.加粗
	connect(ui.boldTBtn, &QToolButton::clicked, [=](bool isChecked) {
		if (isChecked) {
			ui.msgTxtEdit->setFontWeight(QFont::Bold);

		}
		else {
			ui.msgTxtEdit->setFontWeight(QFont::Normal);
		}
		});
	//4.倾斜
	connect(ui.italicTBtn, &QToolButton::clicked, [=](bool check) {
		ui.msgTxtEdit->setFontItalic(check);
		});
	//5.下划线
	connect(ui.underlineTBtn, &QToolButton::clicked, [=](bool check) {
		ui.msgTxtEdit->setFontUnderline(check);
		});
	//6.字体颜色
	connect(ui.colorTBtn, &QToolButton::clicked, [=]() {
		QColor color = QColorDialog::getColor(Qt::red);
		ui.msgTxtEdit->setTextColor(color);
		});
	//7.清空聊天记录
	connect(ui.clearTBtn, &QToolButton::clicked, [=]() {
		ui.msgBrowser->clear();
		});
	//8.保存聊天记录
	connect(ui.saveTBtn, &QToolButton::clicked, [=]() {
		if (ui.msgBrowser->document()->isEmpty()) {

			QMessageBox::warning(this, "提示", "路径或内容不可为空");
			return;

		}
		else {
			QString path = QFileDialog::getSaveFileName(this, "保存记录", "聊天记录", "(*.txt)");
			QFile file(path);
			//打开模式加上换行操作
			file.open(QIODevice::WriteOnly | QIODevice::Text);
			QTextStream stream(&file);
			stream << ui.msgBrowser->toPlainText();
			file.close();
		}

		
		
		
		});

}

void ChatWidget::ReceiveMessage() {
	//拿到数据报文
	//获取长度
	qint64 size = udpSocket->pendingDatagramSize();
	QByteArray array = QByteArray(size, 0);
	udpSocket->readDatagram(array.data(), size);

	//解析数据
	//1. 类型  2.数据 3.
	QDataStream stream(&array, QIODevice::ReadOnly);
	
	int msgType;//读取到的类型
	
	QString usrName;
	QString msg;
	QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//获取当前时间

	stream >> msgType;

	switch (msgType) {
	case Msg://普通聊天
		stream >> usrName >> msg;
		//追加聊天记录
		ui.msgBrowser->setTextColor(Qt::blue);
		ui.msgBrowser->append("[" + usrName +"]" + time);
		ui.msgBrowser->append(msg);
		break;
	//case UsrEnter:
	//{
	//	//stream >> usrName;
	//bool isEmpty = ui.usrTblWidget->findItems(usrName, Qt::MatchExactly).isEmpty();
	//if (isEmpty) {
	//	QTableWidgetItem* usr = new QTableWidgetItem(usrName);
	//	//插入行
	//	ui.usrTblWidget->insertRow(0);
	//	ui.usrTblWidget->setItem(0, 0, usr);

	//	//追加聊天记录
	//	/*ui.msgBrowser->setTextColor(Qt::red);
	//	ui.msgBrowser->append(QString("%1 上线了").arg(username));*/
	//	//在线人数更新
	//	ui.usrNumLbl->setText(QString("在线用户：%1人").arg(ui.usrTblWidget->rowCount()));

	//	//把自身信息广播出去
	//	//sndMsg(UsrEnter);
	//}

	//}

		//break;
	default:
		break;
	}
}




void ChatWidget::sndMsg(MsgType type) {
	//发送的消息分为3种类型 1.类型 2.用户名 3.具体内容
	QByteArray array;
	QDataStream stream(&array, QIODevice::WriteOnly);
	stream << type<< getUsr();//1.类型 2.用户名 添加到流

	switch (type) {
	case Msg://普通消息发送
		if (ui.msgTxtEdit->toPlainText() == "")//判断用户输入内容是否为空，空则不发消息
		{
			QMessageBox::warning(this,"警告","发送内容为空！");
			return;
		}
		//3.具体说的内容
		stream << getMsg();

		break;
	case UsrEnter://新用户进入消息
		break;
	case UsrLeft://用户离开消息
		break;
	default:
		break;
	}

	//书写报文 通过广播发送
	udpSocket->writeDatagram(array, QHostAddress::Broadcast, port);

}

QString ChatWidget::getUsr() {
	return this->uName;
}

QString ChatWidget::getMsg()
{
	QString str = ui.msgTxtEdit->toHtml();
	//清空输入框
	ui.msgTxtEdit->clear();
	ui.msgTxtEdit->setFocus();
	return str;
}





void ChatWidget::closeEvent(QCloseEvent*)
{
	emit this->closeWidget();
}


ChatWidget::~ChatWidget()
{}