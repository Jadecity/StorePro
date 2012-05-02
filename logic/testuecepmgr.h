#ifndef TESTUECEPMGR_H
#define TESTUECEPMGR_H

#include <QObject>
#include "net.h"
#include "dataIO.h"
#include "excepEvents.h"
using namespace Net;
using namespace DataIO;
using namespace WorkFlowExcep;
class testUEcepMgr : public QObject
{
    Q_OBJECT
public:
    explicit testUEcepMgr(QObject *parent = 0);
    void start();
signals:
    void hasExc(QString *content,uint);

public slots:

};

#endif // TESTUECEPMGR_H
