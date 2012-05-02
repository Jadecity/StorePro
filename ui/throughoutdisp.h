#ifndef THROUGHOUTDISP_H
#define THROUGHOUTDISP_H

#include <QWidget>
#include "logic/globalDataType.h"
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
//    接收并显示数据
    void rcvData(Throughout in_out);
private:
    Ui::ThroughoutDisp *ui;
};

#endif // THROUGHOUTDISP_H
