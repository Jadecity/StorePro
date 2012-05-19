#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "askgoodtolookdlg.h"
#include "diaryeditor.h"
#include "excepeditor.h"
#include "lncrankdsp.h"
#include "storemap.h"
#include "storestatusdsp.h"
#include "throughoutdisp.h"
#include "wastagedsp.h"
#include "diarydisp.h"
#include "login_ui.h"
#include "instore_table.h"
#include "outstore_table.h"
#include "check_table.h"
#include "exchange_table.h"
#include "overtimetab.h"
#include <QMessageBox>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QTableWidgetItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    login(NULL)
{
    ui->setupUi(this);
    disable_all ();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//新建一个标签，用于输入坐标，然后显示在主窗口中
void MainWindow::on_lookGoodByPosi_triggered()
{
    StoreMap *map =  new StoreMap(this);
    ui->tabWidget->addTab (map,QString(tr("位置信息")));
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
    connect (dd,SIGNAL(diaries(DiaryDisp*,QString,QString)),this,SIGNAL(diaryHistory(DiaryDisp*,QString,QString)));
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
    ui->loginAct->setEnabled (false);
    connect(login,SIGNAL(rejected()),this,SLOT(disable_all()));
    login->show ();

}

void MainWindow::rcvAuthorise (int flag)
{
    switch(flag)
    {
    case 1://验证通过
        //nowAt
        {
        QMessageBox *box = new QMessageBox;
        box->addButton (QMessageBox::Ok);
        box->setText ("登陆成功！");
        box->show();
        connect(box,SIGNAL(buttonClicked(QAbstractButton*)),login,SLOT(close()));

        enable_all();
        del_login ();
        emit callClientTimeEvent();
        break;
    }
    case 0://验证没通过
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
    ui->menu_7->setDisabled(true);

    ui->logoutAct->setDisabled (true);
    ui->newAcntAct->setDisabled (true);
    ui->chpasswdAct->setDisabled (true);
    ui->delUser->setDisabled (true);
    ui->wDiaryAct->setDisabled (true);
    ui->mthrAct->setDisabled (true);
    ui->nxtMthrAct->setDisabled (true);
    ui->brknRateAct->setDisabled (true);
    ui->rnkComAct->setDisabled (true);
    ui->diaryHisAct->setDisabled (true);

    ui->loginAct->setEnabled (true);
    ui->overtime->setVisible(false);
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
    ui->menu_7->setDisabled(false);

    ui->logoutAct->setDisabled (false);
    ui->newAcntAct->setDisabled (false);
    ui->chpasswdAct->setDisabled (false);
    ui->delUser->setDisabled (false);
    ui->wDiaryAct->setDisabled (false);
    ui->mthrAct->setDisabled (false);
    ui->nxtMthrAct->setDisabled (false);
    ui->brknRateAct->setDisabled (false);
    ui->rnkComAct->setDisabled (false);
    ui->diaryHisAct->setDisabled (false);

    ui->loginAct->setDisabled (true);
    ui->overtime->setVisible(false);
}

void MainWindow::on_curStorAct_triggered()
{
    StoreStatusDsp *ssd = new StoreStatusDsp(this);
    ui->tabWidget->addTab (ssd,QString(tr("仓储状态")));
    ui->tabWidget->setCurrentWidget (ssd);
    emit curStore (ssd);
}

void MainWindow::on_inStoreAct_triggered()
{
    Instore_table *intable = new Instore_table;
    ui->tabWidget->addTab (intable,QString(tr("入库")));
    ui->tabWidget->setCurrentWidget (intable);

    connect (intable,SIGNAL(instore_signal(Instore_table*,QByteArray)),this,SIGNAL(instore_signal(Instore_table*,QByteArray)));
}

void MainWindow::nextflow (int flag)
{
    switch(flag)
    {
    case 1:
        {
            QMessageBox *box = new QMessageBox;
            box->addButton (QMessageBox::Ok);
            box->setText (trUtf8 ("入库完成！"));
            box->show ();
            break;
        }
    case 2:
        {
            QMessageBox *box = new QMessageBox;
            box->addButton (QMessageBox::Ok);
            box->setText (trUtf8 ("出库完成！"));
            box->show ();
             break;
        }
    case 3:
        {
             /*
             QMessageBox *box = new QMessageBox;
             box->addButton (QMessageBox::Ok);
             box->setText (QString("验货单已上传完成！"));
             box->show ();
              break;
              */
        }
    }
}

void MainWindow::on_outStoreAct_triggered()
{
    Outstore_table *outable = new Outstore_table;
    ui->tabWidget->addTab (outable,QString(tr("出库")));
    ui->tabWidget->setCurrentWidget (outable);

    connect(outable,SIGNAL(outstore_signal(Outstore_table*,QByteArray)),this,SIGNAL(outstore_signal(Outstore_table*,QByteArray)));
    connect (outable,SIGNAL(next(int)),this,SLOT(nextflow(int)));
}

void MainWindow::on_chkGoodAct_triggered()
{
    Check_table *chkable = new Check_table;
    ui->tabWidget->addTab (chkable,QString(tr("验证单")));
    ui->tabWidget->setCurrentWidget (chkable);

    connect (chkable,SIGNAL(next(int)),this,SLOT(nextflow(int)));
    connect (chkable,SIGNAL(send_chk_table(Check_table *,QByteArray)),this,SIGNAL(send_chk_table(Check_table *,QByteArray)));
}

void MainWindow::on_storHisAct_triggered()
{

}

void MainWindow::on_quitAct_triggered()
{
    this->close ();
}

void MainWindow::on_manDocAct_triggered()
{
    //QProcess::startDetached ("help.doc");
    QDesktopServices::openUrl (QUrl::fromLocalFile ("help.doc"));
}

void MainWindow::showOverTime(int amount)
{
    //show different color according to the amount
//    if(amount >0)
//    {
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/invagate/icons/warning.png"));
        ui->overtime->setIcon(icon);
        ui->overtime->setText(QString::number(amount));
        ui->overtime->setVisible(true);
//    }
}

void MainWindow::showOverTimeDetails(QByteArray data)
{
    QDataStream ds(&data,QIODevice::ReadOnly);
    int numOfRows=0;
    ds>>numOfRows;
    OverTimeTab *onetab = new OverTimeTab();

    for(int i=0;i<numOfRows;i++)
    {
        int serial=0;
        int amount=0;
        QByteArray name;
        QByteArray danwei;
        QByteArray time;
        QByteArray owner;
        QByteArray deadLine;

        ds>>serial>>name>>danwei>>amount>>time>>owner>>deadLine;

        QTableWidgetItem *item1 = new QTableWidgetItem;
        item1->setText (QString::number (serial));
        onetab->setItem(i,0,item1);

        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setText (QString(name));
        onetab->setItem(i,1,item2);

        QTableWidgetItem *item3 = new QTableWidgetItem;
        item3->setText (QString(danwei));
        onetab->setItem(i,2,item3);

        QTableWidgetItem *item4 = new QTableWidgetItem;
        item4->setText (QString::number(amount));
        onetab->setItem(i,3,item4);

        QTableWidgetItem *item5 = new QTableWidgetItem;
        item5->setText (QString(time));
        onetab->setItem(i,4,item5);

        QTableWidgetItem *item6 = new QTableWidgetItem;
        item6->setText (QString(owner));
        onetab->setItem(i,5,item6);

        QTableWidgetItem *item7 = new QTableWidgetItem;
        item7->setText (QString(deadLine));
        onetab->setItem(i,6,item7);
    }

    ui->tabWidget->addTab (onetab,QString(tr("货物超时信息")));
    ui->tabWidget->setCurrentWidget (onetab);
}

void MainWindow::on_overtime_triggered()
{
    emit getOverTime();
}

void MainWindow::on_newAcntAct_triggered()
{
// show create account window
    CreateUserWnd *wnd = new CreateUserWnd;
    ui->tabWidget->addTab (wnd,QString(tr("创建用户")));
    ui->tabWidget->setCurrentWidget (wnd);
//    ui->tabWidget->setTabEnabled(ui->tabWidget->currentIndex(),false);
    connect(wnd,SIGNAL(createButtonClicked(CreateUserWnd*)),SIGNAL(createAccount(CreateUserWnd*)));
    connect(wnd,SIGNAL(dataOk()),SLOT(enableCurrentTab()));
}

void MainWindow::on_chpasswdAct_triggered()
{
// show ui to change password
    ChangePasswdWnd *wnd = new ChangePasswdWnd;
    ui->tabWidget->addTab (wnd,QString(tr("创建用户")));
    ui->tabWidget->setCurrentWidget (wnd);
//    ui->tabWidget->setTabEnabled(ui->tabWidget->currentIndex(),false);
    connect(wnd,SIGNAL(changeButtonClicked(ChangePasswdWnd*)),SIGNAL(changePasswd(ChangePasswdWnd*)));
    connect(wnd,SIGNAL(dataOk()),SLOT(enableCurrentTab()));
}

void MainWindow::on_delUser_triggered()
{
//    show ui to disp all common accounts
    DelUserWnd *wnd = new DelUserWnd;
    ui->tabWidget->addTab (wnd,QString(tr("创建用户")));
    ui->tabWidget->setCurrentWidget (wnd);
    //ui->tabWidget->setTabEnabled(ui->tabWidget->currentIndex(),false);
    connect(wnd,SIGNAL(delAction(DelUserWnd*)),SIGNAL(delUsers(DelUserWnd*)));
    //connect(wnd,SIGNAL(dataOk()),SLOT(enableCurrentTab()));
    emit getUsers(wnd);
}

void MainWindow::enableCurrentTab()
{
     ui->tabWidget->setTabEnabled(ui->tabWidget->currentIndex(),true);
}
