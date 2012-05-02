/********************************************************************************
** Form generated from reading UI file 'throughoutDisp.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THROUGHOUTDISP_H
#define UI_THROUGHOUTDISP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThroughoutDisp
{
public:
    QLabel *this_thatLabel;
    QLabel *this_or_nextMonth;
    QLabel *avrg;
    QLabel *label_4;
    QLabel *history;
    QLabel *label_3;
    QLabel *tuliLabel;
    QLabel *label_2;
    QLabel *floating;
    QLabel *label_6;

    void setupUi(QWidget *ThroughoutDisp)
    {
        if (ThroughoutDisp->objectName().isEmpty())
            ThroughoutDisp->setObjectName(QString::fromUtf8("ThroughoutDisp"));
        ThroughoutDisp->resize(528, 466);
        this_thatLabel = new QLabel(ThroughoutDisp);
        this_thatLabel->setObjectName(QString::fromUtf8("this_thatLabel"));
        this_thatLabel->setGeometry(QRect(60, 250, 71, 20));
        this_or_nextMonth = new QLabel(ThroughoutDisp);
        this_or_nextMonth->setObjectName(QString::fromUtf8("this_or_nextMonth"));
        this_or_nextMonth->setGeometry(QRect(150, 250, 54, 12));
        avrg = new QLabel(ThroughoutDisp);
        avrg->setObjectName(QString::fromUtf8("avrg"));
        avrg->setGeometry(QRect(140, 340, 54, 12));
        label_4 = new QLabel(ThroughoutDisp);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 340, 54, 12));
        history = new QLabel(ThroughoutDisp);
        history->setObjectName(QString::fromUtf8("history"));
        history->setGeometry(QRect(150, 280, 54, 12));
        label_3 = new QLabel(ThroughoutDisp);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 310, 54, 12));
        tuliLabel = new QLabel(ThroughoutDisp);
        tuliLabel->setObjectName(QString::fromUtf8("tuliLabel"));
        tuliLabel->setGeometry(QRect(360, 250, 54, 12));
        label_2 = new QLabel(ThroughoutDisp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 280, 54, 12));
        floating = new QLabel(ThroughoutDisp);
        floating->setObjectName(QString::fromUtf8("floating"));
        floating->setGeometry(QRect(140, 310, 54, 12));
        label_6 = new QLabel(ThroughoutDisp);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 50, 171, 16));

        retranslateUi(ThroughoutDisp);

        QMetaObject::connectSlotsByName(ThroughoutDisp);
    } // setupUi

    void retranslateUi(QWidget *ThroughoutDisp)
    {
        ThroughoutDisp->setWindowTitle(QApplication::translate("ThroughoutDisp", "Form", 0, QApplication::UnicodeUTF8));
        this_thatLabel->setText(QApplication::translate("ThroughoutDisp", "\346\234\254\346\234\210\345\220\236\345\220\220\357\274\232", 0, QApplication::UnicodeUTF8));
        this_or_nextMonth->setText(QApplication::translate("ThroughoutDisp", "no", 0, QApplication::UnicodeUTF8));
        avrg->setText(QApplication::translate("ThroughoutDisp", "avg", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ThroughoutDisp", "\345\271\263\345\235\207\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        history->setText(QApplication::translate("ThroughoutDisp", "no", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ThroughoutDisp", "\346\265\256\345\212\250\357\274\232", 0, QApplication::UnicodeUTF8));
        tuliLabel->setText(QApplication::translate("ThroughoutDisp", "\345\233\276\344\276\213", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ThroughoutDisp", "\345\216\206\345\217\262\345\220\214\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        floating->setText(QApplication::translate("ThroughoutDisp", "floting", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ThroughoutDisp", "\350\277\231\344\270\252\344\275\215\347\275\256\345\272\224\350\257\245\346\230\257\344\270\252\345\234\206\351\245\274\345\233\276", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ThroughoutDisp: public Ui_ThroughoutDisp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THROUGHOUTDISP_H
