#ifndef OUTSTORE_TABLE_H
#define OUTSTORE_TABLE_H

#include <QWidget>


namespace Ui {
    class Outstore_table;
}

class Outstore_table : public QWidget
{
    Q_OBJECT

public:
    explicit Outstore_table(QWidget *parent = 0);
    ~Outstore_table();
    static const int table_id = 3;
public slots:
    void dispstatus(int,QByteArray);
private:
    Ui::Outstore_table *ui;

private slots:
    void on_btnNext_clicked();
    void on_btnNext_released();
    void on_btnNext_pressed();
    void on_btnBack_released();
    void on_btnBack_pressed();
signals:
    //�������ź������ڲ�ͬ����������л�
    //������ʾҪ��ת���Ĳ����ţ���Ŵ�0��ʼ��
    void next(int);
    void pre(int);
//    ���ͳ����
    void outstore_signal(Outstore_table *,QByteArray);
};

#endif // OUTSTORE_TABLE_H
