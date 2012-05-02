/*
 *��ʹ����������������е�UI�����ٺ��ʵ�ʱ��
 *Ȼ��ͨ���źŽ�����ָ�����ʵ���ʱ�򴫵��������
 *���Ƕ����ɾ�����������
 *���ڴ���Ĳ��ȱ����ã����Կ�����һ��emit����ֱ��ɾ��
 *����
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QDialog;
class DiaryEditor;
class AskGoodToLookDlg;
class ExcepEditor;
class LncRankDsp;
class StoreMap;
class StoreStatusDsp;
class ThroughoutDisp;
class WastageDsp;
class DiaryDisp;
class Login_ui;
class Instore_table;
class Check_table;
class Outstore_table;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    ���������пؼ���Ϊ���ã����˵�¼
    void enable_all();
//    ���������пؼ���Ϊ�����ã����˵�¼
    void disable_all();

private:
    Ui::MainWindow *ui;
    Login_ui *login;
public slots:
//    ������֤����û�״̬
//    0����ûͨ����1����ͨ��
    void rcvAuthorise(int);
//    ɾ����¼����
    void del_login();

private slots:
    /*delete widget if the tab is closed*/
    void on_manDocAct_triggered();
    void on_quitAct_triggered();
    void on_storHisAct_triggered();
    void on_chkGoodAct_triggered();
    void on_outStoreAct_triggered();
    void on_inStoreAct_triggered();
    void on_curStorAct_triggered();
    void on_logoutAct_triggered();
    void on_loginAct_triggered();
    void on_rnkComAct_triggered();
    void on_brknRateAct_triggered();
    void on_nxtMthrAct_triggered();
    void on_mthrAct_triggered();
    void on_diaryHisAct_triggered();
    void on_wDiaryAct_triggered();
    void on_recExcepAct_triggered();
    void on_lookGoodByInfo_triggered();
    void on_tabWidget_tabCloseRequested(int index);
    void on_lookGoodByPosi_triggered();
    //�л�����һ��������
    void nextflow(int);
// ��ʾ��ʱ�Ļ�������
    void showOverTime(int);
signals:
//    ֪ͨ�ⲿɾ����ʱ����һ�������Ѿ����
    void actionFinish();
    void reqstGoodInfo(StoreMap*,int,int);
//    ��һ�������Ǳ����󣬵ڶ��������ǻ�ȡ�������ݵ�����
    void query_good_info(AskGoodToLookDlg*,QString *data);
//    info���������дӽ����õ����ݣ�info�ĳ�����8
    void handin_excep(ExcepEditor*,QString *info);
//    info������4��QString������Diary�ṹ���е�˳��
    void handinDiary(DiaryEditor *,QString *info);
//ȥȡ����ʷ��־����ʾ
//��������ʾ���򴫵ݳ�ȥ���������ʼ����ֹ����
    void diaryHistory(DiaryDisp*,QString,QString);
    //ȥȡ�ñ������²���ʾ
    //��������ʾ���򴫵ݳ�ȥ�����������κ�������Ϣ
    void mthrough(ThroughoutDisp*);
    //ȥȡ���������²���ʾ
    //��������ʾ���򴫵ݳ�ȥ�����������κ�������Ϣ
    void nxmthrough(ThroughoutDisp*);
//    �������𣬴�����ָ��������ʾ���ص�����
    void wastage(WastageDsp *);
 //    ����˾������������ָ��������ʾ���ص�����
    void lncRank(LncRankDsp *);
//    ������֤�û���������
    void authorise(QByteArray);
//    �ǳ�
    void logout();
//    �鿴��ǰ�ִ�
//    ָ��������ʾ���ؽ��
    void curStore(StoreStatusDsp *);
//    �����������
    void instore_signal(Instore_table *,QByteArray);
//    ���������
    void send_chk_table(Check_table *,QByteArray);
//    ���ⵥ
    void outstore_signal(Outstore_table*,QByteArray);

};

#endif // MAINWINDOW_H
