#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "askgoodtolookdlg.h"
#include "diaryeditor.h"
#include "excepeditor.h"
#include "goodinfodisplayer.h"
#include "lncrankdsp.h"
#include "storemap.h"
#include "storestatusdsp.h"
#include "throughoutdisp.h"
#include "wastagedsp.h"
#include "diarydisp.h"
#include "login_ui.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    login(NULL)
{
    ui->setupUi(this);
    disable_all ();
    enable_all ();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//新建一个标签，用于输入坐标，然后显示在主窗口中
void MainWindow::on_lookGoodByPosi_triggered()
{
    StoreMap *map =  new StoreMap(this);
    ui->tabWidget->addTab (map,QString(tr("地图")));
    ui->tabWidget->setCurrentWidget (map);
    connect(map,SIGNAL(fetch(StoreMap*,int,int)),this,SIGNAL(reqstGoodInfo(StoreMap*,int,int)));
}

//新建一个标签，用于输入货物信息，然后显示在主窗口中
void MainWindow::on_lookGoodByInfo_triggered()
{
    AskGoodToLookDlg *dlg = new AskGoodToLookDlg(this);
    ui->tabWidget->addTab (dlg,QString(tr("货物信息输入")));
    ui->tabWidget->setCurrentWidget (dlg);
    connect (dlg,SIGNAL(query_good_info(AskGoodToLookDlg*,QString*)),this,SIGNAL(query_good_info(AskGoodToLookDlg*,QString*)));
}

//当标签关闭，就删除
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    /*delete widget if the tab is closed*/
    QWidget *toRm = ui->tabWidget->widget (index);
    ui->tabWidget->removeTab (index);
    toRm->disconnect ();
    delete toRm;
    toRm = NULL;
//    删除对象后告诉外部删除临时对象
    emit actionFinish ();
}
//新建标签，输入异常信息
void MainWindow::on_recExcepAct_triggered()
{
    ExcepEditor *excep = new ExcepEditor(this);
    ui->tabWidget->addTab (excep,QString(tr("记录异常信息")));
    ui->tabWidget->setCurrentWidget (excep);
    connect (excep,SIGNAL(handin_excep(ExcepEditor*,QString*)),this,SIGNAL(handin_excep(ExcepEditor*,QString*)));
}

void MainWindow::on_wDiaryAct_triggered()
{
    DiaryEditor *de = new DiaryEditor(this);
    ui->tabWidget->addTab (de,QString(tr("写日志")));
    ui->tabWidget->setCurrentWidget (de);
    connect (de,SIGNAL(handinDiary(DiaryEditor*,QString*)),this,SIGNAL(handinDiary(DiaryEditor*,QString*)));
}

void MainWindow::on_diaryHisAct_triggered()
{
    DiaryDisp *dd = new DiaryDisp(this);
    ui->tabWidget->addTab (dd,QString(tr("历史日志列表")));
    ui->tabWidget->setCurrentWidget (dd);
    emit diaryHistory (dd);
}

void MainWindow::on_mthrAct_triggered()
{
    ThroughoutDisp *td = new ThroughoutDisp(this,0);
    ui->tabWidget->addTab (td,QString(tr("本月吞吐")));
    ui->tabWidget->setCurrentWidget (td);
    emit mthrough (td);
}

void MainWindow::on_nxtMthrAct_triggered()
{
    ThroughoutDisp *td = new ThroughoutDisp(this,1);
    ui->tabWidget->addTab (td,QString(tr("下月吞吐")));
    ui->tabWidget->setCurrentWidget (td);
    emit nxmthrough (td);
}

void MainWindow::on_brknRateAct_triggered()
{
    WastageDsp *wd = new WastageDsp(this);
    ui->tabWidget->addTab (wd,QString(tr("破损")));
    ui->tabWidget->setCurrentWidget (wd);
    emit wastage(wd);
}

void MainWindow::on_rnkComAct_triggered()
{
    LncRankDsp *lrd = new LncRankDsp(this);
    ui->tabWidget->addTab (lrd,QString(tr("公司业务排名")));
    ui->tabWidget->setCurrentWidget (lrd);
    emit lncRank(lrd);
}

void MainWindow::on_loginAct_triggered()
{
    login = new Login_ui(this);
    connect (login,SIGNAL(authorise(QByteArray)),this,SIGNAL(authorise(QByteArray)));
    connect (login,SIGNAL(cancle_login()),this,SLOT(del_login()));
    login->show ();
}

void MainWindow::rcvAuthorise (int flag)
{
    switch(flag)
    {
    case 0://验证通过
        //nowAt
        enable_all();
        del_login ();
        break;
    case 1://验证没通过
         login->auth_fail ();
        break;
    default:
;
    }
}
void MainWindow::del_login ()
{
    if(NULL != login)
    {
         login->disconnect ();
         login->close ();
         delete login;
         login = NULL;
     }
}

void MainWindow::on_logoutAct_triggered()
{
//    稍后实现
//    nowAt
    disable_all();
    emit logout();
}

void MainWindow::disable_all ()
{
    ui->centralwidget->setDisabled (true);
    ui->menuFile->setDisabled (true);
    ui->menu->setDisabled (true);
    ui->menu_2->setDisabled (true);
    ui->menu_6->setDisabled (true);
    ui->menu_3->setDisabled (true);
    ui->menu_5->setDisabled (true);

    ui->logoutAct->setDisabled (true);
    ui->newAcntAct->setDisabled (true);
    ui->chpasswdAct->setDisabled (true);
    ui->bkpasswdAct->setDisabled (true);
    ui->printAct->setDisabled (true);
    ui->wDiaryAct->setDisabled (true);
    ui->mthrAct->setDisabled (true);
    ui->nxtMthrAct->setDisabled (true);
    ui->brknRateAct->setDisabled (true);
    ui->rnkComAct->setDisabled (true);
    ui->diaryHisAct->setDisabled (true);

    ui->loginAct->setEnabled (true);;
}

void MainWindow::enable_all ()
{
    ui->centralwidget->setDisabled (false);
    ui->menuFile->setDisabled (false);
    ui->menu->setDisabled (false);
    ui->menu_2->setDisabled (false);
    ui->menu_6->setDisabled (false);
    ui->menu_3->setDisabled (false);
    ui->menu_5->setDisabled (false);

    ui->logoutAct->setDisabled (false);
    ui->newAcntAct->setDisabled (false);
    ui->chpasswdAct->setDisabled (false);
    ui->bkpasswdAct->setDisabled (false);
    ui->printAct->setDisabled (false);
    ui->wDiaryAct->setDisabled (false);
    ui->mthrAct->setDisabled (false);
    ui->nxtMthrAct->setDisabled (false);
    ui->brknRateAct->setDisabled (false);
    ui->rnkComAct->setDisabled (false);
    ui->diaryHisAct->setDisabled (false);

    ui->loginAct->setDisabled (true);
}

void MainWindow::on_curStorAct_triggered()
{
    StoreStatusDsp *ssd = new StoreStatusDsp(this);
    ui->tabWidget->addTab (ssd,QString(tr("仓储状态")));
    ui->tabWidget->setCurrentWidget (ssd);
    emit curStore (ssd);
}
