#ifndef DELUSERWND_H
#define DELUSERWND_H

#include <QWidget>
#include <QStringList>
namespace Ui {
class DelUserWnd;
}

class DelUserWnd : public QWidget
{
    Q_OBJECT
    
public:
    explicit DelUserWnd(QWidget *parent = 0);
    ~DelUserWnd();
    QStringList getSelected();
public slots:
    void dispUsers(QStringList users);
    void dispInfo(QByteArray info);
private slots:
    void on_checkBox_stateChanged(int state);

    void on_delButton_clicked();
signals:
    void delAction(DelUserWnd * );
private:
    Ui::DelUserWnd *ui;
    QStringList usersToDel;
};

#endif // DELUSERWND_H
