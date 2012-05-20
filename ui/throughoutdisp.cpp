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
          ui->this_thatLabel->setText (QString("�������£�"));
          ui->label_7->setText(QString("������"));
    }
    else
    {
         ui->this_thatLabel->setText (QString("Ԥ�����£�"));
         ui->label_7->setText(QString("������"));
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

    QList<float> lstPercent; //���θ�����ÿ�����εİٷֱ�
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
