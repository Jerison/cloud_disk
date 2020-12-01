#pragma once

#include <QObject>
#include <QtNetwork/qtcpsocket.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QDateTime>
class file{ //与Client相同
public:
    QString file_name;
    int blocks,file_size;
    bool *arrived;
    QVector<QByteArray> bs;
    QByteArray MD5;
    QString time;
};
class fileU{//与Client相同
public:
    QString file_name;
    int file_size,blocks;
    QFile *file;
    QByteArray MD5;
    int sending_block=1;
    QByteArray buffer;
};
class TCPsocket : public QObject
{
	Q_OBJECT

public:
	TCPsocket(QObject *parent=NULL);
	~TCPsocket();
	
signals:
    void string_to_server_ready(const QString &str);	//socket 将str发给server 目前用来disconnect
    void string_to_socket_ready(const QString &str,int method);
public slots:
	void socket_init(const qintptr socketDescriptor);	//初始化socket和handler对象
	void tell_server_disconnected();					//将disconnected信息发给server
    void user_disconnect();
    void send_str(const QString &str,int choice);
private:
	QTcpSocket *socket;				//socket
    QString user_name;
    QSqlDatabase database;
    QSqlQuery sql_query,sql_query2;
	qintptr socketdescriptor;		//储存当前socket的descriptor
    QVector<file> files;            //上传下载的文件
    QByteArray buffer;              //一次收到的文件流未读完整
    int has_buffer=0;               //是否存在未读完整的buffer
    QVector<fileU> files_D;
    int task_num=0,processed_cur=0,process_lock=1;
    int block_sent=0;               //当前块是否已经发送 避免重复发送同一个块
    void handle_string();           //处理收到的字符串
    void check_byte(QByteArray &a); //检测收到的字节流中是否存在文件块
    void upload_bytes(QByteArray &a);   //将收到字节流中的文件暂存到file的bs中
    void fresh_file();              //将用户拥有的文件信息发送给客户端
    void process_file();        //发送文件

};
