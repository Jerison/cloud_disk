#include <QtCore/QCoreApplication>
#include "TCPserver.h"
void sql_(){
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("MyDataBase.db");
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug() << "Succeed to connect database." ;
    }
    QSqlQuery sql_query;
    sql_query.exec("create table if not exists users(user_name varchar(16) primary key,password varchar(16),online int default 0)");
    sql_query.exec("create table if not exists files(user_name varchar(16),MD5 char(32),name varchar(100),size int,time varchar(20),primary key(user_name,MD5))");
    //sql_query.exec("insert into files (user_name,MA5,name) values ('123','11111111111111111111111111111111','123123')");
    sql_query.exec("update users set online =0");
    //sql_query.exec("select * from files");
    while(sql_query.next())qDebug()<<sql_query.value(0).toString()<<sql_query.value(1).toString()<<sql_query.value(2).toString()<<sql_query.value(3).toInt();

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	TCPserver *server = new TCPserver();
	server->listen(QHostAddress::Any, 8888);
    sql_();
    return a.exec();
}
