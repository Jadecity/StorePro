#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include<QQueue>
#include "mainwindow.h"
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    /*初始化UI部件*/
    void initUI();
    /*初始化逻辑部件，包括检测网络*/
    void initLogic();
    /*启动主程序，从这里开始程序正式显示给用户*/
    void start();
signals:

public slots:
    /*this is to handle asking good info by position
      *given a candidate x-y,and the pointer is the widgets to disp
      * content
      */
    void goodInfoHandler(StoreMap*,int,int);

    /*一个完整用例完成后删除创建的请求处理对象*/
    void cleanObj();
private:
    QQueue<QObject *> queue;
};

#endif // CLIENT_H
