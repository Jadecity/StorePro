#ifndef TESTDATATRANS_H
#define TESTDATATRANS_H

#include <QObject>
#include"dataIO.h"
#include"upcntrbase.h"
class testDatatrans : public UpCntrBase
{
    Q_OBJECT
public:
    explicit testDatatrans(QObject *parent = 0);
    void start();
    void recv(QByteArray data);
signals:

public slots:
private:
    DataIO::DataTrans *dt;
};

#endif // TESTDATATRANS_H
