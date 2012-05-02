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
    /*��ʼ��UI����*/
    void initUI();
    /*��ʼ���߼������������������*/
    void initLogic();
    /*���������򣬴����￪ʼ������ʽ��ʾ���û�*/
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
     //ȥȡ����ʷ��־����ʾ
     void diaryHistoryHandler(DiaryDisp*,QString,QString);
      //ȥȡ�ñ������²���ʾ
     void mthroughHandler(ThroughoutDisp*);
     //ȥȡ���������²���ʾ
     void nxmthroughHandler(ThroughoutDisp*);
     //    ��������ָ��������ʾ���ص�����
     void wastageHandler(WastageDsp *);
     //    ����˾������ָ��������ʾ���ص�����
     void lncRankHandler(LncRankDsp *);
     //    ������֤�û���������
     void authoriseHandler(QByteArray);
     //    �ǳ�
     void logoutHandler();
     //    �鿴��ǰ�ִ�
     //    ָ��������ʾ���ؽ��
     void curStoreHandler(StoreStatusDsp *);
//     �������
     void instoreHandler(Instore_table *,QByteArray);
//     �����
    void chk_goodHandler(Check_table *,QByteArray);
//    ���ⵥ
    void outstoreHandler (Outstore_table *table, QByteArray data);
    /*һ������������ɺ�ɾ�����������������*/
    void cleanObj();
//�˳�
    void quit();
protected:
     void timerEvent(QTimerEvent *event);
private:
//    ���ڴ����ʱ���󣬹����ɾ��
    QQueue<QObject *> *queue;
    NetConnector *net;
    DataIO::DataTrans *datacntr;
    //������
    MainWindow *mwnd;
signals:
};

#endif // CLIENT_H

