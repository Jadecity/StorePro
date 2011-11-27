#ifndef LNCRANKDSP_H
#define LNCRANKDSP_H

#include <QWidget>
#include <QList>
#include "logic\globalDataType.h"
namespace Ui {
    class LncRankDsp;
}

class LncRankDsp : public QWidget
{
    Q_OBJECT

public:
    explicit LncRankDsp(QWidget *parent = 0);
    ~LncRankDsp();
public slots:
//    显示公司排名列表
    void rcvData(QList<IncRank *> *list);

private:
    Ui::LncRankDsp *ui;
//    存储传入的公司列表，为后面删除数据用
    QList<IncRank *> *list;
};

#endif // LNCRANKDSP_H
