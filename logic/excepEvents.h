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
    public:
       explicit UExcepMgr(QObject *parent=0);
        void setDatacntr (DataTrans *dc);
    public slots:
        void rec_excep(QString *content,unsigned int itemNo=8);
        void recv (QByteArray data);
    signals:
//        把受到的数据交给UI
        void disp(QByteArray status);
    private:
        QByteArray buildcmd(ExcepRec *);
        DataTrans *datacntr;

    };
};
#endif // EXCEPEVENTS_H
