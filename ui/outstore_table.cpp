#include "outstore_table.h"
#include "ui_outstore_table.h"
#include <QMessageBox>
Outstore_table::Outstore_table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Outstore_table)
{
    ui->setupUi(this);
}

Outstore_table::~Outstore_table()
{
    delete ui;
}

void Outstore_table::on_btnBack_pressed()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_left90_on.png"));
    ui->btnBack->setIcon(icon);
}

void Outstore_table::on_btnBack_released()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_left90.png"));
    ui->btnBack->setIcon(icon);
}



void Outstore_table::on_btnNext_pressed()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_right90_on.png"));
    ui->btnNext->setIcon(icon);
}



void Outstore_table::on_btnNext_released()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_right90.png"));
    ui->btnNext->setIcon(icon);
}

void Outstore_table::on_btnNext_clicked()
{
    QString id = ui->editID->text ();
    QString time = ui->dateTimeEdit->text ();
    QString receiver = ui->editRecver->text ();

    QByteArray mydata;
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);

    ds<<id.toUtf8 ()<<time.toUtf8 ()<<receiver.toUtf8 ();

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
                ds2<<arr_space;//填充空项
                lineempty++;
            }
        }

        if(colum == lineempty)
        {
            continue;
        }
        else
        {
            mydata += temp;
            validrow++;
        }
    }

    if(0 != validrow)
    {
        cmd += mydata;
        emit outstore_signal (this,cmd);
        emit next(4);
    }
}

void Outstore_table::dispstatus (int flag,QByteArray rcved_data)
{
    QMessageBox *msg;
    if(0 == flag)
    {
        msg = new QMessageBox;
        msg->addButton (QMessageBox::Ok);
        msg->setText (QString::fromUtf8 (rcved_data));
        msg->show ();
    }else
    {
        msg = new QMessageBox;
        msg->addButton (QMessageBox::Ok);
        msg->setText ("操作成功");
        msg->show ();
    }
}
