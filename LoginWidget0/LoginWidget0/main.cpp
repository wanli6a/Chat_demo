#include "LoginWidget0.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <qDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //�������ݿ�
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("wanli666");
    db.setDatabaseName("mydb");
    if (db.open()) {
        qDebug() << u8"���ݿ����ӳɹ�";
    }
    else {
        qDebug() << u8"���ݿ�����ʧ��";
        db.lastError().text();
    }

   
    LoginWidget0 w;
    w.show();
    return a.exec();
}
