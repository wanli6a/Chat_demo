#include "userWidget.h"
#include "ChatWidget.h"
#include <QPixmap>
#include <QToolButton>
#include <QMessageBox>
#pragma execution_character_set("utf-8")

userWidget::userWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//���ñ����ͼ��
	setWindowTitle("MyQQ");
	setWindowIcon(QPixmap(":/images/chat.jpg"));


	//׼��ͼ��
	QList<QString> nameList;
	nameList << "lala" << "mz" << "qq1" 
		<< "panda" << "x" << "dream" << "hmbb" << "surf" << "mz";
	//׼��ͼ����Դ�б�
	QStringList iconNameList;
	iconNameList<< "lala" << "mz" << "qq1"
		<< "panda" << "x" << "dream" << "hmbb" << "surf" << "mz";

	QVector <QToolButton*> vToolBtn;

	for (int i = 0; i < 9; i++) {
		//����ͷ��ť
		QToolButton* btn = new QToolButton;

		//��������
		btn->setText(nameList[i]);
		//����ͷ��
		QString str = QString(":/images/%1.jpg").arg(iconNameList.at(i));
		btn->setIcon(QPixmap(str));
		//����ͷ���С
		btn->setIconSize(QPixmap(str).size());
		//�������ֺ�ͼƬһ����ʾ
		btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
		//�ӵ���ֱ������
		ui.vLayout->addWidget(btn);
		//����������ס��ť
		vToolBtn.push_back(btn);
	}
	//�԰�ť����źŲ�
	for (int i = 0; i < vToolBtn.size(); i++) {
		connect(vToolBtn[i], &QToolButton::clicked, this, [=]() {

			if (isShow[i]) {
				QString str = QString("%1�����Ѿ�����").arg(vToolBtn[i]->text());
				QMessageBox::warning(this, "����", str);
				return;
			}
			isShow[i] = true;


			//��������Ի����ڹ������촰��ʱ����֪���Զ��㷽ʽ�������Լ��䴰����
			ChatWidget* cwidget = new ChatWidget(nullptr,vToolBtn[i]->text());
			//���ô��ڱ���
			cwidget->setWindowTitle(vToolBtn[i]->text());
			cwidget->setWindowIcon(vToolBtn[i]->icon());
			cwidget->show();

			connect(cwidget, &ChatWidget::closeWidget, [=]() {
				isShow[i] = false;			
				});

			});
	}

	

}

userWidget::~userWidget()
{}
