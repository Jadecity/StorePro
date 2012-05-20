#include "throughoutdisp.h"
#include "ui_throughoutDisp.h"
#include <QString>
//#include "draw3dpiechart.h"
#include "rectdrawer.h"

ThroughoutDisp::ThroughoutDisp(QWidget *parent,int flag) :
    QWidget(parent),
    ui(new Ui::ThroughoutDisp)
{
    ui->setupUi(this);
    if(0==flag)
    {
          ui->this_thatLabel->setText (QString("本月吞吐："));
          ui->label_7->setText(QString("本月量"));
    }
    else
    {
         ui->this_thatLabel->setText (QString("预测吞吐："));
         ui->label_7->setText(QString("下月量"));
    }
}

ThroughoutDisp::~ThroughoutDisp()
{
    delete ui;
}

void ThroughoutDisp::rcvData (Throughout in_out)
{
    ui->history->setText (QString::number ((in_out.history)));
    ui->floating->setText (QString::number (in_out.fudong*100));
    ui->this_or_nextMonth->setText (QString::number (in_out.num));
//    ui->roi->setValue ((int)(in_out.fudong*100)%100);

    QList<float> lstPercent; //矩形个数与每个矩形的百分比
    float roi = (float)in_out.num/in_out.totalnum;
    if(roi>1)
    {
        lstPercent.append(1);
        lstPercent.append((float)in_out.totalnum/in_out.num);
    }else
    {
        lstPercent.append(roi);
        lstPercent.append(1);
    }

    RectDrawer *drawrect = new RectDrawer(this);
    drawrect->setPos(100, 40);
    drawrect->setSize(280, 200);
    drawrect->setRectPercent(lstPercent);
    drawrect->setDistance(20);
    drawrect->show();
}
