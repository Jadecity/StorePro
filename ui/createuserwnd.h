#ifndef CREATEUSERWND_H
#define CREATEUSERWND_H

#include <QWidget>
#include <QByteArray>
namespace Ui {
class CreateUserWnd;
}

class CreateUserWnd : public QWidget
{
    Q_OBJECT
    
public:
    explicit CreateUserWnd(QWidget *parent = 0);
    ~CreateUserWnd();
    QString getName();
    QString getPasswd();
public slots:
    void dispInfo(QByteArray);
private slots:
    void on_pushButton_clicked();
signals:
    void createButtonClicked(CreateUserWnd *);
    void dataOk();
private:
    Ui::CreateUserWnd *ui;
    QString name;
    QString passwd;
private:
    int checkInput();
};

#endif // CREATEUSERWND_H
