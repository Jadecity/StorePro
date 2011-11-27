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

void AskGoodToLookDlg::rcvData (QByteArray data)
{
    //nowAt
}
