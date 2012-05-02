#ifndef WASTAGEDSP_H
#define WASTAGEDSP_H

#include <QWidget>
#include "logic/globalDataType.h"
namespace Ui {
    class WastageDsp;
}

class WastageDsp : public QWidget
{
    Q_OBJECT

public:
    explicit WastageDsp(QWidget *parent = 0);
    ~WastageDsp();
public slots:
//    接收并显示数据
    void rcvData(Wastage data);
private:
    Ui::WastageDsp *ui;
};

#endif // WASTAGEDSP_H
