#ifndef THROUGHOUTDISP_H
#define THROUGHOUTDISP_H

#include <QWidget>

namespace Ui {
    class ThroughoutDisp;
}

class ThroughoutDisp : public QWidget
{
    Q_OBJECT

public:
    explicit ThroughoutDisp(QWidget *parent = 0,int=0);
    ~ThroughoutDisp();
public slots:
//    ���ղ���ʾ����
    void rcvData(QByteArray data);
private:
    Ui::ThroughoutDisp *ui;
};

#endif // THROUGHOUTDISP_H
