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
//    收到日志列表，显示出来
    void rcvData(QList<Diary *> *list);
private:
    Ui::DiaryDisp *ui;
//    本地存储一个列表，用于删除日志内容
    QList<Diary *> *list;
};

#endif // DIARYDISP_H
