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
	//设置标题和图标
	setWindowTitle("MyQQ");
	setWindowIcon(QPixmap(":/images/chat.jpg"));


	//准备图标
	QList<QString> nameList;
	nameList << "lala" << "mz" << "qq1" 
		<< "panda" << "x" << "dream" << "hmbb" << "surf" << "mz";
	//准备图标资源列表
	QStringList iconNameList;
	iconNameList<< "lala" << "mz" << "qq1"
		<< "panda" << "x" << "dream" << "hmbb" << "surf" << "mz";

	QVector <QToolButton*> vToolBtn;

	for (int i = 0; i < 9; i++) {
		//设置头像按钮
		QToolButton* btn = new QToolButton;

		//设置文字
		btn->setText(nameList[i]);
		//设置头像
		QString str = QString(":/images/%1.jpg").arg(iconNameList.at(i));
		btn->setIcon(QPixmap(str));
		//设置头像大小
		btn->setIconSize(QPixmap(str).size());
		//设置文字和图片一起显示
		btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
		//加到垂直布局中
		ui.vLayout->addWidget(btn);
		//用容器保存住按钮
		vToolBtn.push_back(btn);
	}
	//对按钮添加信号槽
	for (int i = 0; i < vToolBtn.size(); i++) {
		connect(vToolBtn[i], &QToolButton::clicked, this, [=]() {

			if (isShow[i]) {
				QString str = QString("%1窗口已经被打开").arg(vToolBtn[i]->text());
				QMessageBox::warning(this, "警告", str);
				return;
			}
			isShow[i] = true;


			//弹出聊天对话框，在构造聊天窗口时，告知它以顶层方式弹出，以及其窗口名
			ChatWidget* cwidget = new ChatWidget(nullptr,vToolBtn[i]->text());
			//设置窗口标题
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
