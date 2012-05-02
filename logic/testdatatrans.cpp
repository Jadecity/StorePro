#include "testdatatrans.h"
#include <iostream>
#include<QDataStream>
using namespace std;
testDatatrans::testDatatrans(QObject *parent) :UpCntrBase()
{
    dt = new DataIO::DataTrans();
}

void testDatatrans::start ()
{
    NetConnector *net = new NetConnector();
    net ->connectToServ ();
    dt->setNet (net);
    QByteArray qb = QByteArray("cmd line");
    dt->request (this,qb);
}

void testDatatrans::recv (QByteArray data)
{
    QDataStream ds(data);
    char *s = NULL;
    ds>>s;
    cout<<s<<endl;
}
