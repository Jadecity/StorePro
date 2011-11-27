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
//    接收到数据，然后显示
    void rcvData(QByteArray data);

private:
    Ui::AskGoodToLookDlg *ui;

private slots:
    void on_queryBtn_clicked();
signals:
//    第一个参数是本对象，第二个参数是获取到的数据的数组
    void query_good_info(AskGoodToLookDlg*,QString *data);
};

#endif // ASKGOODTOLOOKDLG_H
