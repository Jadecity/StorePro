#ifndef TESTDIARY_H
#define TESTDIARY_H

#include <QObject>
#include "storageMgr.h"
using namespace StorageMgr;

class testDiary : public QObject
{
    Q_OBJECT
public:
    explicit testDiary(QObject *parent = 0);
    void start();
signals:
    void goUpload(QString *,int);
    void goCheckDiary();
    void goFetchContent(QString);
public slots:
    void tstDiary();
    void tstDiaries();
    void tstContent();
private:
    DiaryMgr *dmgr;
};

#endif // TESTDIARY_H
