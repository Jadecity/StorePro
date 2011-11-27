#include "diaryeditor.h"
#include "ui_diaryEditor.h"
#include <QDialog>
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
     QString date = ui->dateEdit->date ().toString ();
     QString name = ui->nameEdit->text ();
    QString *info = new QString[4];
    info[0]= title;
    info[1] = content;
    info[2] = date;
    info[3] = name;

    emit handinDiary(this,info);
}

void DiaryEditor::rcvData (QByteArray data)
{
    QString status(data);
   QLabel lable(status);
   lable.show ();
}
