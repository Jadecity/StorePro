#include "createuserwnd.h"
#include "ui_createuserwnd.h"

CreateUserWnd::CreateUserWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateUserWnd)
{
    ui->setupUi(this);
}

CreateUserWnd::~CreateUserWnd()
{
    delete ui;
}

void CreateUserWnd::on_pushButton_clicked()
{
//    check input first
    switch(checkInput())
    {
//    ok
    case 0:
    {
        this->name = ui->nameEdit->text();
        this->passwd = ui->passwdEdit->text();
        emit createButtonClicked(this);
    }
        break;
//        name error
    case 1:
        break;
//        passwd not the same
    case 2:
        break;
    default:
        break;
    }

}
QString CreateUserWnd::getName()
{
    return this->name;
}
QString CreateUserWnd::getPasswd()
{
    return this->passwd;
}
int CreateUserWnd::checkInput()
{
    QString t_name = ui->nameEdit->text();
    QString t_passwd = ui->passwdEdit->text();
    QString t_passwdConfirm = ui->passwdConfirm->text();

    int flag = 0;
    if(t_name.contains(QString(" ")))
    {
        flag = 1;

    }else if(!t_passwd.compare(t_passwdConfirm)){
        flag = 2;
    }
    return flag;
}

void CreateUserWnd::dispInfo(QByteArray data)
{
    emit  dataOk();
}
