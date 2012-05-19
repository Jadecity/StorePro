#include "wastagedsp.h"
#include "ui_wastageDsp.h"
#include "draw3dpiechart.h"
WastageDsp::WastageDsp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WastageDsp)
{
    ui->setupUi(this);
}

WastageDsp::~WastageDsp()
{
    delete ui;
}

void WastageDsp::rcvData(Wastage data)
{
    //nowAt
    //display
    ui->wstNoLabel->setText (QString::number (data.wastage));
    ui->wstRateLabel->setText (QString::number (data.ratio));
    ui->totalLabel->setText (QString::number (data.total));

    //ui->progressBar->setValue (data.ratio*100);
    QList<double> lstPercent; //扇形个数与每个扇形的百分比
    lstPercent.append(data.ratio);
    lstPercent.append(1-data.ratio);
    CDraw3dPieChart *draw3dPie = new CDraw3dPieChart(this);
    draw3dPie->setPiePos(130, 40);
    draw3dPie->setPieSize(280, 200);
    draw3dPie->setPiePerCent(lstPercent);
    draw3dPie->setChartDepth(20);
    draw3dPie->show();
}

