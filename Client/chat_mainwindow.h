#ifndef CHAT_MAINWINDOW_H
#define CHAT_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Chat_MainWindow;
}

class Chat_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chat_MainWindow(QWidget *parent = nullptr);
    ~Chat_MainWindow();

private:
    Ui::Chat_MainWindow *ui;
};

#endif // CHAT_MAINWINDOW_H
