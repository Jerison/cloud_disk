#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>

#include <QtNetwork/QtNetwork>
#include <QMessageBox>
#include <QFileDialog>
#include <QUuid>
#include <QCryptographicHash>
#include <QDateTime>
#include <QTimer>
#include <QInputDialog>
#include "chat_mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class fileU{    //上传文件 结构体
public:
    QString file_name;  //文件名
    int file_size,blocks;   //文件大小 块的数量
    QFile *file;
    QByteArray MD5;
    int type;//1上传检测 2允许上传 3文件重复
    int sending_block=1;    //正在发送的块的序号 序号从一开始
    QByteArray buffer;      //暂存正在发送块
};
class fileD{    //下载文件结构体
public:
    QString file_name,file_path;    //文件名 文件路径
    int blocks,file_size;
    bool *arrived;                  //已经到达的块
    QVector<QByteArray> bs;         //缓存已经收到的块
    QByteArray MD5;
};
class file_status{          //文件传输进度
public:
    int size;               //已有的传输记录
    int blocks,excuted_blocks=0;    //该记录块总数和已经上传/下载的块数
    QString file_name;
    int type;//1上传 0下载
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void share_in_session(QString user_name);

public slots:
    void read_from_socket();//从socket读信息并处理
private slots:
    void on_pushButton_6_clicked(); //切换至目录页
    void on_pushButton_5_clicked(); //切换至传输信息页
    void on_Button_logout_clicked(); //点击登出槽函数
    void on_upload_clicked();       //点击上传槽函数
    void on_download_clicked();     //点击下载槽函数
    void on_fresh_clicked();        //点击刷新槽函数 暂时隐藏
    void on_share_clicked();        //点击刷新槽函数
    void on_session_clicked();      //点击开启会话
    void on_shareCancel_clicked(); //取消分享
    void on_shareConfirm_clicked();//确认分享
    void on_StartChat_clicked(); //开启会话

private:
    Ui::Widget *ui;
    QTcpSocket *socket; //连接服务器
    QString user_name;  //保存当前登录的用户名
    QVector<fileU> files_U; //要上传的文件
    int task_num=0,processed_cur=0;//目前有的上传任务数 执行中的任务编号
    int process_lock=1; //保证只有一个线程进入process函数的锁
    int block_sent=0;   //当前块是否已经发送 避免重复发送同一个块
    QVector<fileD> files_D; //保存下载文件的信息
    int task_num_D=0;   //下载文件的任务数
    QVector<int> file_size; //保存文件的字节数
    QByteArray buffer;  //下载文件 如果读到的字节流没有报文边界 则保存在buffer中
    int has_buffer=0;   //buffer是否有效
    QVector<file_status> status;    //保存文件的传输记录
    int status_up_cur=-1,status_down_cur=-1;    //记录最近的上传/下载任务编号
    QTimer status_timer;    //定时器 定时更新传输状态信息
    void try_login();			//尝试登录
    void try_register();		//尝试注册
    void process_file();        //发送文件
    void check_byte(QByteArray &a); //检测收到的字节流中是否存在文件块
    void send_to_socket(QString &str);
    void upload_bytes(QByteArray &a);   //将收到字节流中的文件暂存到file的bs中
    void fresh_status();
    void seek_next_up_cur();    //处理重复文件的问题
    void show_cur_w();
    QString Cur_Target;
    MainWindow* cur_w;
};
#endif
