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
//    包括了用户名和密码
    void login(QByteArray info);
//    退出登陆
    void logout();
//    创建账户
    void createAccount(QStringList list);
//    更改当前用户密码
    void changePasswd(QStringList passwds);
//    获得用户列表
    void getUsers();
//    删除参数中的用户
    void delUsers(QStringList mylist);
//    override parent method
    void setDatacntr (DataTrans *dc);
public slots:
    void recv (QByteArray data);
signals:
//    将验证后的状态显示到UI
    void disp(int flag);
//    将回显消息交给界面
    void dispInfo(QByteArray info);
//    将用户信息上交给其他模块
    void dispUsers(QStringList users);

private:
    DataTrans *datacntr;
};

#endif // ACCOUNTMGR_H
