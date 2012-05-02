#ifndef NET_H
#define NET_H

#include <QTcpSocket>
#include<QHostAddress>
#include<QtGlobal>

//#define DEFADDR "127.0.0.1"
#define DEFADDR "192.168.12.2"
#define DEFPORT 8888
namespace Net
{
    class NetConnector:public QTcpSocket
    {
        Q_OBJECT
    private:
        QHostAddress* addr;
        quint16 port;
        bool status;//标志网络状态，链接/断开
    public:
        NetConnector(QObject * parent = 0);
        NetConnector(const QHostAddress &addr, quint16 port);
        //new methods
        //return value:1 表示重连成功，0 表示重连失败
        int reconnect();
        bool chkstatus();
        void connectToServ();
    };
}
#endif // NET_H
