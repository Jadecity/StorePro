#ifndef ACCOUNTMGR_H
#define ACCOUNTMGR_H

#include <QObject>
#include "dataIO.h"
using namespace DataIO;
#include "upcntrbase.h"
#include "cmddef.h"
#include "globalDataType.h"
#include <QStringList>
class AccountMgr : public UpCntrBase
{
    Q_OBJECT
public:
    AccountMgr(QObject *parent=0);
//    �������û���������
    void login(QByteArray info);
//    �˳���½
    void logout();
//    �����˻�
    void createAccount(QStringList list);
//    ���ĵ�ǰ�û�����
    void changePasswd(QStringList passwds);
//    ����û��б�
    void getUsers();
//    ɾ�������е��û�
    void delUsers(QStringList mylist);
//    override parent method
    void setDatacntr (DataTrans *dc);
public slots:
    void recv (QByteArray data);
signals:
//    ����֤���״̬��ʾ��UI
    void disp(int flag);
//    ��������Ϣ��������
    void dispInfo(QByteArray info);
//    ���û���Ϣ�Ͻ�������ģ��
    void dispUsers(QStringList users);

private:
    DataTrans *datacntr;
};

#endif // ACCOUNTMGR_H
