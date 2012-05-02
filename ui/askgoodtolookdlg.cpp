#include "askgoodtolookdlg.h"
#include "ui_askGoodToLookDlg.h"

AskGoodToLookDlg::AskGoodToLookDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AskGoodToLookDlg)
{
    ui->setupUi(this);
}

AskGoodToLookDlg::~AskGoodToLookDlg()
{
    delete ui;
}

void AskGoodToLookDlg::on_queryBtn_clicked()
{
    QString goodName = ui->editGoodName->text ();
    QString goodNo = ui->editGoodNo->text ();
    QString dateFrom = ui->dateFrom->date ().toString ();
    QString dateTo = ui->dateTo->date ().toString ();
    QString *info = new QString[4];
    info[0] = goodName;
    info[1] = goodNo;
    info[2] = dateFrom;
    info[3] = dateTo;

    emit query_good_info (this,info);
}

void AskGoodToLookDlg::rcvData (QList<GoodInfo> *list)
{
    //nowAt
    int num = list->size ();
    for(int i=0;i<num;i++)
    {
        QStringList qlist;
        qlist.push_back (list->at (i).name);
//      qlist.push_back (QString::number (list->at (i).toStay));
        qlist.push_back ("x:"+QString::number (list->at (i).posi[0]) + "y:"+QString::number (list->at (i).posi[1]));
        qlist.push_back (QString::number (list->at (i).price));
        qlist.push_back (QString::number (list->at (i).amount));
        qlist.push_back (list->at (i).unit);
        qlist.push_back (list->at (i).owner);
        qlist.push_back (list->at (i).arriveTime);
        QTreeWidgetItem *item = new QTreeWidgetItem(qlist);
        ui->treeWidget->addTopLevelItem (item);
    }

    delete list;
    list = NULL;
}
