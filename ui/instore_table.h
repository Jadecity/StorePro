#ifndef INSTORE_TABLE_H
#define INSTORE_TABLE_H

#include <QWidget>
#include <QMessageBox>
namespace Ui {
    class Instore_table;
}

class Instore_table : public QWidget
{
    Q_OBJECT

public:
    explicit Instore_table(QWidget *parent = 0);
    ~Instore_table();
    static const int table_id = 1;
private:
    Ui::Instore_table *ui;
    QMessageBox *msg;
private slots:
    void on_btnNext_clicked();
    void on_btnNext_released();
    void on_btnNext_pressed();
    void on_btnBack_released();
    void on_btnBack_pressed();
    void delMsg();
public slots:
    void dispstatus(int flag, QByteArray info);
signals:
    //�������ź������ڲ�ͬ����������л�
    //������ʾҪ��ת���Ĳ����ţ���Ŵ�0��ʼ��
    void next(int);
    void pre(int);
    //    �����������
    void instore_signal(Instore_table *,QByteArray);
};

#endif // INSTORE_TABLE_H
