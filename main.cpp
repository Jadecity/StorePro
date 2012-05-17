#include <QtGui/QApplication>
#include <QTextCodec>
#include "ui/login_ui.h"
#include "ui/mainwindow.h"
#include "logic/testnetconnector.h"

#include "client.h"
QString currentUser;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::addLibraryPath("./plugins");
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    Client *client = new Client;
    client->start ();

    return a.exec();
}
