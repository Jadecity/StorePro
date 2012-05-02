#include "storageMgr.h"
#include <QList>

using namespace StorageMgr;

PosiMgr::PosiMgr()
{
    datacntr = NULL;
}
/*
double PosiMgr::ocurate ()
{
    //还没想好怎么写
     //to be modified
}
*/
void PosiMgr::setPosi(int x, int y)
{
    position = qMakePair(x,y);
}

void PosiMgr::getPoso (int *x, int *y)
{
    *x = position.first;
    *y = position.second;
}


void PosiMgr::dispException (QString &msg)
{
    //to be modified
}

void PosiMgr::recv (QByteArray data)
{
    //do analysis and call reflective methods
    QDataStream ds(&data,QIODevice::ReadOnly);
    char *temp;
    ds>>temp;
    if(!strcmp (temp,NOTHING))/*reply flag is indicated to find nothing of that action*/
    {
        QString msg("抱歉，没有找到任何您需要的数据！");
        dispException(msg);
        return;
    }
    else
    {
        ds>>temp;
        if(!strcmp (temp,POSI_INFO))/*reply is position info*/
        {
            /*
             *get all data from source and build a struct PosiInfo
             */
            QList<PosiInfo> *thislist = new QList<PosiInfo>;

            int numOfRec = 0;
            ds>>numOfRec;
            for(int i=0;i<numOfRec;i++)
            {
                PosiInfo info;
               char *s ;
               ds>>s;
               info.goodname = QString::fromUtf8 (s);
//               ds>>info.toStay;
               ds>>info.price;
               ds>>info.amount;

               ds>>s;
               info.unit = QString::fromUtf8 (s);
               ds>>s;
               info.owner = QString::fromUtf8 (s);
               ds>>s;
               info.arrivetime = QString::fromUtf8 (s);
               thislist->push_back (info);
            }

            //PosiInfo info;
            emit post2ui(thislist);
        }else if(!strcmp (temp,GOOD_INFO))/*reply is good info*/
        {
            QList<GoodInfo> *thislist = new QList<GoodInfo>;

            int numOfgood;
            ds>>numOfgood;
            for(int i=0;i<numOfgood;i++)
            {
                GoodInfo info;
                char *s;
                ds>>s;
                info.name = QString::fromUtf8 (s);
//              ds>>info.toStay;

                ds>>info.posi[0]>>info.posi[1];

                ds>>info.price>>info.amount;
                ds>>s;
                info.unit = QString::fromUtf8 (s);
                ds>>s;
                info.owner = QString::fromUtf8 (s);
                ds>>s;
                info.arriveTime = QString::fromUtf8 (s);

                thislist->push_back (info);
            }

            //GoodInfo info;
            emit post2ui (thislist);
        }
    }
}

void PosiMgr::setDatacntr (DataTrans *dc)
{
    if(dc!=NULL)
      this->datacntr = dc;
}

void PosiMgr::lookUpGood(int *posi)
{
    if(posi != NULL)
    {
         setPosi (posi[0],posi[1]);
         //build command
         QByteArray cmd;
         QDataStream ds(&cmd,QIODevice::ReadWrite);
         ds<<GET<<POSI_INFO<<position.first<<position.second;
         QByteArray temp;
         QDataStream ds2(&temp,QIODevice::ReadWrite);
         ds2<<cmd.size ();
         cmd = temp + cmd;

         datacntr->request (this,cmd);
    }
}
//info包含了四个数据，依次是name,no,datefrom,dateto
void PosiMgr::lookUpGood (QString *info)
{
    //build command
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<GET<<GOOD_INFO;
    ds<<info[0].toUtf8 ();
    ds<<info[1].toUtf8 ();
    ds<<info[2].toUtf8 ();
    ds<<info[3].toUtf8 ();
    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();
    cmd = temp + cmd;

    datacntr->request (this,cmd);
}


/*
 *第二个类DiaryMgr
*/
DiaryMgr::DiaryMgr(QObject *parent)
{

}

void DiaryMgr::upload (QString *diary, int itemNo)
{
    if(NULL == diary||itemNo!= DIARY_STRUCT_SIZE)
    {
        return;
    }
    else
    {
        Diary oneDiary;
        int i = 0;
        oneDiary.title = diary[i++];
        oneDiary.content =  diary[i++];
        oneDiary.date = diary[i++];
        oneDiary.writerName = diary[i++];

        QByteArray cmd = buildcmd (&oneDiary);
        datacntr->request (this,cmd);
    }
}

QByteArray DiaryMgr::buildcmd (Diary *content)
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<HANDIN<<DIARY<<content->title.toUtf8 ()<<content->content.toUtf8 ()<<content->date.toUtf8 ()<<content->writerName.toUtf8 ();

    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();

    cmd = temp + cmd;
    return cmd;
}
void DiaryMgr::setDatacntr (DataTrans *dc)
{
    this->datacntr = dc;
}
void DiaryMgr::recv (QByteArray data)
{
    QByteArray &status = data;
    QDataStream ds(&status,QIODevice::ReadWrite);
    char *str;
    ds>>str;
    if(!strcmp (str,NOTHING))
    {
        ds>>str;
        QByteArray reason;
        ds>>reason;
        emit dispStatus(reason);
        return;
    }

    ds>>str;
    if(!strcmp(str,DIARY))
    {
        emit dispStatus(QString("完成").toUtf8 ());
    }else if(!strcmp (str,DIARIES))
    {
        QList<Diary> *diaryList = new QList<Diary>;
        /*
         *read data to build many diaries whose content is empty
         *and put them to the list,realise this later
        */
        int num;
        ds>>num;
        Diary temp;
        for(int i=0;i<num;i++)
        {
            QByteArray arr;
            ds>>arr;
            temp.title = QString::fromUtf8 (arr.data ());
            ds>>arr;
            temp.content = QString::fromUtf8 (arr.data ());
            ds>>arr;
            temp.date = QString::fromUtf8 (arr.data ());
            ds>>arr;
            temp.writerName = QString::fromUtf8 (arr.data ());
            diaryList->push_back (temp);
        }
        emit dispDiaList (diaryList);
    }else if(!strcmp(str,DIA_CON))
    {
        QByteArray content;
        ds>>content;
        emit dispDiaContent (content);
    }
}

void DiaryMgr::checkDiary ()
{
    /*
     *for debug and I will realise it later
    */
#ifdef DEBUG
    QString datefrom = "2011-1-1";
    QString dateto = "2011-12-12";
    diaries (datefrom,dateto);
#endif
}

void DiaryMgr::diaries (QString datefrom, QString dateto)
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<GET<<DIARIES<<datefrom.toUtf8 ()<<dateto.toUtf8 ();
    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();

    cmd = temp + cmd;

    datacntr->request (this,cmd);
}

void DiaryMgr::fetchContent (QString date)
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<GET<<DIA_CON<<date.toUtf8 ();
    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();

    cmd = temp + cmd;

    datacntr->request (this,cmd);
}
