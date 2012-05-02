#ifndef ACCOUNTMGR_H
#define ACCOUNTMGR_H

#include <QObject>
#include "dataIO.h"
using namespace DataIO;
#include "upcntrbase.h"
#include "cmddef.h"
#include "globalDataType.h"

class AccountMgr : public UpCntrBase
{
    Q_OBJECT
public:
    AccountMgr(QObject *parent=0);
//    包括了用户名和密码
    void login(QByteArray info);
//    退出登陆
    void logout();
//    override parent method
    void setDatacntr (DataTrans *dc);
public slots:
    void recv (QByteArray data);
signals:
//    将验证后的状态显示到UI
    void disp(int flag);

private:
    DataTrans *datacntr;
};

#endif // ACCOUNTMGR_H
