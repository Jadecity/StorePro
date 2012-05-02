#ifndef STORESTATUSDSP_H
#define STORESTATUSDSP_H

#include <QWidget>

namespace Ui {
    class StoreStatusDsp;
}

class StoreStatusDsp : public QWidget
{
    Q_OBJECT

public:
    explicit StoreStatusDsp(QWidget *parent = 0);
    ~StoreStatusDsp();
public slots:
//    收到数据并显示
    void rcvData(QByteArray data);
private:
    Ui::StoreStatusDsp *ui;
};

#endif // STORESTATUSDSP_H
