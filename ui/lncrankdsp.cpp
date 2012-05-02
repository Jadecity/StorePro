#include "lncrankdsp.h"
#include "ui_lncRankDsp.h"

LncRankDsp::LncRankDsp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LncRankDsp),
    list(NULL)
{
    ui->setupUi(this);
}

LncRankDsp::~LncRankDsp()
{
    delete ui;
    if(NULL!=list)
    {
        delete list;
    }
}

void LncRankDsp::rcvData (QList<IncRank> *list)
{
    if(NULL!= list)
    {
        this->list = list;
        //nowAt
        //display aaaaaaaaaaaaa
        int size = list->size ();
        for(int i=0;i<size;i++)
        {
            QTableWidgetItem *item1 = new QTableWidgetItem;
            item1->setText (QString::number (list->at (i).rank));

            QTableWidgetItem *item2 = new QTableWidgetItem;
            item2->setText (QString::number (list->at (i).trans_amnt));

            QTableWidgetItem *item3 = new QTableWidgetItem;
            item3->setText (list->at (i).Inc_name);

            ui->tableWidget->setItem (i,0,item1);
            ui->tableWidget->setItem (i,1,item2);
            ui->tableWidget->setItem (i,2,item3);
        }
    }
}
