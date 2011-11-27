#include "testuecepmgr.h"

testUEcepMgr::testUEcepMgr(QObject *parent) :
    QObject(parent)
{
    NetConnector *net = new NetConnector(this);
    net->connectToServ ();
    DataTrans *dt = new DataTrans(net);
    UExcepMgr *uemgr = new UExcepMgr(this);
    uemgr->setDatacntr (dt);
    connect    (this,SIGNAL(hasExc(QString*,uint)),uemgr,SLOT(rec_excep(QString*,uint)));
}

void testUEcepMgr::start ()
{
    //testing^
    QString title("Life is broken");
    QString abstract("my life is so happy!n");
    QString detailDes("for many days ,my life is happy");
    QString reason("Ihave a good girl friend");
    QString action("dance everyday");
    QString handlerId("0943111258");
    QString handlerName("lv hao");
    QString time("2011/11/1");

    QString *content = new QString[8] ;
    int i=0;
    content[i++] = title;
    content[i++] = abstract;
    content[i++] = detailDes;
    content[i++] = reason;
    content[i++] = action;
    content[i++] = handlerId;
    content[i++] = handlerName;
    content[i++] = time;

    emit hasExc (content,i);
}
