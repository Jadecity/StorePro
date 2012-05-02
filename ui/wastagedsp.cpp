#include "wastagedsp.h"
#include "ui_wastageDsp.h"

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

    ui->progressBar->setValue (data.ratio*100);
}

