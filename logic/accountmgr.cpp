#include "accountmgr.h"

AccountMgr::AccountMgr(QObject *parent)
{

}


void AccountMgr::login(QByteArray info)
{
    datacntr->request (this,info);
}

void AccountMgr::logout()
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<LOGOUT;

    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();

    cmd = temp + cmd;

    datacntr->request (this,cmd);
}

void AccountMgr::recv(QByteArray data)
{
    QDataStream ds(&data,QIODevice::ReadOnly);
    char *status;
    ds>>status;
    if(!strcmp(status,NOTHING))
    {
        //do nothing
        emit disp(0);
    }else if(!strcmp(status,OK))
    {
        emit disp(1);
    }
}

void AccountMgr::setDatacntr (DataTrans *dc)
{
    if(NULL != dc)
    datacntr = dc;
}
