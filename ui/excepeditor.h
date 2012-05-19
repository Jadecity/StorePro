#ifndef EXCEPEDITOR_H
#define EXCEPEDITOR_H

#include <QWidget>
#include <QMessageBox>
namespace Ui {
    class ExcepEditor;
}

class ExcepEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ExcepEditor(QWidget *parent = 0);
    ~ExcepEditor();
public slots:
//    ��ʾ���������ص�״̬
    void rcvData(QByteArray data);
    void delMsg();
private:
    Ui::ExcepEditor *ui;
    QMessageBox *msg;

private slots:
    void on_handinButton_clicked();
signals:
//    info���������дӽ����õ����ݣ�info�ĳ�����8
    void handin_excep(ExcepEditor*,QString *info);
};

#endif // EXCEPEDITOR_H
