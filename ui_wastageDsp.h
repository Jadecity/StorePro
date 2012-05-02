/********************************************************************************
** Form generated from reading UI file 'wastageDsp.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WASTAGEDSP_H
#define UI_WASTAGEDSP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WastageDsp
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *wstNoLabel;
    QLabel *totalLabel;
    QLabel *wstRateLabel;
    QLabel *tuliLabel;

    void setupUi(QWidget *WastageDsp)
    {
        if (WastageDsp->objectName().isEmpty())
            WastageDsp->setObjectName(QString::fromUtf8("WastageDsp"));
        WastageDsp->resize(573, 419);
        label = new QLabel(WastageDsp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 40, 121, 20));
        label_2 = new QLabel(WastageDsp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 200, 61, 16));
        label_3 = new QLabel(WastageDsp);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 250, 54, 12));
        label_4 = new QLabel(WastageDsp);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 290, 54, 12));
        wstNoLabel = new QLabel(WastageDsp);
        wstNoLabel->setObjectName(QString::fromUtf8("wstNoLabel"));
        wstNoLabel->setGeometry(QRect(170, 200, 54, 12));
        totalLabel = new QLabel(WastageDsp);
        totalLabel->setObjectName(QString::fromUtf8("totalLabel"));
        totalLabel->setGeometry(QRect(160, 250, 54, 12));
        wstRateLabel = new QLabel(WastageDsp);
        wstRateLabel->setObjectName(QString::fromUtf8("wstRateLabel"));
        wstRateLabel->setGeometry(QRect(150, 290, 54, 12));
        tuliLabel = new QLabel(WastageDsp);
        tuliLabel->setObjectName(QString::fromUtf8("tuliLabel"));
        tuliLabel->setGeometry(QRect(390, 200, 54, 12));

        retranslateUi(WastageDsp);

        QMetaObject::connectSlotsByName(WastageDsp);
    } // setupUi

    void retranslateUi(QWidget *WastageDsp)
    {
        WastageDsp->setWindowTitle(QApplication::translate("WastageDsp", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WastageDsp", "\350\277\231\351\207\214\345\272\224\350\257\245\346\230\257\344\270\252\345\234\206\351\245\274\345\233\276", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WastageDsp", "\347\240\264\346\215\237\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WastageDsp", "\346\200\273\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WastageDsp", "\347\240\264\346\215\237\346\257\224\344\276\213", 0, QApplication::UnicodeUTF8));
        wstNoLabel->setText(QApplication::translate("WastageDsp", "no", 0, QApplication::UnicodeUTF8));
        totalLabel->setText(QApplication::translate("WastageDsp", "no", 0, QApplication::UnicodeUTF8));
        wstRateLabel->setText(QApplication::translate("WastageDsp", "no", 0, QApplication::UnicodeUTF8));
        tuliLabel->setText(QApplication::translate("WastageDsp", "\345\233\276\344\276\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WastageDsp: public Ui_WastageDsp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WASTAGEDSP_H
