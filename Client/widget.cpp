#include "widget.h"
#include "ui_widget.h"
#define BLOCK_SIZE 8192
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
    ui->fresh->hide();
    ui->share->hide();
    ui->FriendsList->setRowCount(1);
    set_hidden(1);
    for(int i = 0; i< 1;i++){
        //ui->FriendsList->setItem(i,0,new QTableWidgetItem("jerison"));
    }
    this->resize(858,600);
    socket = new QTcpSocket(this);
    socket->connectToHost("62.234.142.180", 8888);  //  QHostAddress::LocalHost "62.234.142.180"
    if (socket->waitForConnected()) {
        qDebug()<< "TCP connected";
    } else {
        qDebug() << "TCP connect failed";
        QMessageBox::information(this, "提示", "无法连接到服务器!");
        exit(0);
    }

    cur_w = NULL;
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &Widget::set_hidden);
    connect(socket, &QTcpSocket::readyRead, this, &Widget::read_from_socket);
    connect(ui->button_login, &QPushButton::clicked, this, &Widget::try_login);
    connect(ui->button_register, &QPushButton::clicked, this, &Widget::try_register);
    //connect(cur_w, &MainWindow::open_chat,this,&Widget::share_in_session);
    //将定时器与更新传输状态相连
    status_timer.setInterval(1000);
    connect(&status_timer,&QTimer::timeout,this,&Widget::fresh_status);
    status_timer.start();
    //设置两个table widget的列宽
    int width=800;
    ui->files->setColumnWidth(0,0.45*width);
    ui->files->setColumnWidth(1,0.2*width);
    ui->files->setColumnWidth(2,0.3*width);
    ui->transport->setColumnWidth(0,0.45*width);
    ui->transport->setColumnWidth(1,0.2*width);
    ui->transport->setColumnWidth(2,0.3*width);
    ui->files_2->setColumnWidth(0,0.45*width);
    ui->files_2->setColumnWidth(1,0.2*width);
    ui->files_2->setColumnWidth(2,0.3*width);
    waiting_req = 0;

}

void Widget::fresh_status() {
    ui->transport->setRowCount(status.size());//设置行数
    for(int i=0; i<status.size(); i++) {        //三栏分别为文件名 文件大小 上传下载进度
        //qDebug()<<status[i].file_name;
        ui->transport->setItem(i,0,new QTableWidgetItem(status[i].file_name));
        int size=status[i].size/1024;
        if(size==0)size=1;
        ui->transport->setItem(i,1,new QTableWidgetItem(QString("%1KB").arg(size)));
        QString tem;
        if(status[i].type==1)tem="上传";
        else tem="下载";
        ui->transport->setItem(i,2,new QTableWidgetItem(QString("%1完成:%2%").arg(tem).arg(100.0*status[i].excuted_blocks/status[i].blocks)));
    }
}
void Widget::try_login() {  //将登录信息以 login****用户名****密码 的方式发送给服务端验证
    user_name = ui->edit_username->text();
    if (user_name.length() < 6) {
        QMessageBox::information(this, "提示", "用户名长度应至少6位，请重新输入。");
        return;
    }else if(user_name.length() > 16){
        QMessageBox::information(this, "提示", "用户名长度最多为16位，请重新输入。");
        return;
    }
    QString password = ui->edit_password->text();
    if (password.length() < 6) {
        QMessageBox::information(this, "提示", "密码长度应至少六位，请重新输入。");
        return;
    }else if(password.length()>16){
        QMessageBox::information(this, "提示", "密码长度最多为16位，请重新输入。");
        return;
    }
    QString res = QString("login****%1****%2").arg(user_name).arg(password);
    send_to_socket(res);
}
void Widget::try_register() {   //将注册信息以 register****用户名****密码 的方式发送给服务端验证
    user_name = ui->edit_username->text();
    if (user_name.length() < 6) {
        QMessageBox::information(this, "提示", "用户名长度应至少6位，请重新输入。");
        return;
    }else if(user_name.length() > 16){
        QMessageBox::information(this, "提示", "用户名长度最多为16位，请重新输入。");
        return;
    }
    QString password = ui->edit_password->text();
    if (password.length() < 6) {
        QMessageBox::information(this, "提示", "密码长度应至少六位，请重新输入。");
        return;
    }else if(password.length()>16){
        QMessageBox::information(this, "提示", "密码长度最多为16位，请重新输入。");
        return;
    }
    QString res = QString("register****%1****%2").arg(user_name).arg(password);
    send_to_socket(res);
}
void Widget::send_to_socket(QString &str) { //为发送的QString加上报文头尾
    socket->write(("^()"+str+"^()").toUtf8());
}
void Widget::read_from_socket() {
    QByteArray as=socket->readAll();    //以字节流形式从socket读取
    //qDebug()<<"receive size"<<as.size();
    int cur=0;
    QString str;
    QVector<int> poses; //储存发现报文头的位置
    int tem=as.indexOf("^()",cur);
    while(tem!=-1) {
        poses.push_back(tem);
        cur=tem+3;
        tem=as.indexOf("^()",cur);
    }
    QStringList lists;  //将报文储存在lists中
    for(int i=0; i<poses.size()-1; i++) {
        QByteArray tem;
        for(int j=poses[i]+3; j<poses[i+1]; j++) {
            tem+=as[j];
        }
        QString tem2(tem);
        //qDebug()<<tem2;
        lists.push_back(tem2);
    }
    //if(lists.size())qDebug()<<lists;

    for (auto &str:lists) {     //处理每一条报文
        if (str.length() == 0)continue;
        QStringList list = str.split("****");   //报文主要内容以****分割
        QString mode = list.at(0);              //开头部分为功能
        if (mode == "register" || mode == "login") {    //登录/注册的回复
            QMessageBox::information(this, "提示", list.at(2));
            if(list.at(1)=="success") {
                ui->stackedWidget->setCurrentIndex(1);
                ui->files->setRowCount(0);
                ui->transport->setRowCount(0);
                ui->label_user_name->setText(QString("用户:%1").arg(user_name));
            }
        } else if(mode=="ack") {        //上传块得到ack回复
            auto args=list.at(1).split("##");
            block_sent=0;
            if(args[0].toInt()==processed_cur&&args[1].toInt()==files_U[processed_cur].sending_block) {
                status[status_up_cur].excuted_blocks++;
                if(files_U[processed_cur].sending_block==files_U[processed_cur].blocks) {
                    seek_next_up_cur();
                    qDebug()<<"upload"<<files_U[processed_cur].file_name<<"success";
                    processed_cur++;
                } else {
                    files_U[processed_cur].sending_block++;

                }
            }
            if(process_lock) {
                process_lock=0;
                process_file();
            }
        } else if(mode=="upload") {        //接受要上传文件的查重结果
            auto args=list.at(1).split("##");
            files_U[args[0].toInt()].type=args[1].toInt();
            if(process_lock) {
                process_lock=0;
                process_file();
            }
        } else if(mode=="fresh") {          //刷新现有文件
            if(list.at(1).size()==0) {
                ui->files->setRowCount(1);
                ui->files->setItem(0,0,new QTableWidgetItem("无文件"));
                continue;
            }
            auto files=list.at(1).split("##");  //各文件以##隔开
            ui->files->setRowCount(files.size());
            file_size.resize(files.size());
            for(int i=0; i<files.size(); i++) {
                auto args=files[i].split("$$");//每个文件是文件名 文件大小 上传时间的三元组
                file_size[i]=args[1].toInt();
                int size=file_size[i]/1024;
                if(size==0)size=1;
                QString size_=QString("%1KB").arg(size);
                ui->files->setItem(i,0,new QTableWidgetItem(args[0]));
                ui->files->setItem(i,1,new QTableWidgetItem(size_));
                ui->files->setItem(i,2,new QTableWidgetItem(args[2]));
            }

            ui->files_2->setRowCount(files.size());
            file_size.resize(files.size());
            for(int i=0; i<files.size(); i++) {
                auto args=files[i].split("$$");//每个文件是文件名 文件大小 上传时间的三元组
                file_size[i]=args[1].toInt();
                int size=file_size[i]/1024;
                if(size==0)size=1;
                QString size_=QString("%1KB").arg(size);
                ui->files_2->setItem(i,0,new QTableWidgetItem(args[0]));
                ui->files_2->setItem(i,1,new QTableWidgetItem(size_));
                ui->files_2->setItem(i,2,new QTableWidgetItem(args[2]));
            }
        }
        else if(mode == "friendlist"){
            auto args=list.at(1).split("##");
            ui->FriendsList->setRowCount(args.size());
            for(int i = 0; i< args.size();i++){
                ui->FriendsList->setItem(i,0,new QTableWidgetItem(args[i]));
            }
        }
        else if(mode == "chatmsg"){
            auto msgs = list.at(1).split("##");
            for(int i = 0;i < msgs.size(); i++ ){
                auto args = msgs[i].split("$$");//每条信息的格式:来源$$消息
                for(int j = 0; j < ui->FriendsList->rowCount(); j++){
                    if(args[0] == ui->FriendsList->item(j,0)->text())
                        ui->FriendsList->setItem(j,1, new QTableWidgetItem(args[1]));
                }

            }
        }
        else if(mode == "friendreq"){
            qDebug()<<"request found!";
            auto args = list.at(1).split("##");
            ui->ReqList->setRowCount(args.size());
            for(int i = 0; i< args.size();i++){
                ui->ReqList->setItem(i,0,new QTableWidgetItem(args[i]));
            }
        }
        else if(mode == "sentmsg"){

        }
        else if(mode == "onlinemsg"){
            qDebug()<<"received online msg";
            auto msg_all=list.at(1).split("##");  //各信息以##隔开
            for(int i=0; i<msg_all.size(); i++) {
                auto args=msg_all[i].split("$$");//每条信息是 来自用户 信息内容 的二元组
                if(cur_w && cur_w->getCurUser() == args[0]){
                    cur_w->showMsg(args[1]);
                }
                qDebug()<<"entered loop!";
                for(int j = 0; j < ui->FriendsList->rowCount(); j++){
                    qDebug()<<"j="<<j;
                    QString s = ui->FriendsList->item(j,0)->text();
                    if(args[0] == ui->FriendsList->item(j,0)->text()){
                        qDebug()<<"p1";
                        QString res = "";
                        if(ui->FriendsList->item(j,1))
                            res = ui->FriendsList->item(j,1)->text();
                        res += "##";
                        res += args[1];
                        ui->FriendsList->setItem(j,1,new QTableWidgetItem(res));
                    }
                }
            }
        }
        else if(mode == "offlinemsg"){
            auto msg_all=list.at(1).split("##");  //各信息以##隔开
            for(int i=0; i<msg_all.size(); i++) {
                auto args=msg_all[i].split("$$");//每条信息是 来自用户 信息内容 的二元组
                qDebug()<<"entered loop!";
                for(int j = 0; j < ui->FriendsList->rowCount(); j++){
                    qDebug()<<"j="<<j;
                    QString s = ui->FriendsList->item(j,0)->text();
                    if(args[0] == ui->FriendsList->item(j,0)->text()){
                        qDebug()<<"p1";
                        QString res = "";
                        if(ui->FriendsList->item(j,1))
                            res = ui->FriendsList->item(j,1)->text();
                        res += "##";
                        res += args[1];
                        ui->FriendsList->setItem(j,1,new QTableWidgetItem(res));
                    }
                }
            }
        }

    }
    check_byte(as); //检测字节流中是否存在下载的文件字节
}
void Widget::seek_next_up_cur() {   //寻找传输状态的下一个文件下标
    for(int i=status_up_cur+1; i<status.size(); i++) {
        if(status[i].type==1) {
            status_up_cur=i;
            break;
        }
    }
}
void Widget::check_byte(QByteArray &a) {    //检测是否存在
    //qDebug()<<"start checking bytes";
    int cur=0;
    while(1) {
        if(has_buffer==1) {         //如果存在buffer 寻找字节流尾
            int tem=a.indexOf("/*-+",cur);
            if(tem!=-1) {           //找到的话打包储存
                has_buffer=0;
                cur=tem;
                for(int i=0; i<tem+4; i++) {
                    buffer.push_back(a[i]);
                }
                upload_bytes(buffer);
            } else {                //没找到在下一次读入的字节流中寻找
                for(int i=0; i<a.size(); i++) {
                    buffer.push_back(a[i]);
                }
                return;
            }
        }
        int res=a.indexOf("+-*/",cur);
        int res2=a.indexOf("/*-+",res+4);
        cur=res2;
        //qDebug()<<res<<res2;
        if(res!=-1&&res2==-1) {
            has_buffer=1;
            buffer.resize(a.size()-res);
            for(int i=0; i<a.size()-res; i++) {
                buffer[i]=a[res+i];
            }
        }
        if(res==-1||res2==-1)break;
        else {
            QByteArray a2;
            a2.resize(res2-res+4);
            for(int i=0; i<res2-res+4; i++) {
                a2[i]=a[res+i];
            }
            upload_bytes(a2);


        }

    }

}
void Widget::upload_bytes(QByteArray &a) {//储存打包的字节流
    auto args=QString(a).split("#");
    int index=args[1].toInt(),cur=args[2].toInt();
    //qDebug()<<"upload"<<index<<cur;
    int start=a.indexOf("$");
    int i;
    for(i=start+1; i<a.size()-4; i++) {
        //qDebug()<<i-start-1;
        files_D[index].bs[cur-1][i-start-1]=a[i];
    }
    status[status_down_cur].excuted_blocks++;
    QString res=QString("ack****%1##%2").arg(index).arg(cur);
    send_to_socket(res);
    files_D[index].arrived[cur-1]=1;
    if(cur==files_D[index].blocks) {
        files_D[index].bs[cur-1].resize(a.size()-4-start-1);
        for(int i=0; i<files_D[index].blocks; i++) {
            if(!files_D[index].arrived[i])return;
        }
        //出循环代表读取完成
        for(int i=status_down_cur+1; i<status.size(); i++) {
            if(status[i].type==0) {
                status_down_cur=i;
                break;
            }
        }
        QFile *out=new QFile(files_D[index].file_path);
        out->open(QIODevice::WriteOnly);
        for(auto &it:files_D[index].bs) {
            out->write(it);
        }
        for(int i=0; i<files_D[index].blocks; i++)files_D[index].bs[i].clear();
        out->close();
        qDebug()<<"download"<<files_D[index].file_name<<"succees";
    }


}

Widget::~Widget() {
    //关闭窗口时若用户处在登录状态，将用户登出
    if(ui->stackedWidget->currentIndex()){
        qDebug()<<"logged out";
        on_Button_logout_clicked();
    }
    delete ui;
}


void Widget::on_pushButton_6_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_5_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void Widget::on_Button_logout_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
    ui->transport->setRowCount(0);
    status.clear();
    status_up_cur=status_down_cur=-1;
    QString res="logout****";
    send_to_socket(res);
}

void Widget::on_upload_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this, "选择上传文件", "..\\", "InputFile (*.*)");
    if (file_name == "")return;

    fileU tem;
    file_status tem2;
    tem.file=new QFile(file_name);
    tem.file->open(QIODevice::ReadOnly);
    tem.file_size=tem.file->size();

    tem2.size=tem.file_size;
    tem2.type=1;

    //qDebug()<<"size:"<<tem.file_size;
    tem.file_name = file_name.right(file_name.size() - file_name.lastIndexOf('/')-1);
    tem2.file_name=tem.file_name;
    tem.blocks=tem.file_size/BLOCK_SIZE+1;
    tem2.blocks=tem.blocks;
    status.push_back(tem2);
    if(status_up_cur==-1) {
        status_up_cur=status.size()-1;
    } else if(status[status_up_cur].excuted_blocks==status[status_up_cur].blocks) {
        status_up_cur=status.size()-1;
    }
    tem.type=1;
    QCryptographicHash Hash(QCryptographicHash::Md5);
    Hash.addData(tem.file->read(1000));
    tem.file->seek(0);
    tem.MD5=Hash.result();
    //qDebug()<<QString(tem.MD5.toHex());
    QByteArray a=tem.MD5;
    QDateTime t=QDateTime::currentDateTime();
    QString time=t.toString("yyyy.MM.dd hh:mm");
    a.insert(0,QString("+-*/#%1#0#%2#%3#%4#%5#$").arg(task_num).arg(tem.file_name).arg(tem.blocks).arg(tem.file_size).arg(time));
    a.push_back("/*-+");
    socket->write(a);

    files_U.push_back(tem);
    task_num++;
}
void Widget::process_file() {
    //qDebug()<<"upload here";
    while(processed_cur<task_num) {

        auto &file=files_U[processed_cur];
        if(file.type==1)break;
        else if(file.type==3) {
            processed_cur++;
            QMessageBox::information(this,"提示",QString("文件%1已存在。").arg(file.file_name));
            status[status_up_cur].excuted_blocks=status[status_up_cur].blocks;
            seek_next_up_cur();
            continue;
        } else if(file.type==4) {
            processed_cur++;
            QMessageBox::information(this,"提示",QString("文件%1闪存。").arg(file.file_name));
            status[status_up_cur].excuted_blocks=status[status_up_cur].blocks;
            seek_next_up_cur();
            continue;
        }
        if(block_sent==1) {
            process_lock=1;
            return;
        }
        file.buffer=file.file->read(BLOCK_SIZE);
        file.buffer.insert(0,QString("+-*/#%1#%2#$").arg(processed_cur).arg(file.sending_block));
        file.buffer.push_back("/*-+");
        //qDebug()<<processed_cur<<file.sending_block;
        socket->write(file.buffer);
        block_sent=1;
        process_lock=1;
        return;
    }
    process_lock=1;
}

void Widget::on_download_clicked() {
    int choice=ui->files->currentRow();
    if(choice==-1) {
        QMessageBox::information(this,"提示","请选择要下载的文件。");
        return;
    }
    fileD tem;
    file_status tem2;
    QString file_name=ui->files->item(choice,0)->text();
    QString path = QFileDialog::getSaveFileName(this, "选择保存文件位置", "..\\"+file_name);
    tem.file_name=file_name;
    tem2.file_name=file_name;

    tem.file_size=file_size[choice];
    tem2.size=tem.file_size;
    tem.blocks=tem.file_size/BLOCK_SIZE+1;
    tem2.blocks=tem.blocks;
    tem2.type=0;
    status.push_back(tem2);
    if(status_down_cur==-1) {
        status_down_cur=status.size()-1;
    } else if(status[status_down_cur].blocks==status[status_down_cur].excuted_blocks) {
        status_down_cur=status.size()-1;
    }
    tem.bs.resize(tem.blocks);
    tem.arrived=new bool[tem.blocks];
    //qDebug()<<"Blocks:"<<tem.blocks;
    for(int i=0; i<tem.blocks; i++)tem.bs[i].resize(BLOCK_SIZE);
    tem.file_path=path;
    files_D.push_back(tem);
    //qDebug()<<tem.file_name<<tem.file_size<<tem.blocks;
    QString res=QString("download****%1##%2").arg(file_name).arg(task_num_D);
    send_to_socket(res);
    task_num_D++;
}

void Widget::on_fresh_clicked() {
    QString res="fresh****";
    send_to_socket(res);

}

void Widget::on_share_clicked() {
    int choice=ui->files->currentRow();
    if(choice==-1) {
        QMessageBox::information(this,"提示","请选择要分享的文件。");
        return;
    }
    QString file_name=ui->files->item(choice,0)->text();
    bool ok;
    QString user_name = QInputDialog::getText(this,"输入用户名",tr("请输入要分享用户的用户名：")
                                              , QLineEdit::Normal,"", &ok);
    if (ok && !user_name.isEmpty()) {
        QMessageBox::information(this,"提示",QString("已尝试将文件%1分享给用户%2").arg(file_name).arg(user_name));
        QString res=QString("share****%1##%2").arg(user_name).arg(file_name);   //发送分享请求
        send_to_socket(res);
    }
    else if(ok && user_name.isEmpty()){
        QMessageBox::information(this,"提示",QString("用户名不可为空！"));
        on_share_clicked();
    }
}

void Widget::on_shareCancel_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_shareConfirm_clicked(){
    int choice=ui->files_2->currentRow();
    if(choice==-1) {
        QMessageBox::information(this,"提示","请选择要分享的文件。");
        return;
    }
    QString file_name=ui->files->item(choice,0)->text();
    QMessageBox::information(this,"提示",QString("已尝试将文件%1分享给用户%2").arg(file_name).arg(Cur_Target));
    QString res=QString("share****%1##%2").arg(Cur_Target).arg(file_name);   //发送分享请求
    send_to_socket(res);
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::share_in_session(QString user_name){
    qDebug()<<"in!";
    ui->stackedWidget->setCurrentIndex(3);
    Cur_Target = user_name;
    QMessageBox::information(this,"提示","请选择要分享的文件。");
}

void Widget::on_session_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    QString res = "friendlist****";
    send_to_socket(res);
    res = "chatmsg****";
    send_to_socket(res);
}

void Widget::show_cur_w()
{
    cur_w->show();
}

void Widget::on_StartChat_clicked()
{
    int choice=ui->FriendsList->currentRow();
    if(choice==-1) {
        QMessageBox::information(this,"提示","请选择好友！");
        return;
    }
    QString user_name=ui->FriendsList->item(choice,0)->text();
    cur_w = new MainWindow(user_name);
    show_cur_w();
    connect(cur_w, &MainWindow::open_chat, this, &Widget::share_in_session);
    connect(cur_w, &MainWindow::send_msg, this, &Widget::send_msg);
    connect(cur_w, &MainWindow::close_cur_w, this, &Widget::close_cur_w);
    QString init_msg = "";
    if(ui->FriendsList->item(choice,1)){
        init_msg += ui->FriendsList->item(choice,1)->text();
        auto msg_unread = init_msg.split("##");
        for(int i = 0; i < msg_unread.size(); i++){
            cur_w->showMsg(msg_unread[i]);
        }
    }
}

void Widget::on_AddFriends_clicked(){
    bool ok;
    QString user_name = QInputDialog::getText(this,"输入用户名",tr("请输入对方用户名：")
                                              , QLineEdit::Normal,"", &ok);
    if (ok && !user_name.isEmpty()) {
        QMessageBox::information(this,"提示",QString("已向%1发送好友申请").arg(user_name));
        QString res = QString("friend****%1").arg(user_name);   //发送好友申请
        qDebug()<<QString("requested %1").arg(user_name);
        send_to_socket(res);
    }
    else if(ok && user_name.isEmpty()){
        QMessageBox::information(this,"提示",QString("用户名不可为空！"));
        on_AddFriends_clicked();
    }
}

void Widget::on_GoBack_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_PassReq_clicked(){
    int choice=ui->ReqList->currentRow();
    if(choice==-1) {
        QMessageBox::information(this,"提示","请选择需要通过的请求。");
        return;
    }
    QString user_name=ui->ReqList->item(choice,0)->text();
    QMessageBox::information(this,"提示",QString("已通过%1的好友申请。").arg(user_name));
    QString res=QString("friendack****%1").arg(user_name);   //发送接收请求
    send_to_socket(res);
    ui->ReqList->removeRow(choice);
    res = "friendlist****";
    send_to_socket(res);
}

void Widget::on_RejReq_clicked(){
    int choice=ui->ReqList->currentRow();
    if(choice==-1) {
        QMessageBox::information(this,"提示","请选择需要通过的请求。");
        return;
    }

    QString user_name=ui->ReqList->item(choice,0)->text();
    QMessageBox::information(this,"提示",QString("已拒绝%1的好友申请。").arg(user_name));
    ui->ReqList->removeRow(choice);
    QString res=QString("friendrej****%1").arg(user_name);   //发送拒绝请求
    send_to_socket(res);
}

void Widget::send_msg(QString msg)
{
    QString res = QString("send****%1$$%2").arg(cur_w->getCurUser()).arg(msg);
    qDebug()<<"sent msg: "<<res;
    send_to_socket(res);
}

void Widget::close_cur_w(){
    delete cur_w;
    cur_w = NULL;
    qDebug()<<"window closed!";
}

void Widget::set_hidden(int index)
{
    if(ui->tabWidget->currentIndex()){
        ui->AddFriends->hide();
        ui->StartChat->hide();
        ui->PassReq->show();
        ui->RejReq->show();
    }
    else{
        ui->AddFriends->show();
        ui->StartChat->show();
        ui->PassReq->hide();
        ui->RejReq->hide();
    }
}

void Widget::on_rename_clicked()
{
    int choice=ui->files->currentRow();
    if(choice==-1) {
        QMessageBox::information(this,"提示","请选择要重命名的文件。");
        return;
    }
    QString file_name=ui->files->item(choice,0)->text();
    bool ok;
    QString changed_name = QInputDialog::getText(this,"输入文件名",tr("请输入修改后的文件名：")
                                              , QLineEdit::Normal,file_name, &ok);
    if (ok && !changed_name.isEmpty()) {
        int num=0;
        for(int i=0;i<ui->files->rowCount();i++){
            if(ui->files->item(i,0)->text()==changed_name)num++;
        }
        if(num!=0){
            QMessageBox::information(this,"提示",QString("文件名不可重复！"));
            return;
        }
        QString res=QString("rename****%1##%2").arg(file_name).arg(changed_name);   //发送分享请求
        send_to_socket(res);
    }else if(ok && changed_name.isEmpty()){
        QMessageBox::information(this,"提示",QString("文件名不可为空！"));
        return;
    }
}

void Widget::on_delete_file_clicked()
{
    int choice=ui->files->currentRow();
    if(choice==-1) {
        QMessageBox::information(this,"提示","请选择要删除的文件。");
        return;
    }
    QString file_name=ui->files->item(choice,0)->text();
    QString res=QString("delete****%1").arg(file_name);   //发送分享请求
    send_to_socket(res);
}
