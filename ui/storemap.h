#ifndef STOREMAP_H
#define STOREMAP_H

#include <QWidget>
#include "logic/globalDataType.h"
namespace Ui {
    class StoreMap;
}

class StoreMap : public QWidget
{
    Q_OBJECT

public:
    explicit StoreMap(QWidget *parent = 0);
    ~StoreMap();
public slots:
    /*显示由外部传过来的数据，按照协议格式显示*/
    void rcvData(QList<PosiInfo> *list);

private:
    Ui::StoreMap *ui;

private slots:
    void on_okButton_clicked();
signals:
    /*the first is this pointer,then x,then y
    *this pointer is to be used outer
    */
    void fetch(StoreMap*,int,int);
};

#endif // STOREMAP_H
