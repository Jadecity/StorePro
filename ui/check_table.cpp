#include "check_table.h"
#include "ui_check_table.h"
#include <QMessageBox>

Check_table::Check_table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Check_table)
{
    ui->setupUi(this);
}

Check_table::~Check_table()
{
    delete ui;
}

void Check_table::on_btnBack_pressed()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_left90_on.png"));
    ui->btnBack->setIcon(icon);
}

void Check_table::on_btnBack_released()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_left90.png"));
    ui->btnBack->setIcon(icon);
}

void Check_table::on_btnNext_pressed()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_right90_on.png"));
    ui->btnNext->setIcon(icon);
}

void Check_table::on_btnNext_released()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_right90.png"));
    ui->btnNext->setIcon(icon);
}


void Check_table::on_btnNext_clicked()
{
    QString id = ui->editID->text ();
    QString time = ui->dateTimeEdit->text ();

    QByteArray mydata;
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);

    ds<<id.toUtf8 ()<<time.toUtf8 ();

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
        QByteArray temp;
        QDataStream ds2(&temp,QIODevice::ReadWrite);
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
        cmd += mydata;
        emit send_chk_table (this,cmd);
        emit next(3);
    }
}

void Check_table::dispstatus (int flag, QByteArray data)
{
    QString str = QString::fromUtf8 (data.data ());
    QMessageBox *box = new QMessageBox;
    box->setText (str);
    box->addButton (QMessageBox::Ok);
    box->show ();
}
