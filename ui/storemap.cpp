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

void StoreMap::rcvData (QList<PosiInfo> *list)
{
    /*
     *ÕâÀïÌî³äÏÔÊ¾Âß¼­
    */
    int num = list->size ();
    for(int i=0;i<num;i++)
    {
        QStringList qlist;
        qlist.push_back (list->at (i).goodname);
//      qlist.push_back (QString::number (list->at (i).toStay));
        //qlist.push_back ("x:"+list->at (i).posi[0] + "y:"+list->at (i).posi[1]);
        qlist.push_back (QString::number (list->at (i).price));
        qlist.push_back (QString::number (list->at (i).amount));
        qlist.push_back (list->at (i).unit);
        qlist.push_back (list->at (i).owner);
        qlist.push_back (list->at (i).arrivetime);
        QTreeWidgetItem *item = new QTreeWidgetItem(qlist);
        ui->treeWidget->addTopLevelItem (item);
    }

    delete list;
    list = NULL;
}
