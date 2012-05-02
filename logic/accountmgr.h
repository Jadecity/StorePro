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
//    �������û���������
    void login(QByteArray info);
//    �˳���½
    void logout();
//    override parent method
    void setDatacntr (DataTrans *dc);
public slots:
    void recv (QByteArray data);
signals:
//    ����֤���״̬��ʾ��UI
    void disp(int flag);

private:
    DataTrans *datacntr;
};

#endif // ACCOUNTMGR_H
