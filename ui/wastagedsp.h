#ifndef WASTAGEDSP_H
#define WASTAGEDSP_H

#include <QWidget>

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
//    ���ղ���ʾ����
    void rcvData(QByteArray data);
private:
    Ui::WastageDsp *ui;
};

#endif // WASTAGEDSP_H