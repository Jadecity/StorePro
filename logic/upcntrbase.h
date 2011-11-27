#ifndef UPCENBASE_H
#define UPCENBASE_H
#include"dataIO.h"
using namespace DataIO;
#include<QByteArray>
class UpCntrBase:public QObject
{
    Q_OBJECT
public:

    virtual void setDatacntr(DataTrans *dc){}
public slots:
     virtual void recv(QByteArray data){}
};
#endif // UPCENBASE_H
