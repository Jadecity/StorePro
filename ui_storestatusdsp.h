/********************************************************************************
** Form generated from reading UI file 'storestatusdsp.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORESTATUSDSP_H
#define UI_STORESTATUSDSP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoreStatusDsp
{
public:
    QGroupBox *groupBox;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *StoreStatusDsp)
    {
        if (StoreStatusDsp->objectName().isEmpty())
            StoreStatusDsp->setObjectName(QString::fromUtf8("StoreStatusDsp"));
        StoreStatusDsp->resize(400, 300);
        groupBox = new QGroupBox(StoreStatusDsp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 371, 271));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 20, 351, 241));

        retranslateUi(StoreStatusDsp);

        QMetaObject::connectSlotsByName(StoreStatusDsp);
    } // setupUi

    void retranslateUi(QWidget *StoreStatusDsp)
    {
        StoreStatusDsp->setWindowTitle(QApplication::translate("StoreStatusDsp", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("StoreStatusDsp", "\344\273\223\345\272\223\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StoreStatusDsp: public Ui_StoreStatusDsp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORESTATUSDSP_H
