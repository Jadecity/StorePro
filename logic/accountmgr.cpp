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
        ds>>status;
        if(!strcmp(status,C_USER))
        {
            emit dispInfo(data);
        }else if(!strcmp(status,AUTHOR))
        {
            emit disp(0);
        }else
        {
            emit dispInfo(data);
        }
    }else if(!strcmp(status,OK))
    {
        if(!strcmp(status,C_USER))
        {
            emit dispInfo(data);
        }else if(!strcmp(status,AUTHOR))
        {
            emit disp(1);
        }else if(!strcmp(status,USERS))
        {
            QStringList userlist;
            emit dispUsers(userlist);
        }else
        {
            emit dispInfo(data);
        }
    }
}

void AccountMgr::setDatacntr (DataTrans *dc)
{
    if(NULL != dc)
    datacntr = dc;
}

void AccountMgr::createAccount(QStringList list)
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<HANDIN<<C_USER<<list.at(0).toUtf8()<<list.at(1).toUtf8();

    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();

    cmd = temp + cmd;

    datacntr->request (this,cmd);
}

void AccountMgr::changePasswd(QStringList passwds)
{
    extern QString currentUser;
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<HANDIN<<PASSWORD<<currentUser.toUtf8()<<passwds.at(0).toUtf8()<<passwds.at(1).toUtf8();

    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();

    cmd = temp + cmd;

    datacntr->request (this,cmd);
}

void AccountMgr::getUsers()
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<GET<<USERS;

    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();

    cmd = temp + cmd;

    datacntr->request (this,cmd);
}

void AccountMgr::delUsers(QStringList mylist)
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<HANDIN<<D_USERS<<mylist.count();
    for(int i=0;i<mylist.count();i++)
    {
        ds<<mylist.at(i).toUtf8();
    }

    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();

    cmd = temp + cmd;

    datacntr->request (this,cmd);
}
