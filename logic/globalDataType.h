#ifndef GLOBALDATATYPE_H
#define GLOBALDATATYPE_H
#include <QString>
struct PosiInfo
{
   QString goodname;
//   int toStay;
   double price;
   int amount;
   QString unit;//unit is evalued how amount is measured
   QString owner;
   QString arrivetime;
};

struct GoodInfo
{

    QString name;
//  int toStay;
    int posi[2];
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
//    �û�����Ҫ����ID
//    QString writerId;
};

struct StoreStatus
{
//    ������
    long totalCap;
//    ʣ������
    long remainCap;
//    ��������
    long totalGoods;
//    ���������ֵ
    long totalVal;
};

struct IncRank
{
//    ����
    int rank;
//    ��˾����
    QString Inc_name;
//    Ƶ�ȼ���
//    ��ʾ��λ�� ��/��
//    int count;
//    �ܹ����׽��
    double trans_amnt;
//    ����������
//    QString mgrName;
};

struct Throughout
{
//    ��ǰֵ
    qint64 totalnum;
//    ����������λ�Ǽ�
    qint64 num;
//    ��ʷͬ��
    qint64 history;
//    ����
    float fudong;
////    ƽ��
//     int avrg;
};

struct Wastage
{
//    ��������
    qint64 wastage;
//    ������
    qint64 total;
//    ����
    float ratio;
};
#endif // GLOBALDATATYPE_H
