#include"dataIO.h"
#include"upcntrbase.h"
#include<QByteArray>
#include<QDataStream>
using namespace DataIO;

#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

DataTrans::DataTrans():IOBase()
{
    net = NULL;
}

DataTrans::DataTrans(Net::NetConnector *net):
        IOBase()
{
   this->setNet (net);
}

void DataTrans::request (UpCntrBase *caller,QByteArray &cmd)
{
    if(NULL != caller)
    {
        msgOwner.enqueue (caller);
        net->write(cmd);
    }
}

void DataTrans::handIn()
{

   UpCntrBase *owner = msgOwner.dequeue ();
    owner->recv(databuf);
    databuf.clear ();
}

int  DataTrans::setNet (Net::NetConnector *_net)
{
    if(NULL == _net)
        return -1;
    else
    {
        this->net = _net;
        connect (net,SIGNAL(readyRead()),this,SLOT(readData()));
        return 0;
    }
}

void DataTrans::readData ()
{
    static int totalSize = 0;
    static int curSize = 0;
    static int flag = 1;
    QByteArray temp = net->read (1024);
    QDataStream dstemp(&temp,QIODevice::ReadOnly);
    QByteArray test;
    dstemp>>test;
    QString str = QString::fromUtf8 (test.data ());

    QByteArray tp = temp;
    if(1 == flag)
    {
        QDataStream ds(&tp,QIODevice::ReadWrite);
        ds>>totalSize;
        char *str1;
        char *str2;
        ds>>str1>>str2;
        temp = temp.remove (0,4);
        tp = tp.remove (0,strlen (str1) + strlen(str2) + 2 + 12);
        flag = 0;

        curSize += tp.size ();

    }else if(0 == flag)
    {
        curSize += temp.size ();
    }

    databuf += temp;

    if(curSize == totalSize)
    {
        totalSize = 0;
        curSize = 0;
        flag = 1;
        handIn ();
    }
}
