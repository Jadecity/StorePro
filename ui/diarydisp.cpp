#include "diarydisp.h"
#include "ui_diarydisp.h"

DiaryDisp::DiaryDisp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiaryDisp),
    list(NULL)
{
    ui->setupUi(this);
    content = new QList<QString>;

    connect (ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(diary_content(QTreeWidgetItem*,int)));
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

void DiaryDisp::rcvData (QList<Diary> *list)
{
    if(NULL != list)
    {
        this->list = list;
        Diary temp;
        //ÏÔÊ¾
        //nowAt
        int num = list->size ();
        for(int i=0;i<num;i++)
        {
            temp = list->at (i);
            QStringList in_list;
            in_list.push_back (temp.title);
            content->push_back (temp.content);
            in_list.push_back (temp.date);
            in_list.push_back (temp.writerName);

            QTreeWidgetItem *item = new QTreeWidgetItem(in_list);
            ui->treeWidget->addTopLevelItem (item);
        }
    }
}


void DiaryDisp::on_pushButton_clicked()
{
    QString dateFrom = ui->dateFromEdit->text ();
    QString dateTo = ui->dateToEdit->text ();
    emit diaries(this,dateFrom,dateTo);
}

void DiaryDisp::diary_content (QTreeWidgetItem *item, int posi)
{
    int index = ui->treeWidget->indexOfTopLevelItem (item);
    ui->textBrowser->setText (content->at (index));
}
