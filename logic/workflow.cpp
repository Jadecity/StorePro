#include "workFlow.h"
using namespace WorkFlow;
WorkFlowMgr::WorkFlowMgr(QObject *parent)
{

}
WorkFlowMgr::~WorkFlowMgr ()
{

}

void WorkFlowMgr::recv (QByteArray data)
{
    QDataStream ds(&data,QIODevice::ReadWrite);
    char *str;
    ds>>str;
    int amount=0;
    if(!strcmp (str,NOTHING))
    {
        ds>>str;
        QByteArray info;
        ds>>info;
        emit post2ui (0,info);
    }
    else if(!strcmp(str,OK))
    {
        ds>>str;
        ds>>amount;
        QByteArray res;
        res.append((char)amount);
        emit post2ui (1,res);
    }
}

void WorkFlowMgr::sendTables (QByteArray data,int flag)
{
    QByteArray cmd;
    QByteArray temp;
    QDataStream ds1(&cmd,QIODevice::ReadWrite);
    QDataStream ds2(&temp,QIODevice::ReadWrite);

    switch(flag)
    {
    case 1:
        ds1<<HANDIN<<INPUTTABLE;
        break;
    case 2:
        ds1<<HANDIN<<OUTPUTTABLE;
        break;
    case 3:
        ds1<<HANDIN<<CHECKTABLE;
        break;
    }
    cmd += data;

    ds2<<cmd.size ();
    cmd = temp + cmd;

    datacntr->request (this,cmd);
}

void WorkFlowMgr::setDatacntr (DataTrans *dc)
{
    if(NULL != dc)
    {
        this->datacntr = dc;
    }
}
