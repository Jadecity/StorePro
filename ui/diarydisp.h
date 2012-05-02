#ifndef DIARYDISP_H
#define DIARYDISP_H

#include <QWidget>
#include "logic/globalDataType.h"
#include <QList>
#include <QTreeWidgetItem>

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
    void rcvData(QList<Diary> *list);
private:
    Ui::DiaryDisp *ui;
//    本地存储一个列表，用于删除日志内容
    QList<Diary> *list;
    QList<QString> *content;

private slots:
    void on_pushButton_clicked();
//    查看日志内容
    void diary_content(QTreeWidgetItem*,int);
signals:
//    查找两个日期之间的日志
    void diaries(DiaryDisp*,QString dateFrom,QString dateTo);

};

#endif // DIARYDISP_H
