#pragma once

#include <QWidget>
#include "ui_userWidget.h"

class userWidget : public QWidget
{
	Q_OBJECT

public:
	userWidget(QWidget *parent=nullptr);
	
	~userWidget();

private:
	Ui::userWidgetClass ui;

	QVector<bool> isShow;
};
