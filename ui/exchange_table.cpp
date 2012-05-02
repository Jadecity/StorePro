#include "exchange_table.h"
#include "ui_exchange_table.h"

Exchange_table::Exchange_table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Exchange_table)
{
    ui->setupUi(this);
    ui->btnBack->setDisabled (true);
}

Exchange_table::~Exchange_table()
{
    delete ui;
}

void Exchange_table::on_btnNext_clicked()
{
    QByteArray mydata;
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);

    QString space(" ");
    QByteArray arr_space = space.toUtf8 ();

    int row;
    int colum;
    colum = ui->tableWidget->columnCount ();
    row = ui->tableWidget->rowCount ();

    int lineempty = 0;
    int validrow = 0;

    for(int i=0;i<row;i++)
    {
        lineempty = 0;
        for(int j=0;j<colum;j++)
        {
            QTableWidgetItem *item = ui->tableWidget->item (i,j);
            if(item)//item != null
            {
                QByteArray oo = item->data (Qt::DisplayRole).toByteArray ();
                ds2<<oo;
                if(0 == oo.size ())
                    lineempty++;
            }else
            {
                ds2<<arr_space;//Ìî³ä¿ÕÏî
                lineempty++;
            }
        }

        if(colum == lineempty)
        {
            temp.clear ();
            continue;
        }
        else
        {
            mydata += temp;
            temp.clear ();
            validrow++;
        }
    }

    if(0 != validrow)
    {
        ds<<validrow<<mydata;
        emit send_exchg_table (this,cmd);
        emit next(1);
    }
}

void Exchange_table::on_btnNext_released()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_right90.png"));
    ui->btnNext->setIcon(icon);
}

void Exchange_table::on_btnNext_pressed()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_right90_on.png"));
    ui->btnNext->setIcon(icon);
}

void Exchange_table::dispstatus (QByteArray rcved_data)
{
    QString str = QString::fromUtf8 (rcved_data.data ());
    //do show the content
}
