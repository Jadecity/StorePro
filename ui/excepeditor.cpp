#include "excepeditor.h"
#include "ui_excepEditor.h"
#include <QTime>
ExcepEditor::ExcepEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExcepEditor)
{
    ui->setupUi(this);
}

ExcepEditor::~ExcepEditor()
{
    delete ui;
}

void ExcepEditor::on_handinButton_clicked()
{
//    获得所有数据
    QString title = ui->titleEdit->text ();
    QString abs = ui->absEdit->toPlainText ();
    QString des = ui->detailEdit->toPlainText ();
    QString reason = ui->reasonEdit->toPlainText ();
    QString deal = ui->schemeEdit->toPlainText ();
    QString id = ui->handlerIDEdit->text ();
    QString name = ui->handlerNameEdit->text ();
    QString time = QTime::currentTime ().toString ();

    QString *info = new QString[8];
    info[0] = title;
    info[1] = abs;
    info[2] = des;
    info[3] = reason;
    info[4] = deal;
    info[5] = id;
    info[6] = name;
    info[7] = time;

    emit handin_excep(this,info);
}

void ExcepEditor::rcvData (QByteArray data)
{
    QString str4(data);
        QLabel *lab = new QLabel(str4);
        lab->show ();
}
