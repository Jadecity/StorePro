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
//    ��ʾ��˾�����б�
    void rcvData(QList<IncRank *> *list);

private:
    Ui::LncRankDsp *ui;
//    �洢����Ĺ�˾�б�Ϊ����ɾ��������
    QList<IncRank *> *list;
};

#endif // LNCRANKDSP_H
