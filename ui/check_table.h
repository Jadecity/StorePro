#ifndef CHECK_TABLE_H
#define CHECK_TABLE_H

#include <QWidget>
#include <QMessageBox>
namespace Ui {
    class Check_table;
}

class Check_table : public QWidget
{
    Q_OBJECT

public:
    explicit Check_table(QWidget *parent = 0);
    ~Check_table();
    static const int table_id = 2;
public slots:
    void dispstatus(int,QByteArray);
private:
    Ui::Check_table *ui;
    QMessageBox *msg;

private slots:
    void on_btnNext_clicked();
    void on_btnNext_released();
    void on_btnNext_pressed();
    void on_btnBack_released();
    void on_btnBack_pressed();
    void delMsg();
signals:
    //这两个信号用于在不同步骤间连续切换
    //参数表示要跳转到的步骤标号（标号从0开始）
    void next(int);
    void pre(int);
//    发送验货单
    void send_chk_table(Check_table *,QByteArray);
};

#endif // CHECK_TABLE_H
