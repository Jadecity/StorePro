#ifndef ASKGOODTOLOOKDLG_H
#define ASKGOODTOLOOKDLG_H

#include <QDialog>

namespace Ui {
    class AskGoodToLookDlg;
}

class AskGoodToLookDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AskGoodToLookDlg(QWidget *parent = 0);
    ~AskGoodToLookDlg();
public slots:
//    ���յ����ݣ�Ȼ����ʾ
    void rcvData(QByteArray data);

private:
    Ui::AskGoodToLookDlg *ui;

private slots:
    void on_queryBtn_clicked();
signals:
//    ��һ�������Ǳ����󣬵ڶ��������ǻ�ȡ�������ݵ�����
    void query_good_info(AskGoodToLookDlg*,QString *data);
};

#endif // ASKGOODTOLOOKDLG_H
