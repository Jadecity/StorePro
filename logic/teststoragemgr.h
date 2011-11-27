#ifndef TESTSTORAGEMGR_H
#define TESTSTORAGEMGR_H

//#define TEST_POSI
#define TEST_NAME
#include <QObject>
#include"storageMgr.h"
using namespace StorageMgr;
class teststorageMgr : public QObject
{
    Q_OBJECT
public:
    explicit teststorageMgr(QObject *parent = 0);
   void  start();
signals:
    void needInfo(int *);
    void needInfo (QString name);
public slots:

};

#endif // TESTSTORAGEMGR_H
