#include "accountmgr.h"
#include <QStringList>

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
            QByteArray info;
            ds>>info;
            emit dispInfo(info);
        }else if(!strcmp(status,AUTHOR))
        {
            emit disp(0);
        }else
        {
            emit dispInfo(data);
        }
    }else if(!strcmp(status,OK))
    {
         ds>>status;
        if(!strcmp(status,C_USER))
        {
            emit dispInfo(data);
        }else if(!strcmp(status,LOGIN))
        {
            emit disp(1);
        }else if(!strcmp(status,USERS))
        {
            QStringList userlist;
            QByteArray mytemp;
            int count=0;
            ds>>count;
            for(int i=0;i<count;i++){
                ds>>mytemp;
                userlist.push_back(QString(mytemp));
            }

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
    ds<<HANDIN<<D_USERS;
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
