#include "client.h"
#include "ui/askgoodtolookdlg.h"
#include "ui/diaryeditor.h"
#include "ui/diarydisp.h"
#include "ui/excepeditor.h"
#include "ui/lncrankdsp.h"
#include "ui/storemap.h"
#include "ui/throughoutdisp.h"
#include "ui/wastagedsp.h"
#include "ui/instore_table.h"
#include "ui/check_table.h"
#include "ui/outstore_table.h"

#include "logic/cmddef.h"
#include "logic/globalDataType.h"
#include "logic/statics.h"
#include "logic/storageMgr.h"
#include "logic/excepEvents.h"
#include "logic/accountmgr.h"
Client::Client(QObject *parent) :
    QObject(parent),
    queue(NULL),
    net(NULL),
    datacntr(NULL),
    mwnd(NULL)
{
    initUI ();
    initLogic ();
}

void Client::initUI ()
{
    mwnd = new MainWindow;
    //初始化主窗口连接
    if(NULL != mwnd)
    {
        connect (mwnd,SIGNAL(reqstGoodInfo(StoreMap*,int,int)),this,SLOT(reqstGoodInfoHandler(StoreMap*,int,int)));
        connect (mwnd,SIGNAL(query_good_info(AskGoodToLookDlg*,QString*)),this,SLOT(query_good_infoHandler(AskGoodToLookDlg*,QString*)));
        connect (mwnd,SIGNAL(handin_excep(ExcepEditor*,QString*)),this,SLOT(handin_excep(ExcepEditor*,QString*)));
        connect (mwnd,SIGNAL(handinDiary(DiaryEditor*,QString*)),this,SLOT(handinDiaryHandler(DiaryEditor*,QString*)));

        connect (mwnd,SIGNAL(diaryHistory(DiaryDisp*,QString,QString)),this,SLOT(diaryHistoryHandler(DiaryDisp*,QString,QString)));
        connect (mwnd,SIGNAL(mthrough(ThroughoutDisp*)),this,SLOT(mthroughHandler(ThroughoutDisp*)));
        connect (mwnd,SIGNAL(nxmthrough(ThroughoutDisp*)),this,SLOT(nxmthroughHandler(ThroughoutDisp*)));
        connect (mwnd,SIGNAL(wastage(WastageDsp*)),this,SLOT(wastageHandler(WastageDsp*)));
        connect (mwnd,SIGNAL(lncRank(LncRankDsp*)),this,SLOT(lncRankHandler(LncRankDsp*)));
        connect (mwnd,SIGNAL(authorise(QByteArray)),this,SLOT(authoriseHandler(QByteArray)));
        connect (mwnd,SIGNAL(logout()),this,SLOT(logoutHandler()));
        connect (mwnd,SIGNAL(curStore(StoreStatusDsp*)),this,SLOT(curStoreHandler(StoreStatusDsp*)));
        connect (mwnd,SIGNAL(actionFinish()),this,SLOT(cleanObj()));

        connect (mwnd,SIGNAL(instore_signal(Instore_table*,QByteArray)),this,SLOT(instoreHandler(Instore_table*,QByteArray)));

        connect (mwnd,SIGNAL(send_chk_table(Check_table*,QByteArray)),SLOT(chk_goodHandler(Check_table*,QByteArray)));
        connect(mwnd,SIGNAL(outstore_signal(Outstore_table*,QByteArray)),this,SLOT(outstoreHandler(Outstore_table*,QByteArray)));
       // connect (mwnd,SIGNAL(destroyed()),this,SLOT(quit()));
        connect(mwnd,SIGNAL(getOverTime()),SLOT(overTimeHandler()));
        connect(mwnd,SIGNAL(callClientTimeEvent()),SLOT(startMyTimer()));

        connect(mwnd,SIGNAL(createAccount(CreateUserWnd*)),SLOT(createAccountHandler(CreateUserWnd*)));
        connect(mwnd,SIGNAL(changePasswd(ChangePasswdWnd*)),SLOT(passwordHandler(ChangePasswdWnd*)));
        connect(mwnd,SIGNAL(getUsers(DelUserWnd*)),SLOT(getUserHandler(DelUserWnd*)));
        connect(mwnd,SIGNAL(delUsers(DelUserWnd*)),SLOT(delUsersHandler(DelUserWnd*)));
    }
}

void Client::initLogic ()
{
    queue = new QQueue<QObject *>;
    net = new NetConnector(this);
    datacntr = new DataIO::DataTrans(net);
}

void Client::start ()
{
    mwnd->show ();
}

void Client::reqstGoodInfoHandler (StoreMap *map, int x, int y)
{
    //    假设每次都能连接成功
    this->net->connectToServ ();
    StorageMgr::PosiMgr *posimgr = new StorageMgr::PosiMgr;
    posimgr->setDatacntr (datacntr);
    queue->enqueue (posimgr);
    connect (posimgr,SIGNAL(post2ui(QList<PosiInfo>*)),map,SLOT(rcvData(QList<PosiInfo>*)));

    int posi[] = {x,y};
    posimgr->lookUpGood (posi);
}

void Client::query_good_infoHandler (AskGoodToLookDlg *dlg, QString *data)
{
    //    假设每次都能连接成功
    this->net->connectToServ ();

     StorageMgr::PosiMgr *posimgr = new StorageMgr::PosiMgr;
     posimgr->setDatacntr (this->datacntr);
     queue->enqueue (posimgr);
     connect (posimgr,SIGNAL(post2ui(QList<GoodInfo>*)),dlg,SLOT(rcvData(QList<GoodInfo>*)));

     posimgr->lookUpGood (data);
}

void Client::handin_excep (ExcepEditor *except, QString *info)
{
    //    假设每次都能连接成功
        this->net->connectToServ ();

    WorkFlowExcep::UExcepMgr *ue = new WorkFlowExcep::UExcepMgr;
    ue->setDatacntr (this->datacntr);
    queue->enqueue (ue);
    connect (ue,SIGNAL(disp(QByteArray)),except,SLOT(rcvData(QByteArray)));

    ue->rec_excep (info);
}

void Client::handinDiaryHandler (DiaryEditor *de, QString *info)
{
    //    假设每次都能连接成功
    // to del
        this->net->connectToServ ();

    StorageMgr::DiaryMgr *diarymgr = new StorageMgr::DiaryMgr;
    diarymgr->setDatacntr (this->datacntr);
    queue->enqueue (diarymgr);
    connect(diarymgr,SIGNAL(dispStatus(QByteArray)),de,SLOT(rcvData(QByteArray)));

    diarymgr->upload (info);
}

void Client::diaryHistoryHandler (DiaryDisp *displayer,QString dateFrom,QString dateTo)
{
    //    假设每次都能连接成功
    // to del
        this->net->connectToServ ();

     StorageMgr::DiaryMgr *diarymgr = new StorageMgr::DiaryMgr;
     diarymgr->setDatacntr (this->datacntr);
     queue->enqueue (diarymgr);

     connect (diarymgr,SIGNAL(dispDiaList(QList<Diary>*)),displayer,SLOT(rcvData(QList<Diary>*)));
     diarymgr->diaries (dateFrom,dateTo);
}

void Client::mthroughHandler (ThroughoutDisp *dsper)
{
    //    假设每次都能连接成功
    // to del
        this->net->connectToServ ();
    Statics::StaticCntr *staticModule = new Statics::StaticCntr;
    staticModule->setDatacntr (this->datacntr);
    queue->enqueue (staticModule);
    connect (staticModule,SIGNAL(disp(Throughout)),dsper,SLOT(rcvData(Throughout)));

    staticModule->thisMonthThroughout ();
}

void Client::nxmthroughHandler (ThroughoutDisp *dsper)
{
    //    假设每次都能连接成功
    // to del
        this->net->connectToServ ();

    Statics::StaticCntr *staticModule = new Statics::StaticCntr;
    staticModule->setDatacntr (this->datacntr);
    queue->enqueue (staticModule);
    connect (staticModule,SIGNAL(disp(Throughout)),dsper,SLOT(rcvData(Throughout)));

    staticModule->predictNextMonthThroughout ();
}

void Client::wastageHandler (WastageDsp *dsper)
{
    //    假设每次都能连接成功
    // to del
        this->net->connectToServ ();

    Statics::StaticCntr *staticModule = new Statics::StaticCntr;
    staticModule->setDatacntr (this->datacntr);
    queue->enqueue (staticModule);
    connect (staticModule,SIGNAL(disp(Wastage)),dsper,SLOT(rcvData(Wastage)));

    staticModule->goodWastage ();
}

void Client::lncRankHandler (LncRankDsp *lncDsp)
{
    //    假设每次都能连接成功
    // to del
        this->net->connectToServ ();

    Statics::StaticCntr *staticModule = new Statics::StaticCntr;
    staticModule->setDatacntr (this->datacntr);
    queue->enqueue (staticModule);
    connect (staticModule,SIGNAL(dispIncRank(QList<IncRank>*)),lncDsp,SLOT(rcvData(QList<IncRank> *)));

    staticModule->companyBusyDegree ();
}

void Client::authoriseHandler (QByteArray auth_info)
{
//    假设每次都能连接成功
    this->net->connectToServ ();

    QDataStream ds(&auth_info,QIODevice::ReadOnly);
    QByteArray name,passwd,cmd;
    ds>>name>>passwd;
    QDataStream dsout(&cmd,QIODevice::ReadWrite);
    dsout<<CHECK<<LOGIN<<name<<passwd;

    QByteArray tmp;
    QDataStream ds2(&tmp,QIODevice::WriteOnly);
    ds2<<cmd.size ();

    cmd = tmp+cmd;

    AccountMgr *mgr = new AccountMgr;
    mgr->setDatacntr (this->datacntr);
    queue->enqueue (mgr);
    connect (mgr,SIGNAL(disp(int)),mwnd,SLOT(rcvAuthorise(int)));

    mgr->login (cmd);
}

void Client::logoutHandler ()
{
    AccountMgr *mgr = new AccountMgr;
    mgr->setDatacntr (datacntr);
    queue->enqueue (mgr);

    mgr->logout ();

    this->quit ();
}

void Client::curStoreHandler (StoreStatusDsp *)
{

}

void Client::instoreHandler (Instore_table *table, QByteArray data)
{
    //    假设每次都能连接成功
        this->net->connectToServ ();

    WorkFlow::WorkFlowMgr *wkflow = new WorkFlow::WorkFlowMgr;
    wkflow->setDatacntr (this->datacntr);
    queue->enqueue (wkflow);

    connect(wkflow,SIGNAL(post2ui(int,QByteArray)),table,SLOT(dispstatus(int,QByteArray)));
    wkflow->sendTables (data,1);
}

void Client::outstoreHandler (Outstore_table *table, QByteArray data)
{
    //    假设每次都能连接成功
        this->net->connectToServ ();

    WorkFlow::WorkFlowMgr *wkflow = new WorkFlow::WorkFlowMgr;
    wkflow->setDatacntr (this->datacntr);
    queue->enqueue (wkflow);

    connect(wkflow,SIGNAL(post2ui(int,QByteArray)),table,SLOT(dispstatus(int,QByteArray)));
    wkflow->sendTables (data,2);
}

void Client::chk_goodHandler (Check_table *table, QByteArray data)
{
//    假设每次都能连接成功
    this->net->connectToServ ();
    WorkFlow::WorkFlowMgr *wkflow = new WorkFlow::WorkFlowMgr;
    wkflow->setDatacntr (this->datacntr);
    queue->enqueue (wkflow);

    connect(wkflow,SIGNAL(post2ui(int,QByteArray)),table,SLOT(dispstatus(int,QByteArray)));
    wkflow->sendTables (data,3);
}

void Client::cleanObj ()
{
    while(!queue->isEmpty ())
    {
        QObject *todel = queue->dequeue ();
        todel->disconnect ();
        delete todel;
        todel = NULL;
    }
}

void Client::quit ()
{
    delete queue;
    net->disconnectFromHost ();
    delete net;
    delete datacntr;
    mwnd->close ();
    delete mwnd;
}

void Client::timerEvent(QTimerEvent *event)
{
//    //向服务器发送请求，请求超时商品数量
//    static int counter = 0;
//    if(counter%5 == 0&&counter != 0)
//    {
//        counter = 0;
        Statics::StaticCntr *staticModule = new Statics::StaticCntr;
        staticModule->setDatacntr (this->datacntr);
        queue->enqueue (staticModule);
        connect (staticModule,SIGNAL(overTimeAmount(int)),mwnd,SLOT(showOverTime(int)));

        staticModule->overTime();
//    }else
//    {
//        counter++;
//    }

}

void Client::overTimeHandler()
{
    Statics::StaticCntr *staticModule = new Statics::StaticCntr;
    staticModule->setDatacntr (this->datacntr);
    queue->enqueue (staticModule);
    connect (staticModule,SIGNAL(overTimeDetails_s(QByteArray)),mwnd,SLOT(showOverTimeDetails(QByteArray)));

    staticModule->overTimeDetails();
}

void Client::startMyTimer()
{
    startTimer(2000);
}

void Client::createAccountHandler(CreateUserWnd *window_pointer)
{
    AccountMgr *mgr = new AccountMgr;
    mgr->setDatacntr (this->datacntr);
    queue->enqueue (mgr);
    connect (mgr,SIGNAL(dispInfo(QByteArray)),window_pointer,SLOT(dispInfo(QByteArray)));
//  Get all info from UI and call AccountMgr to
//  create an account
    QStringList userinfo;
    userinfo.push_back(window_pointer->getName());
    userinfo.push_back(window_pointer->getPasswd());
    mgr->createAccount (userinfo);
}

void Client::passwordHandler(ChangePasswdWnd *window_pointer)
{
    AccountMgr *mgr = new AccountMgr;
    mgr->setDatacntr (this->datacntr);
    queue->enqueue (mgr);
    connect (mgr,SIGNAL(dispInfo(QByteArray)),window_pointer,SLOT(dispInfo(QByteArray)));
//  Get all info from UI and call AccountMgr to
//  create an account
    QStringList passwords;
    mgr-> changePasswd(passwords);
}

void Client::getUserHandler(DelUserWnd *window_pointer)
{
    AccountMgr *mgr = new AccountMgr;
    mgr->setDatacntr (this->datacntr);
    queue->enqueue (mgr);
    connect (mgr,SIGNAL(dispUser(QStringList)),window_pointer,SLOT(dispUser(QStringList)));
//  Get all info from UI and call AccountMgr to
//  create an account
    mgr-> getUsers();
}

void Client::delUsersHandler(DelUserWnd *window_pointer)
{
    AccountMgr *mgr = new AccountMgr;
    mgr->setDatacntr (this->datacntr);
    queue->enqueue (mgr);
    connect (mgr,SIGNAL(dispInfo(QByteArray)),window_pointer,SLOT(dispInfo(QByteArray)));
//  Get all info from UI and call AccountMgr to
//  create an account
    QStringList userlist;
    mgr->delUsers(userlist);
}
