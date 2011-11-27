#include "diarydisp.h"
#include "ui_diarydisp.h"

DiaryDisp::DiaryDisp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiaryDisp),
    list(NULL)
{
    ui->setupUi(this);
}

DiaryDisp::~DiaryDisp()
{
    delete ui;
    if(NULL != list)
    {
        delete list;
        list = NULL;
    }
}

void DiaryDisp::rcvData (QList<Diary *> *list)
{
    if(NULL != list)
    {
        this->list = list;
        //œ‘ æ
        //nowAt
    }
}
