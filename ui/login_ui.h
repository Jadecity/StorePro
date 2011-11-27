#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include <QDialog>

namespace Ui {
    class Login_ui;
}

class Login_ui : public QDialog
{
    Q_OBJECT

public:
    explicit Login_ui(QWidget *parent = 0);
    ~Login_ui();
    void auth_fail();
private:
    Ui::Login_ui *ui;

private slots:
    void on_toleftbtn_clicked();
    void on_torightbtn_clicked();
    void on_torightbtn_released();
    void on_torightbtn_pressed();
    void on_toleftbtn_released();
    void on_toleftbtn_pressed();
signals:
//    请求验证用户
    void authorise(QByteArray);
//    取消登录
    void cancle_login();
};

#endif // LOGIN_UI_H
