#include "testnetconnector.h"

testNetConnector::testNetConnector(QObject *parent) :
    QObject(parent)
{
}

void testNetConnector::startTest ()
{
    Net::NetConnector *nt = new Net::NetConnector();
    nt->connectToServ ();
    if(nt->waitForReadyRead ())
    {
        char buf[200] = {'\0'};
        nt->read (buf,sizeof(buf));
        cout<<buf<<endl;
        string s = "I love you.";
        int i = nt->write (s.data ());
        cout<<i<<endl;
    }
}
