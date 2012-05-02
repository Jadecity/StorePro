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
    private:
        DataTrans *datacntr;
    signals:
        void disp(Throughout in_out);
        void disp(Wastage wst);
        void dispIncRank(QList<IncRank> *list);
    };
}
#endif // STATICS_H
