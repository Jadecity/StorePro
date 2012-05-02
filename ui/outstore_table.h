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
    //这两个信号用于在不同步骤间连续切换
    //参数表示要跳转到的步骤标号（标号从0开始）
    void next(int);
    void pre(int);
//    发送出库表
    void outstore_signal(Outstore_table *,QByteArray);
};

#endif // OUTSTORE_TABLE_H
