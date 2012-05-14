#include "throughoutdisp.h"
#include "ui_throughoutDisp.h"
#include <QString>
ThroughoutDisp::ThroughoutDisp(QWidget *parent,int flag) :
    QWidget(parent),
    ui(new Ui::ThroughoutDisp)
{
    ui->setupUi(this);
    if(0==flag)
    {
          ui->this_thatLabel->setText (QString("本月吞吐："));
    }
    else
    {
         ui->this_thatLabel->setText (QString("预测吞吐："));
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

    QList<double> lstPercent; //扇形个数与每个扇形的百分比
    lstPercent.append(in_out.num/in_out.totalnum);
    lstPercent.append(1-in_out.num/in_out.totalnum);
    CDraw3dPieChart *draw3dPie = new CDraw3dPieChart(this);
    draw3dPie->setPiePos(100, 40);
    draw3dPie->setPieSize(280, 200);
    draw3dPie->setPiePerCent(lstPercent);
    draw3dPie->setChartDepth(20);
}
