#include "LoginWidget0.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <qDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("wanli666");
    db.setDatabaseName("mydb");
    if (db.open()) {
        qDebug() << u8"数据库连接成功";
    }
    else {
        qDebug() << u8"数据库连接失败";
        db.lastError().text();
    }

   
    LoginWidget0 w;
    w.show();
    return a.exec();
}
