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
          ui->this_thatLabel->setText (QString("±¾ÔÂÍÌÍÂ£º"));
    }
    else
    {
         ui->this_thatLabel->setText (QString("Ô¤²âÍÌÍÂ£º"));
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
    ui->roi->setValue ((int)(in_out.fudong*100)%100);
}
