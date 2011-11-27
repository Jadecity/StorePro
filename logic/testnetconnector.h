#ifndef TESTNETCONNECTOR_H
#define TESTNETCONNECTOR_H

#include <QObject>
#include "net.h"
#include<windows.h>
#include<iostream>
using namespace std;

class testNetConnector : public QObject
{
    Q_OBJECT
public:
    explicit testNetConnector(QObject *parent = 0);

signals:

public slots:
    void startTest();

};

#endif // TESTNETCONNECTOR_H
