#include "deluserwnd.h"
#include "ui_deluserwnd.h"
#include <QListWidgetItem>

DelUserWnd::DelUserWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DelUserWnd)
{
    ui->setupUi(this);
}

DelUserWnd::~DelUserWnd()
{
    delete ui;
}

void DelUserWnd::on_checkBox_stateChanged(int state)
{
    if(Qt::Unchecked == state)
    {
//        do not select all
    }else if(Qt::Checked == state)
    {
//select all
    }
}

void DelUserWnd::on_delButton_clicked()
{
    emit delAction(this);
}

void DelUserWnd::dispUser(QStringList users)
{

}

void DelUserWnd::dispInfo(QByteArray info)
{

}
