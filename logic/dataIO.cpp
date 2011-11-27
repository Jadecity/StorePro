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
    /*
    *connect(this,SIGNAL(dataReady()),SLOT(handIn()));
    */
}

DataTrans::DataTrans(Net::NetConnector *net):
        IOBase()
{
   this->setNet (net);
}

void DataTrans::request (UpCntrBase *caller,QByteArray &cmd)
{
    net->write(cmd);
    msgOwner.enqueue (caller);
}

void DataTrans::handIn()
{

   UpCntrBase *owner = msgOwner.dequeue ();
    owner->recv(databuf);
    databuf.clear ();
}

int  DataTrans::setNet (Net::NetConnector *net)
{
    if(NULL == net)
        return -1;
    else
    {
        this->net = net;
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

    if(1 == flag)
    {
        QDataStream ds(&temp,QIODevice::ReadWrite);
        ds>>totalSize;
        temp = temp.remove (0,4);
        flag = 0;
    }

    curSize += temp.size ();
    databuf += temp;

    if(curSize == totalSize)
    {
        totalSize = 0;
        curSize = 0;
        flag = 1;
        /*
        *emit dataReady();
        */
        handIn ();
    }
}
