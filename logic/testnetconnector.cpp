#include "testnetconnector.h"
#include "logic/cmddef.h"
#include <iostream>
using namespace std;
testNetConnector::testNetConnector(QObject *parent) :
    QObject(parent)
{
}

void testNetConnector::startTest ()
{
    Net::NetConnector *nt = new Net::NetConnector();
    nt->connectToServ ();
    nt->chkstatus ();

    QByteArray d;
    QDataStream ds(&d,QIODevice::ReadWrite);
    ds<<CHECK<<LOGIN<<QByteArray("yubaohua")<<QByteArray("yubaohua");

    QByteArray d2;
    QDataStream ds2(&d2,QIODevice::ReadWrite);
    ds2<<d.size ();

    d = d2 + d;

    nt->write(d);
    if(nt->waitForReadyRead ())
    {
//        char buf[200] = {'\0'};
//        nt->read (buf,sizeof(buf));
//        cout<<buf<<endl;
//        string s = "I love you.";
//        int i = nt->write (s.data ());
//        cout<<i<<endl;
        QByteArray d;
        QDataStream ds(&d,QIODevice::ReadWrite);
        ds<<CHECK<<LOGIN<<QByteArray("yubaohua")<<QByteArray("yubaohua");

        QByteArray d2;
        QDataStream ds2(&d2,QIODevice::ReadWrite);
        ds2<<d.size ();

        d = d2 + d;

        nt->write(d);
//        cout << size<<endl;
    }
}
