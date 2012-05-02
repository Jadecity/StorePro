#include "statics.h"
using namespace Statics;
#ifdef DEBUG
#include <iostream>
using namespace std;
#endif
StaticCntr::StaticCntr(QObject *parent)
{

}

void StaticCntr::setDatacntr (DataTrans *dc)
{
    if(NULL!=dc)
    {
         this->datacntr = dc;
    }
}

void StaticCntr::recv (QByteArray data)
{
    QDataStream ds(&data,QIODevice::ReadOnly);
    char  *str;
    ds>>str;
    if(!strcmp(str,NOTHING))
    {
#ifdef DEBUG
        cout<<"server gives nothing"<<endl;
#endif
        return;
    }else
    {
        ds>>str;
        if(!strcmp (str,THIS_MONTH_THROUGHPUT))
        {
            Throughout in_out;
            ds>>in_out.num>>in_out.history>>in_out.fudong;
            emit disp(in_out);
        }else if(!strcmp(str,NEXT_MONTH_THROUGHPUT))
        {
            Throughout in_out;
            ds>>in_out.totalnum>>in_out.history>>in_out.fudong>>in_out.num;
            emit disp(in_out);
        }else if(!strcmp(str,GOOD_WASTAGE))
        {
            Wastage wst;
            ds>>wst.wastage>>wst.total>>wst.ratio;
            emit disp(wst);
        }else if(!strcmp (str,COMPANY_BUSY_RANK))
        {
            QList<IncRank> *list = new QList<IncRank>;
            int num;
            ds>>num;
            for(int i=0;i<num;i++)
            {
                IncRank rnk;
                ds>>rnk.rank;

                QByteArray name;
                ds>>name;
                rnk.Inc_name = QString::fromUtf8 (name);

                ds>>rnk.trans_amnt;
                list->push_back (rnk);
            }
            //nowAt
            //build list
            emit dispIncRank (list);
        }else if(!strcmp(str,OVERTIME))
        {
            //do default
            int amount=0;
            ds>>amount;
            emit overTimeAmount(amount);
        }
    }
}

void StaticCntr::thisMonthThroughout ()
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<GET<<THIS_MONTH_THROUGHPUT;
    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();
    cmd = temp  + cmd;

    datacntr->request (this,cmd);
}

void StaticCntr::predictNextMonthThroughout ()
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<GET<<NEXT_MONTH_THROUGHPUT;
    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();
    cmd = temp  + cmd;

    datacntr->request (this,cmd);
}

void StaticCntr::companyBusyDegree ()
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<GET<<COMPANY_BUSY_RANK;
    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();
    cmd = temp  + cmd;

    datacntr->request (this,cmd);
}

void StaticCntr::goodWastage()
{
    QByteArray cmd;
    QDataStream ds(&cmd,QIODevice::ReadWrite);
    ds<<GET<<GOOD_WASTAGE;
    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<cmd.size ();
    cmd = temp  + cmd;

    datacntr->request (this,cmd);
}

void StaticCntr::overTime()
{
    if(NULL != datacntr)
    {
        QByteArray cmd;
        QDataStream ds(&cmd,QIODevice::ReadWrite);
        ds<<GET<<OVERTIME;
        datacntr->request(this,cmd);
    }
}
