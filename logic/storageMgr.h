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
    private:
        QPair<int,int> position;
        DataTrans *datacntr;
    public:
        PosiMgr();
       // double ocurate();货物空间占有率
        void setPosi(int x,int y);
        void getPoso(int *x,int *y);
        void setDatacntr (DataTrans *dc);
        /*
         *void registerUI();
         */
    private:
          void dispPosi(PosiInfo &info);
          void dispGood(GoodInfo &info);
          void dispException(QString &msg);
    public slots:
        void lookUpGood(int *posi);
 //info包含了四个数据，依次是name,no,datefrom,dateto
        void lookUpGood (QString *info);
        void recv (QByteArray data);
    };

    class DiaryMgr:public UpCntrBase
    {
        Q_OBJECT
    public:
        DiaryMgr(QObject *parent = 0);
        void  diaries(QString datefrom,QString dateto);
        QByteArray buildcmd(Diary *content);
        void setDatacntr (DataTrans *dc);
        void dispStatus(QByteArray &status);
        void dispDiaList(QList<Diary> &list);
        void dispDiaContent(QString &content);
    public slots:
        void upload(QString *diary,int itemNo = DIARY_STRUCT_SIZE);
       void checkDiary();
       void fetchContent(QString date);
       void recv (QByteArray data);
    private:
        DataTrans *datacntr;
    };
}
#endif
