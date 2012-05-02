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

#include <QMessageBox>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
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
//�½�һ����ǩ�������������꣬Ȼ����ʾ����������
void MainWindow::on_lookGoodByPosi_triggered()
{
    StoreMap *map =  new StoreMap(this);
    ui->tabWidget->addTab (map,QString(tr("λ����Ϣ")));
    ui->tabWidget->setCurrentWidget (map);
    connect(map,SIGNAL(fetch(StoreMap*,int,int)),this,SIGNAL(reqstGoodInfo(StoreMap*,int,int)));
}

//�½�һ����ǩ���������������Ϣ��Ȼ����ʾ����������
void MainWindow::on_lookGoodByInfo_triggered()
{
    AskGoodToLookDlg *dlg = new AskGoodToLookDlg(this);
    ui->tabWidget->addTab (dlg,QString(tr("������Ϣ����")));
    ui->tabWidget->setCurrentWidget (dlg);
    connect (dlg,SIGNAL(query_good_info(AskGoodToLookDlg*,QString*)),this,SIGNAL(query_good_info(AskGoodToLookDlg*,QString*)));
}

//����ǩ�رգ���ɾ��
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    /*delete widget if the tab is closed*/
    QWidget *toRm = ui->tabWidget->widget (index);
    ui->tabWidget->removeTab (index);
    toRm->disconnect ();
    delete toRm;
    toRm = NULL;
//    ɾ�����������ⲿɾ����ʱ����
    emit actionFinish ();
}
//�½���ǩ�������쳣��Ϣ
void MainWindow::on_recExcepAct_triggered()
{
    ExcepEditor *excep = new ExcepEditor(this);
    ui->tabWidget->addTab (excep,QString(tr("��¼�쳣��Ϣ")));
    ui->tabWidget->setCurrentWidget (excep);
    connect (excep,SIGNAL(handin_excep(ExcepEditor*,QString*)),this,SIGNAL(handin_excep(ExcepEditor*,QString*)));
}

void MainWindow::on_wDiaryAct_triggered()
{
    DiaryEditor *de = new DiaryEditor(this);
    ui->tabWidget->addTab (de,QString(tr("д��־")));
    ui->tabWidget->setCurrentWidget (de);
    connect (de,SIGNAL(handinDiary(DiaryEditor*,QString*)),this,SIGNAL(handinDiary(DiaryEditor*,QString*)));
}

void MainWindow::on_diaryHisAct_triggered()
{
    DiaryDisp *dd = new DiaryDisp(this);
    ui->tabWidget->addTab (dd,QString(tr("��ʷ��־�б�")));
    ui->tabWidget->setCurrentWidget (dd);
    connect (dd,SIGNAL(diaries(DiaryDisp*,QString,QString)),this,SIGNAL(diaryHistory(DiaryDisp*,QString,QString)));
}

void MainWindow::on_mthrAct_triggered()
{
    ThroughoutDisp *td = new ThroughoutDisp(this,0);
    ui->tabWidget->addTab (td,QString(tr("��������")));
    ui->tabWidget->setCurrentWidget (td);
    emit mthrough (td);
}

void MainWindow::on_nxtMthrAct_triggered()
{
    ThroughoutDisp *td = new ThroughoutDisp(this,1);
    ui->tabWidget->addTab (td,QString(tr("��������")));
    ui->tabWidget->setCurrentWidget (td);
    emit nxmthrough (td);
}

void MainWindow::on_brknRateAct_triggered()
{
    WastageDsp *wd = new WastageDsp(this);
    ui->tabWidget->addTab (wd,QString(tr("����")));
    ui->tabWidget->setCurrentWidget (wd);
    emit wastage(wd);
}

void MainWindow::on_rnkComAct_triggered()
{
    LncRankDsp *lrd = new LncRankDsp(this);
    ui->tabWidget->addTab (lrd,QString(tr("��˾ҵ������")));
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
    case 1://��֤ͨ��
        //nowAt
        {
        QMessageBox *box = new QMessageBox;
        box->addButton (QMessageBox::Ok);
        box->setText ("��½�ɹ���");
        box->show();
        connect(box,SIGNAL(buttonClicked(QAbstractButton*)),login,SLOT(close()));

        enable_all();
        del_login ();
        break;
    }
    case 0://��֤ûͨ��
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
//    �Ժ�ʵ��
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
    ui->wDiaryAct->setDisabled (true);
    ui->mthrAct->setDisabled (true);
    ui->nxtMthrAct->setDisabled (true);
    ui->brknRateAct->setDisabled (true);
    ui->rnkComAct->setDisabled (true);
    ui->diaryHisAct->setDisabled (true);

    ui->loginAct->setEnabled (true);
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
    ui->tabWidget->addTab (ssd,QString(tr("�ִ�״̬")));
    ui->tabWidget->setCurrentWidget (ssd);
    emit curStore (ssd);
}

void MainWindow::on_inStoreAct_triggered()
{
    Instore_table *intable = new Instore_table;
    ui->tabWidget->addTab (intable,QString(tr("���")));
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
            box->setText (trUtf8 ("�����ɣ�"));
            box->show ();
            break;
        }
    case 2:
        {
            QMessageBox *box = new QMessageBox;
            box->addButton (QMessageBox::Ok);
            box->setText (trUtf8 ("������ɣ�"));
            box->show ();
             break;
        }
    case 3:
        {
             /*
             QMessageBox *box = new QMessageBox;
             box->addButton (QMessageBox::Ok);
             box->setText (QString("��������ϴ���ɣ�"));
             box->show ();
              break;
              */
        }
    }
}

void MainWindow::on_outStoreAct_triggered()
{
    Outstore_table *outable = new Outstore_table;
    ui->tabWidget->addTab (outable,QString(tr("����")));
    ui->tabWidget->setCurrentWidget (outable);

    connect(outable,SIGNAL(outstore_signal(Outstore_table*,QByteArray)),this,SIGNAL(outstore_signal(Outstore_table*,QByteArray)));
    connect (outable,SIGNAL(next(int)),this,SLOT(nextflow(int)));
}

void MainWindow::on_chkGoodAct_triggered()
{
    Check_table *chkable = new Check_table;
    ui->tabWidget->addTab (chkable,QString(tr("��֤��")));
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














