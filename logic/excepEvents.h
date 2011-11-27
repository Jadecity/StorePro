#ifndef EXCEPEVENTS_H
#define EXCEPEVENTS_H

#include "upcntrbase.h"
#include "dataIO.h"
using namespace DataIO;
class QString;
namespace SysExcep
{

}
namespace DataIOExcep
{

}

namespace WorkFlowExcep
{
    struct ExcepRec
    {
        QString title;
        QString abstract;
        QString detailDes;
        QString reason;
        QString action;
        QString handlerId;
        QString handlerName;
        QString time;
    };

    class UExcepMgr:public UpCntrBase
    {
        Q_OBJECT
    private:
        DataTrans *datacntr;
    public:
        UExcepMgr(QObject *parent=0);
        void setDatacntr (DataTrans *dc);
    private:
        QByteArray buildcmd(ExcepRec *);
    public slots:
        void rec_excep(QString *content,unsigned int itemNo=0);
        void disp(QString msg);
        void recv (QByteArray data);
    };
};
#endif // EXCEPEVENTS_H
