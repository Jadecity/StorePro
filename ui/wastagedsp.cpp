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

void WastageDsp::rcvData(QByteArray data)
{
    //nowAt
    //display
}

