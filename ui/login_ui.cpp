#include "login_ui.h"
#include "ui_login_ui.h"

Login_ui::Login_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_ui)
{
    ui->setupUi(this);
    connect(ui->toleftbtn,SIGNAL(pressed()),this,SLOT(on_toleftbtn_pressed()));
    connect(ui->toleftbtn,SIGNAL(released()),this,SLOT(on_toleftbtn_released()));
}

Login_ui::~Login_ui()
{
    delete ui;
}

void Login_ui::on_toleftbtn_pressed()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_left90_on.png"));
    ui->toleftbtn->setIcon(icon);
}

void Login_ui::on_toleftbtn_released()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_left90.png"));
    ui->toleftbtn->setIcon(icon);
    this->reject ();
    this->close ();
}

void Login_ui::on_torightbtn_pressed()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_right90_on.png"));
    ui->torightbtn->setIcon(icon);
}

void Login_ui::on_torightbtn_released()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/invagate/icons/to_right90.png"));
    ui->torightbtn->setIcon(icon);
}

void Login_ui::on_torightbtn_clicked()
{
    QString name = ui->nameEdit->text ();
    QString passwd = ui->passwdEdit->text ();
    QByteArray data;
    QDataStream ds(&data,QIODevice::ReadWrite);
    ds<<name.toUtf8 ()<<passwd.toUtf8 ();
    QByteArray temp;
    QDataStream ds2(&temp,QIODevice::ReadWrite);
    ds2<<data.size ();

    data += temp;

    emit authorise(data);
}

void Login_ui::on_toleftbtn_clicked()
{
    emit cancle_login();
}

void Login_ui::auth_fail ()
{
    //nowAt
    ui->status->setText (QString(tr("用户名或密码不正确")));
}
