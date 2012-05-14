#ifndef STATICS_H
#define STATICS_H

#include <QObject>
#include "dataIO.h"
using namespace DataIO;
#include "upcntrbase.h"
#include "cmddef.h"
#include "globalDataType.h"
namespace Statics
{
    class StaticCntr:public UpCntrBase
    {
        Q_OBJECT
    public:
        StaticCntr(QObject *parent=0);
        void setDatacntr(DataTrans *dc);
    public slots:
        //first check return data then
        //call different ui methods to display relative result in graph
        void recv(QByteArray data);
        void thisMonthThroughout();
        void predictNextMonthThroughout();
        void companyBusyDegree();
        void goodWastage();
        //get overtime goods amount
        //emit overTimeAmount(int) signal
        void overTime();
        //get details about over time goods
        //emit overTimedetails_s(QByteArray)
        void overTimeDetails();
    private:
        DataTrans *datacntr;
    signals:
        void disp(Throughout in_out);
        void disp(Wastage wst);
        void dispIncRank(QList<IncRank> *list);
        void overTimeAmount(int);
        void overTimeDetails_s(QByteArray);
    };
}
#endif // STATICS_H
