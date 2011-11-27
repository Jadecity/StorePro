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
    /*��ʼ��UI����*/
    void initUI();
    /*��ʼ���߼������������������*/
    void initLogic();
    /*���������򣬴����￪ʼ������ʽ��ʾ���û�*/
    void start();
signals:

public slots:
    /*this is to handle asking good info by position
      *given a candidate x-y,and the pointer is the widgets to disp
      * content
      */
    void goodInfoHandler(StoreMap*,int,int);

    /*һ������������ɺ�ɾ�����������������*/
    void cleanObj();
private:
    QQueue<QObject *> queue;
};

#endif // CLIENT_H
