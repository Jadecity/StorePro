#ifndef GLOBALDATATYPE_H
#define GLOBALDATATYPE_H
#include <QString>
struct PosiInfo
{
   QString goodname;
   int stayedtime;
   int toStay;
   double price;
   int amount;
   QString unit;//unit is evalued how amount is measured
   QString owner;
};

struct GoodInfo
{
    int posi[2];
    QString name;
    double price;
    int amount;
   QString unit;
   QString owner;
   QString arriveTime;
};

struct Diary
{
    QString title;
    QString content;
    QString date;
    QString writerName;
//    用户不需要输入ID
//    QString writerId;
};

struct StoreStatus
{
//    总容量
    long totalCap;
//    剩余容量
    long remainCap;
//    货物总量
    long totalGoods;
//    所存货物总值
    long totalVal;
};

struct IncRank
{
//    排名
    int rank;
//    公司名称
    QString Inc_name;
//    频度计数
//    显示单位是 笔/月
    int count;
//    总共交易金额
    double trans_amnt;
//    负责人名字
    QString mgrName;
};
#endif // GLOBALDATATYPE_H
