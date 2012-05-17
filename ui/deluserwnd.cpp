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
    QList<QListWidgetItem *> selected =	ui->listWidget->selectedItems ();
    QString user;
    for(int i=0;i<selected.count();i++)
    {
        user = selected.at(i)->text();
        this->usersToDel.append(user);
    }
    emit delAction(this);
}

void DelUserWnd::dispUser(QStringList users)
{
    for(int i=0;i<users.count();i++)
    {
        QListWidgetItem *item = new QListWidgetItem(users.at(i));
        item->setCheckState(Qt::Unchecked);
        ui->listWidget->addItem(item);
    }
}

void DelUserWnd::dispInfo(QByteArray info)
{

}

QStringList DelUserWnd::getSelected()
{
    return this->usersToDel;
}
