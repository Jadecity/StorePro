#include "storemap.h"
#include "ui_storemap.h"

StoreMap::StoreMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StoreMap)
{
    ui->setupUi(this);
}

StoreMap::~StoreMap()
{
    delete ui;
}

void StoreMap::on_okButton_clicked()
{
    int x = ui->editX->text ().toInt ();
    int y = ui->editY->text ().toInt ();
    emit fetch(this,x,y);
}

void StoreMap::rcvData (QByteArray data)
{
    /*
     *ÕâÀïÌî³äÏÔÊ¾Âß¼­
    */
}
