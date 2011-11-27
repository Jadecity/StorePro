#include <QtGui/QApplication>
#include <QTextCodec>
#include "ui/login_ui.h"
#include "ui/mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   Login_ui login;
    //login.show ();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
    MainWindow *mwnd = new MainWindow;
    mwnd->show ();
    return a.exec();
}
