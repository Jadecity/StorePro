#include "diaryeditor.h"
#include "ui_diaryEditor.h"
#include <QDialog>
#include<QMessageBox>
DiaryEditor::DiaryEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiaryEditor)
{
    ui->setupUi(this);
}

DiaryEditor::~DiaryEditor()
{
    delete ui;
}

void DiaryEditor::on_handinBtn_clicked()
{
//    获取数据

    QString title = ui->titleEdit->text ();
    QString content = ui->contentEdit->toPlainText ();
     QString date = ui->dateEdit->text ();
     QString name = ui->nameEdit->text ();

     QString *info = new QString[4];
    info[0]= title;
    info[1] = content;
    info[2] = date;
    info[3] = name;
    //to be del
        QMessageBox *msg = new 	QMessageBox;
        msg->addButton (QMessageBox::Ok);
        msg->setText (tr("日志已发出!"));
        msg->show ();
    emit handinDiary(this,info);
}

void DiaryEditor::rcvData (QByteArray mydata)
{
    QString status = QString::fromUtf8 (mydata.data ());
   QLabel *lable = new QLabel(status);
   lable->show ();
}
