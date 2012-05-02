#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include<QQueue>
#include "ui/mainwindow.h"
#include "logic/dataIO.h"
#include "logic/workFlow.h"
class Outstore_table;

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    /*初始化UI部件*/
    void initUI();
    /*初始化逻辑部件，包括检测网络*/
    void initLogic();
    /*启动主程序，从这里开始程序正式显示给用户*/
    void start();
public slots:
    //deal with get good info by position
    void reqstGoodInfoHandler(StoreMap*,int,int);
    //deal with ask goodinfo by info of good name
    void query_good_infoHandler(AskGoodToLookDlg*,QString *data);
    //get a exception and post to server
    void handin_excep(ExcepEditor*,QString *info);
    //get a diary and post to server
     void handinDiaryHandler(DiaryEditor *,QString *info);
     //去取得历史日志并显示
     void diaryHistoryHandler(DiaryDisp*,QString,QString);
      //去取得本月吞吐并显示
     void mthroughHandler(ThroughoutDisp*);
     //去取得下月吞吐并显示
     void nxmthroughHandler(ThroughoutDisp*);
     //    请求破损，指针用于显示传回的数据
     void wastageHandler(WastageDsp *);
     //    请求公司排名，指针用于显示传回的数据
     void lncRankHandler(LncRankDsp *);
     //    请求验证用户名和密码
     void authoriseHandler(QByteArray);
     //    登出
     void logoutHandler();
     //    查看当前仓储
     //    指针用于显示返回结果
     void curStoreHandler(StoreStatusDsp *);
//     入库请求
     void instoreHandler(Instore_table *,QByteArray);
//     验货单
    void chk_goodHandler(Check_table *,QByteArray);
//    出库单
    void outstoreHandler (Outstore_table *table, QByteArray data);
    /*一个完整用例完成后删除创建的请求处理对象*/
    void cleanObj();
//退出
    void quit();
protected:
     void timerEvent(QTimerEvent *event);
private:
//    用于存放临时对象，供最后删除
    QQueue<QObject *> *queue;
    NetConnector *net;
    DataIO::DataTrans *datacntr;
    //主窗口
    MainWindow *mwnd;
signals:
};

#endif // CLIENT_H

