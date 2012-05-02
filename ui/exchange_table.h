#ifndef EXCHANGE_TABLE_H
#define EXCHANGE_TABLE_H

#include <QWidget>

namespace Ui {
    class Exchange_table;
}

class Exchange_table : public QWidget
{
    Q_OBJECT

public:
    explicit Exchange_table(QWidget *parent = 0);
    ~Exchange_table();
    static const int table_id = 0;
public slots:
    void dispstatus(QByteArray);

private:
    Ui::Exchange_table *ui;

private slots:
    void on_btnNext_pressed();
    void on_btnNext_released();
    void on_btnNext_clicked();
signals:
    //�������ź������ڲ�ͬ����������л�
    //������ʾҪ��ת���Ĳ����ţ���Ŵ�0��ʼ��
    void next(int);
    void pre(int);
    void send_exchg_table(Exchange_table *,QByteArray);
};

#endif // EXCHANGE_TABLE_H
