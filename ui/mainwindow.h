/*
 *我使用这个类来创建所有的UI对象（再合适的时候）
 *然后通过信号将对象指针在适当的时候传到处理对象
 *但是对象的删除在这个类里
 *由于处理的槽先被调用，所以可以在一个emit后面直接删除
 *对象
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
//    窗口中所有控件设为可用，除了登录
    void enable_all();
//    窗口中所有控件设为不可用，除了登录
    void disable_all();

private:
    Ui::MainWindow *ui;
    Login_ui *login;
public slots:
//    接收验证后的用户状态
//    0代表没通过，1代表通过
    void rcvAuthorise(int);
//    删除登录对像
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
    //切换到下一个表单界面
    void nextflow(int);
// 显示超时的货物数量
    void showOverTime(int);
signals:
//    通知外部删除临时对象，一个用例已经完成
    void actionFinish();
    void reqstGoodInfo(StoreMap*,int,int);
//    第一个参数是本对象，第二个参数是获取到的数据的数组
    void query_good_info(AskGoodToLookDlg*,QString *data);
//    info包含了所有从界面获得的数据，info的长度是8
    void handin_excep(ExcepEditor*,QString *info);
//    info包括了4个QString，按照Diary结构体中的顺序
    void handinDiary(DiaryEditor *,QString *info);
//去取得历史日志并显示
//仅仅把显示区域传递出去，后面跟起始和终止日期
    void diaryHistory(DiaryDisp*,QString,QString);
    //去取得本月吞吐并显示
    //仅仅把显示区域传递出去，并不传递任何其他信息
    void mthrough(ThroughoutDisp*);
    //去取得下月吞吐并显示
    //仅仅把显示区域传递出去，并不传递任何其他信息
    void nxmthrough(ThroughoutDisp*);
//    请求破损，传出的指针用于显示传回的数据
    void wastage(WastageDsp *);
 //    请求公司排名，传出的指针用于显示传回的数据
    void lncRank(LncRankDsp *);
//    请求验证用户名和密码
    void authorise(QByteArray);
//    登出
    void logout();
//    查看当前仓储
//    指针用于显示返回结果
    void curStore(StoreStatusDsp *);
//    发送入库数据
    void instore_signal(Instore_table *,QByteArray);
//    发送验货单
    void send_chk_table(Check_table *,QByteArray);
//    出库单
    void outstore_signal(Outstore_table*,QByteArray);

};

#endif // MAINWINDOW_H
