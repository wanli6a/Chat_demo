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

	//��ʼ������
	udpSocket = new QUdpSocket(this);
	//�û�����ȡ
	uName = name;
	//�˿ں�
	this->port = 9999;

	//�󶨶˿ں�   ��ģʽ  �����ַ  ��������
	udpSocket->bind(this->port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

	//�������û�����
	//sndMsg(UsrEnter);

	//������Ͱ�ť������Ϣ
	connect(ui.sendBtn, &QPushButton::clicked, [=]() {
		sndMsg(Msg);
		});

	//�������˷��͵�����
	connect(udpSocket, &QUdpSocket::readyRead, this, &ChatWidget::ReceiveMessage);

	/////////�������õȹ���
	//1.����
	connect(ui.fontCbx, &QFontComboBox::currentFontChanged, [=](const QFont &font) {
		ui.msgTxtEdit->setCurrentFont(font);
		ui.msgTxtEdit->setFocus();
		});
	//2.�ֺ�
	void(QComboBox:: * cbxsingal)(const QString & text) = &QComboBox::currentIndexChanged;
	connect(ui.sizeCbx, cbxsingal, [=](const QString &text) {
		ui.msgTxtEdit->setFontPointSize(text.toDouble());
		ui.msgTxtEdit->setFocus();
				});
	//3.�Ӵ�
	connect(ui.boldTBtn, &QToolButton::clicked, [=](bool isChecked) {
		if (isChecked) {
			ui.msgTxtEdit->setFontWeight(QFont::Bold);

		}
		else {
			ui.msgTxtEdit->setFontWeight(QFont::Normal);
		}
		});
	//4.��б
	connect(ui.italicTBtn, &QToolButton::clicked, [=](bool check) {
		ui.msgTxtEdit->setFontItalic(check);
		});
	//5.�»���
	connect(ui.underlineTBtn, &QToolButton::clicked, [=](bool check) {
		ui.msgTxtEdit->setFontUnderline(check);
		});
	//6.������ɫ
	connect(ui.colorTBtn, &QToolButton::clicked, [=]() {
		QColor color = QColorDialog::getColor(Qt::red);
		ui.msgTxtEdit->setTextColor(color);
		});
	//7.��������¼
	connect(ui.clearTBtn, &QToolButton::clicked, [=]() {
		ui.msgBrowser->clear();
		});
	//8.���������¼
	connect(ui.saveTBtn, &QToolButton::clicked, [=]() {
		if (ui.msgBrowser->document()->isEmpty()) {

			QMessageBox::warning(this, "��ʾ", "·�������ݲ���Ϊ��");
			return;

		}
		else {
			QString path = QFileDialog::getSaveFileName(this, "�����¼", "�����¼", "(*.txt)");
			QFile file(path);
			//��ģʽ���ϻ��в���
			file.open(QIODevice::WriteOnly | QIODevice::Text);
			QTextStream stream(&file);
			stream << ui.msgBrowser->toPlainText();
			file.close();
		}

		
		
		
		});

}

void ChatWidget::ReceiveMessage() {
	//�õ����ݱ���
	//��ȡ����
	qint64 size = udpSocket->pendingDatagramSize();
	QByteArray array = QByteArray(size, 0);
	udpSocket->readDatagram(array.data(), size);

	//��������
	//1. ����  2.���� 3.
	QDataStream stream(&array, QIODevice::ReadOnly);
	
	int msgType;//��ȡ��������
	
	QString usrName;
	QString msg;
	QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//��ȡ��ǰʱ��

	stream >> msgType;

	switch (msgType) {
	case Msg://��ͨ����
		stream >> usrName >> msg;
		//׷�������¼
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
	//	//������
	//	ui.usrTblWidget->insertRow(0);
	//	ui.usrTblWidget->setItem(0, 0, usr);

	//	//׷�������¼
	//	/*ui.msgBrowser->setTextColor(Qt::red);
	//	ui.msgBrowser->append(QString("%1 ������").arg(username));*/
	//	//������������
	//	ui.usrNumLbl->setText(QString("�����û���%1��").arg(ui.usrTblWidget->rowCount()));

	//	//��������Ϣ�㲥��ȥ
	//	//sndMsg(UsrEnter);
	//}

	//}

		//break;
	default:
		break;
	}
}




void ChatWidget::sndMsg(MsgType type) {
	//���͵���Ϣ��Ϊ3������ 1.���� 2.�û��� 3.��������
	QByteArray array;
	QDataStream stream(&array, QIODevice::WriteOnly);
	stream << type<< getUsr();//1.���� 2.�û��� ��ӵ���

	switch (type) {
	case Msg://��ͨ��Ϣ����
		if (ui.msgTxtEdit->toPlainText() == "")//�ж��û����������Ƿ�Ϊ�գ����򲻷���Ϣ
		{
			QMessageBox::warning(this,"����","��������Ϊ�գ�");
			return;
		}
		//3.����˵������
		stream << getMsg();

		break;
	case UsrEnter://���û�������Ϣ
		break;
	case UsrLeft://�û��뿪��Ϣ
		break;
	default:
		break;
	}

	//��д���� ͨ���㲥����
	udpSocket->writeDatagram(array, QHostAddress::Broadcast, port);

}

QString ChatWidget::getUsr() {
	return this->uName;
}

QString ChatWidget::getMsg()
{
	QString str = ui.msgTxtEdit->toHtml();
	//��������
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