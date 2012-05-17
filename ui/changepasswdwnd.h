#ifndef CHANGEPASSWDWND_H
#define CHANGEPASSWDWND_H

#include <QWidget>

namespace Ui {
class ChangePasswdWnd;
}

class ChangePasswdWnd : public QWidget
{
    Q_OBJECT
    
public:
    explicit ChangePasswdWnd(QWidget *parent = 0);
    ~ChangePasswdWnd();
    QString getOld();
    QString getNew();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
public slots:
    void dispInfo(QByteArray);
signals:
    void changeButtonClicked(ChangePasswdWnd *);
    void dataOk();
private:
    Ui::ChangePasswdWnd *ui;
    QString old;
    QString newone;
private:
    int checkInput();
};

#endif // CHANGEPASSWDWND_H
