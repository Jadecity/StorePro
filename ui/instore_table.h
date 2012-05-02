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
    //这两个信号用于在不同步骤间连续切换
    //参数表示要跳转到的步骤标号（标号从0开始）
    void next(int);
    void pre(int);
    //    发送入库数据
    void instore_signal(Instore_table *,QByteArray);
};

#endif // INSTORE_TABLE_H
