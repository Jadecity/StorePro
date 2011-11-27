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

void LncRankDsp::rcvData (QList<IncRank *> *list)
{
    if(NULL!= list)
    {
        this->list = list;
        //nowAt
        //display aaaaaaaaaaaaa
    }
}
