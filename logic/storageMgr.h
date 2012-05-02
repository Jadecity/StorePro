#ifndef STORAGEMGR_H
#define STORAGEMGR_H
#include<QPair>
#include<QObject>
#include <QList>
#include"dataIO.h"
#include"upcntrbase.h"
#include "cmddef.h"
#include "globalDataType.h"
#include<iostream>
using namespace std;
using namespace DataIO;

class QString;
namespace StorageMgr
{

    class PosiMgr:public UpCntrBase
    {
        Q_OBJECT

    public:
        PosiMgr();
       // double ocurate();货物空间占有率
        void setPosi(int x,int y);
        void getPoso(int *x,int *y);
        void setDatacntr (DataTrans *dc);

    private:
          void dispPosi(PosiInfo &info);
          void dispGood(GoodInfo &info);
          void dispException(QString &msg);
          QPair<int,int> position;
          DataTrans *datacntr;
    public slots:
        void lookUpGood(int *posi);
        //info包含了四个数据，依次是name,no,datefrom,dateto
        void lookUpGood (QString *info);
        void recv (QByteArray data);
    signals:
        //将受到的位置信息数据交给UI
        void post2ui(QList<PosiInfo> *);
        void post2ui(QList<GoodInfo> *);
    };

    class DiaryMgr:public UpCntrBase
    {
        Q_OBJECT
    public:
        DiaryMgr(QObject *parent = 0);
        void  diaries(QString datefrom,QString dateto);
        void setDatacntr (DataTrans *dc);
        QByteArray buildcmd(Diary *content);
    public slots:
        void upload(QString *diary,int itemNo = DIARY_STRUCT_SIZE);
       void checkDiary();
       void fetchContent(QString date);
       void recv (QByteArray data);
    private:
        DataTrans *datacntr;
    signals:
        void dispStatus(QByteArray status);
        void dispDiaList(QList<Diary> *list);
        void dispDiaContent(QByteArray content);
    };
}
#endif
