#include "testdiary.h"

testDiary::testDiary(QObject *parent) :
    QObject(parent)
{
    NetConnector *net = new NetConnector(this);
    net->connectToServ ();
    DataTrans *dt = new DataTrans(net);
    dmgr = new DiaryMgr(this);
    dmgr->setDatacntr (dt);
    connect (this,SIGNAL(goUpload(QString*,int)),dmgr,SLOT(upload(QString*,int)));
    connect(this,SIGNAL(goCheckDiary()),dmgr,SLOT(checkDiary()));
    connect(this,SIGNAL(goFetchContent(QString)),dmgr,SLOT(fetchContent(QString)));
}

void testDiary::start ()
{
    tstDiary ();
    tstDiaries ();
    tstContent ();
}

void testDiary::tstDiary ()
{
    QString *diary = new QString[DIARY_STRUCT_SIZE];
    int i=0;
    QString title("this is a diary");
    QString content("wo cao le ,mei renxing a ");
    QString date("2011-1-5");
    QString writerName("lv hao");
    QString writerId("0943111258");

    diary[i++] = title;
    diary[i++] = content ;
    diary[i++] = date;
    diary[i++] = writerName;
    diary[i++] = writerId;

    emit goUpload (diary,DIARY_STRUCT_SIZE);
}
void testDiary::tstDiaries ()
{
    emit goCheckDiary ();
}
void testDiary::tstContent ()
{
    QString date("2011-9-10");
    emit goFetchContent (date);
}
