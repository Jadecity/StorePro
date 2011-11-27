#include "storestatusdsp.h"
#include "ui_storestatusdsp.h"

StoreStatusDsp::StoreStatusDsp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StoreStatusDsp)
{
    ui->setupUi(this);
}

StoreStatusDsp::~StoreStatusDsp()
{
    delete ui;
}

void StoreStatusDsp::rcvData (QByteArray data)
{
    //nowAt
    //ÏÔÊ¾Âß¼­
}
