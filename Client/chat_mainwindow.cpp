#include "chat_mainwindow.h"
#include "ui_chat_mainwindow.h"

Chat_MainWindow::Chat_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chat_MainWindow)
{
    ui->setupUi(this);
}

Chat_MainWindow::~Chat_MainWindow()
{
    delete ui;
}
