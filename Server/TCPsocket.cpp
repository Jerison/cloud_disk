#include "TCPsocket.h"
#include <QObject>
#define BLOCK_SIZE 8192

TCPsocket::TCPsocket(QObject *parent)
	: QObject(parent)
{
    database=QSqlDatabase::database();      //需要在初始化时声明 在init中声明会导致两个数据库不再同一线程
    //database = QSqlDatabase::addDatabase("QSQLITE");
   // database.setDatabaseName("MyDataBase.db");
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        //qDebug() << "Succeed to connect database." ;
        sql_query=QSqlQuery(database);
        sql_query2=QSqlQuery(database);
    }

}

TCPsocket::~TCPsocket()
{
}
void TCPsocket::socket_init(const qintptr socketDescriptor)
{
    files.resize(100);
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &TCPsocket::handle_string);
    connect(this,&TCPsocket::string_to_socket_ready,this,&TCPsocket::send_str);
    socketdescriptor = socketDescriptor;
    connect(socket, &QTcpSocket::disconnected, this, &TCPsocket::tell_server_disconnected);
    connect(socket, &QTcpSocket::disconnected,  this,&TCPsocket::user_disconnect);
    srand((unsigned int)time(NULL));
}

void TCPsocket::tell_server_disconnected()
{
	QString res = QString("disconnect****%1").arg(socketdescriptor);
	emit string_to_server_ready(res);
}


void TCPsocket::user_disconnect()
{
    sql_query.exec(QString("update users set online=0 where user_name='%1' ").arg(user_name));
}
void TCPsocket::check_byte(QByteArray &a){
    //qDebug()<<"start checking bytes";
    int cur=0;
    while(1){
        if(has_buffer==1){
            int tem=a.indexOf("/*-+",cur);
            if(tem!=-1){
                has_buffer=0;
                cur=tem;
                for(int i=0;i<tem+4;i++){
                    buffer.push_back(a[i]);
                }
                upload_bytes(buffer);
            }else{
                for(int i=0;i<a.size();i++){
                    buffer.push_back(a[i]);
                }
                return;
            }
        }
        int res=a.indexOf("+-*/",cur);
        int res2=a.indexOf("/*-+",res+4);
        cur=res2;
        //qDebug()<<res<<res2;
        if(res!=-1&&res2==-1){
            has_buffer=1;
            buffer.resize(a.size()-res);
            for(int i=0;i<a.size()-res;i++){
                buffer[i]=a[res+i];
            }
        }
        if(res==-1||res2==-1)break;
        else{
            QByteArray a2;
            a2.resize(res2-res+4);
            for(int i=0;i<res2-res+4;i++){
                a2[i]=a[res+i];
            }
            upload_bytes(a2);


        }

    }

}

void TCPsocket::upload_bytes(QByteArray &a){

    auto args=QString(a).split("#");
    //qDebug()<<"server send"<<args;
    int index=args[1].toInt(),cur=args[2].toInt();
    if(cur==0){
        int start=a.indexOf("$");
        int size=args[5].toInt();
        files[index].file_size=size;
        files[index].time=args[6];
        QByteArray MD5;
        MD5.resize(16);
        for(int i=0;i<16;i++)MD5[i]=a[start+1+i];
        files[index].MD5=MD5;
        int res=2;//查重
        QString MD5_s=MD5.toHex();
        sql_query.exec(QString("select * from files where user_name='%1' and MD5='%2'").arg(user_name).arg(MD5_s));
        if(sql_query.next()){
            int res=3;
            emit string_to_socket_ready(QString("upload****%1##%2").arg(index).arg(res),1);
            return;
        }
        sql_query.exec(QString("select * from files where  MD5='%2'").arg(MD5_s));
        if(sql_query.next()){
            sql_query.exec(QString("insert into files (user_name,MD5,name,size,time)values ('%1','%2','%3','%4','%5')")
                           .arg(user_name).arg(MD5_s).arg(args[3]).arg(size).arg(args[6]));
           int res=4;
           emit string_to_socket_ready(QString("upload****%1##%2").arg(index).arg(res),1);
           fresh_file();
           return;
        }
        files[index].blocks=args[4].toInt();
        files[index].file_name=args[3];

        //qDebug()<<"upload"<<files[index].file_name<<files[index].blocks;
        files[index].arrived=new bool[files[index].blocks];
        files[index].bs.resize(files[index].blocks);
        for(int i=0;i<files[index].blocks;i++)files[index].bs[i].resize(BLOCK_SIZE);
        //qDebug()<<files[index].blocks;
        emit string_to_socket_ready(QString("upload****%1##%2").arg(index).arg(res),1);
        return;
    }
    //qDebug()<<"upload"<<index<<cur;
    int start=a.indexOf("$");
    int i;
    for(i=start+1;i<a.size()-4;i++){

        files[index].bs[cur-1][i-start-1]=a[i];
    }
    emit string_to_socket_ready(QString("ack****%1##%2").arg(index).arg(cur),1);
    files[index].arrived[cur-1]=1;
    if(cur==files[index].blocks){
        files[index].bs[cur-1].resize(a.size()-4-start-1);
        for(int i=0;i<files[index].blocks;i++){
            if(!files[index].arrived[i]){
                qDebug()<<"upload file fatal error";
                return;
            }

        }

        //qDebug()<<"Start fill file";
        QString MD5=files[index].MD5.toHex();

        QFile *out=new QFile(QString("files/%1").arg(MD5));
        out->open(QIODevice::WriteOnly);
        for(auto &it:files[index].bs){
            out->write(it);
        }
        for(int i=0;i<files[index].blocks;i++)files[index].bs[i].clear();
        out->close();
        qDebug()<<user_name<<"upload"<<files[index].file_name<<"success";

        sql_query.exec(QString("insert into files (user_name,MD5,name,size,time)values ('%1','%2','%3','%4','%5')")
                       .arg(user_name).arg(MD5).arg(files[index].file_name).arg(files[index].file_size).arg(files[index].time));
        fresh_file();
    }




}
void TCPsocket::handle_string() //工作原理与read_from_socket相同
{
    QByteArray as=socket->readAll();
    //qDebug()<<"receive size"<<as.size();
    int cur=0;
    QString str;
    QVector<int> poses;

    int tem=as.indexOf("^()",cur);
    while(tem!=-1){
        poses.push_back(tem);
        cur=tem+3;
        tem=as.indexOf("^()",cur);
    }
    QStringList lists;
    for(int i=0;i<poses.size()-1;i++){
        QString tem;
        for(int j=poses[i]+3;j<poses[i+1];j++){
            tem+=as[j];
        }
        lists.push_back(tem);
    }
    //if(lists.size())qDebug()<<lists;

    for(auto &str:lists){
        if (str.length() == 0)continue;
    QStringList list = str.split("****");
    QString mode = list.at(0);
    if (mode == "login") {
        if (list.at(1).length() < 6 || list.at(2).length() < 6) {	//冗余设置
            emit string_to_socket_ready(QString("login****fail****用户名或密码长度不足6位，请重新输入。"), 1);
            return;
        }
        sql_query.exec(QString("select * from users where user_name='%1'").arg(list.at(1)));
        if (sql_query.next()) {
            QString password = sql_query.value(1).toString();
            if (password == list.at(2)) {
                if(sql_query.value(2).toInt()==1){
                    emit string_to_socket_ready(QString("login****fail****用户已登录。"), 1);
                    return;
                }
                user_name = list.at(1);
                sql_query.exec(QString("update users set online=1 where user_name='%1' ").arg(list.at(1)));
                emit string_to_socket_ready(QString("user %1 login success").arg(list.at(1)), 2);
                emit string_to_socket_ready(QString("login****success****登录成功"), 1);
                fresh_file();
            }
            else {
                emit string_to_socket_ready(QString("login****fail****密码错误，请检查后重新登录。"), 1);
            }
        }
        else {
            emit string_to_socket_ready(QString("login****fail****用户名%1未被注册，请先注册用户。").arg(list.at(1)), 1);
        }
    }else if(mode=="register"){
        if (list.at(1).length() < 6 || list.at(2).length() < 6) {	//冗余设置
            emit string_to_socket_ready(QString("register****fail****用户名或密码长度不足6位，请重新输入。"), 1);
            return;
        }
        sql_query.exec(QString("select * from users where user_name='%1'\0").arg(list.at(1)));
        if (sql_query.next()) {
            emit string_to_socket_ready("register failed", 2);
            emit string_to_socket_ready(QString("register****fail****用户名%1已被注册，请换用户名重新注册。").arg(list.at(1)), 1);
        }
        else {
            sql_query.exec(QString("insert into users values ('%1','%2',1)").arg(list.at(1)).arg(list.at(2)));
            user_name = list.at(1);
            emit string_to_socket_ready(QString("user %1 register success").arg(list.at(1)), 2);
            emit string_to_socket_ready(QString("register****success****恭喜您注册成功"), 1);
            fresh_file();
        }
    }else if(mode=="logout"){
        sql_query.exec(QString("update users set online=0 where user_name='%1' ").arg(user_name));
    }else if(mode=="fresh"){
           fresh_file();
    }else if(mode=="download"){
        auto args=list.at(1).split("##");
        fileU tem;
        tem.file_name=args[0];
        sql_query.exec(QString("select MD5,size from files where name='%1' and user_name").arg(tem.file_name).arg(user_name));
        sql_query.next();
        QString MD5_=sql_query.value(0).toString();
        int size=sql_query.value(1).toInt();
        tem.file=new QFile(QString("files/%1").arg(MD5_));
        tem.file->open(QIODevice::ReadOnly);
        tem.blocks=size/BLOCK_SIZE+1;
        //qDebug()<<"Block"<<tem.blocks;
        task_num++;
        files_D.push_back(tem);
        if(process_lock){
            process_lock=0;
            process_file();
        }
    }else if(mode=="ack"){
        auto args=list.at(1).split("##");
        block_sent=0;
        if(args[0].toInt()==processed_cur&&args[1].toInt()==files_D[processed_cur].sending_block){
            if(files_D[processed_cur].sending_block==files_D[processed_cur].blocks){
                processed_cur++;

            }else{

                files_D[processed_cur].sending_block++;
            }
        }
        if(process_lock){
            process_lock=0;

            process_file();
        }

    }else if(mode=="share"){
        auto args=list.at(1).split("##");
        sql_query.exec(QString("select * from users where user_name='%1'").arg(args[0]));
        if(sql_query.next()){
            sql_query.exec(QString("select * from files where user_name='%1' and name='%2'").arg(args[0]).arg(list.at(1)));
            if(sql_query.next()){
                continue;
            }else{
                sql_query.exec(QString("select * from files where user_name='%1' and name='%2'").arg(user_name).arg(args[1]));
                sql_query.next();
                QString md5=sql_query.value(1).toString();
                int size=sql_query.value(3).toInt();
                QDateTime t=QDateTime::currentDateTime();
                QString time=t.toString("yyyy.MM.dd hh:mm");
                sql_query.exec(QString("select * from files where md5='%1' and user_name='%2'")
                               .arg(md5).arg(args[0]));
                if(sql_query.next()){
                    continue;
                }
                sql_query.exec(QString("insert into files values('%1','%2','%3',%4,'%5')")
                               .arg(args[0]).arg(md5).arg(args[1]).arg(size).arg(time));
            }
        }

    }
}
    check_byte(as);
}
void TCPsocket::process_file(){
    while(processed_cur<task_num){
        //qDebug()<<"download"<<processed_cur<<files_D[processed_cur].sending_block;
        auto &file=files_D[processed_cur];
        if(block_sent==1){
            process_lock=1;
            return;
        }
        file.buffer=file.file->read(BLOCK_SIZE);
        file.buffer.insert(0,QString("+-*/#%1#%2#$").arg(processed_cur).arg(file.sending_block));
        file.buffer.push_back("/*-+");
        //qDebug()<<"size"<<file.buffer.size();
        socket->write(file.buffer);
        block_sent=1;
        process_lock=1;
        return;
    }
    process_lock=1;
}
void TCPsocket::fresh_file(){   //查询并发送用户的文件信息
    QString res="fresh****";
    sql_query.exec(QString("select name,size,time from files where user_name='%1'").arg(user_name));
    int first=1;
    while(sql_query.next()){
        if(first)first=0;
        else res+="##";
        res+=(sql_query.value(0).toString()+"$$"+sql_query.value(1).toString()+"$$"+sql_query.value(2).toString());
    }

    emit string_to_socket_ready(res,1);
}

void TCPsocket::send_str(const QString &str,int choice){    //choice为1时 为报文增加报头报尾发送
    switch (choice)
        {
        case 1:{

        QString res=QString("^()")+str+QString("^()");
        socket->write(res.toUtf8());
        break;
            }

        case 2:
            QString result = QString("debug****%1").arg(str);
            emit string_to_server_ready(result);
            break;
        }
}
