#include "changepasswdwnd.h"
#include "ui_changepasswdwnd.h"

ChangePasswdWnd::ChangePasswdWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePasswdWnd)
{
    ui->setupUi(this);
}

ChangePasswdWnd::~ChangePasswdWnd()
{
    delete ui;
}

void ChangePasswdWnd::on_pushButton_clicked()
{
    //    check input first
        switch(checkInput())
        {
    //    ok
        case 0:
        {
            this->old = ui->old->text();
            this->newone = ui->newone->text();
            emit changeButtonClicked(this);
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

void ChangePasswdWnd::on_pushButton_2_clicked()
{

}
QString ChangePasswdWnd::getOld()
{
    return this->old;
}
QString ChangePasswdWnd::getNew()
{
    return this->newone;
}
int ChangePasswdWnd::checkInput()
{
    QString t_old = ui->old->text();
    QString t_new = ui->newone->text();
    QString t_newConfirm = ui->newConfirm->text();

    int flag = 0;
    if(t_old.contains(QString(" ")))
    {
        flag = 1;

    }else if(!t_new.compare(t_newConfirm)){
        flag = 2;
    }
    return flag;
}

void ChangePasswdWnd::dispInfo(QByteArray data)
{
    emit  dataOk();
}
