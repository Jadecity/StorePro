#ifndef DIARYDISP_H
#define DIARYDISP_H

#include <QWidget>
#include "logic/globalDataType.h"
#include <QList>
namespace Ui {
    class DiaryDisp;
}

class DiaryDisp : public QWidget
{
    Q_OBJECT

public:
    explicit DiaryDisp(QWidget *parent = 0);
    ~DiaryDisp();
public slots:
//    �յ���־�б���ʾ����
    void rcvData(QList<Diary *> *list);
private:
    Ui::DiaryDisp *ui;
//    ���ش洢һ���б�����ɾ����־����
    QList<Diary *> *list;
};

#endif // DIARYDISP_H
