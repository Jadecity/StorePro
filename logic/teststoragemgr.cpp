#include "teststoragemgr.h"

teststorageMgr::teststorageMgr(QObject *parent) :
    QObject(parent)
{
    NetConnector *net = new NetConnector(this);
    net->connectToServ ();
    PosiMgr *mgr = new PosiMgr();
    DataTrans *dt = new DataTrans(net);
    mgr->setDatacntr (dt);
    connect (this,SIGNAL(needInfo(int*)),mgr,SLOT(lookUpGood(int*)));
    connect (this,SIGNAL(needInfo(QString)),mgr,SLOT(lookUpGood(QString)));
}

void teststorageMgr::start ()
{
#ifdef TEST_POSI
    int posi[2] = {3,4};
    emit needInfo (posi);
#endif
#ifdef TEST_NAME
    QString name("À¬»ø");
    emit needInfo (name);
#endif
}
