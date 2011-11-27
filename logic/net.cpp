#include "net.h"
using namespace Net;


NetConnector::NetConnector(QObject *parent):status(false)
{
    addr = new QHostAddress(DEFADDR);
    port = DEFPORT;
}

NetConnector::NetConnector(const QHostAddress &addr, quint16 port):status(false)
{
    this->addr = new QHostAddress(addr);
    this->port = port;
}
//new methods
int NetConnector::reconnect ()
{
     this->connectToHost (*addr,port);
     if(waitForConnected (1000))
         return 1;
     else
         return 0;
}

bool NetConnector::chkstatus ()
{
    if(QAbstractSocket::ConnectedState == state ())
    {
        this->status = true;
    }else
    {
        this->status = false;
    }

    return status;
}

void NetConnector::connectToServ ()
{
    connectToHost (*addr,DEFPORT);
}

