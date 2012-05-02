#ifndef EXCEPEDITOR_H
#define EXCEPEDITOR_H

#include <QWidget>

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
//    显示服务器返回的状态
    void rcvData(QByteArray data);
private:
    Ui::ExcepEditor *ui;

private slots:
    void on_handinButton_clicked();
signals:
//    info包含了所有从界面获得的数据，info的长度是8
    void handin_excep(ExcepEditor*,QString *info);
};

#endif // EXCEPEDITOR_H
