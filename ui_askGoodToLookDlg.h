/********************************************************************************
** Form generated from reading UI file 'askGoodToLookDlg.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASKGOODTOLOOKDLG_H
#define UI_ASKGOODTOLOOKDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AskGoodToLookDlg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *editGoodName;
    QLineEdit *editGoodNo;
    QLabel *label_3;
    QDateEdit *dateFrom;
    QLabel *label_4;
    QFrame *line;
    QLabel *label_5;
    QDateEdit *dateTo;
    QPushButton *queryBtn;
    QPushButton *cancleBtn;
    QFrame *line_2;
    QGroupBox *groupBox;
    QListView *listView;

    void setupUi(QDialog *AskGoodToLookDlg)
    {
        if (AskGoodToLookDlg->objectName().isEmpty())
            AskGoodToLookDlg->setObjectName(QString::fromUtf8("AskGoodToLookDlg"));
        AskGoodToLookDlg->resize(818, 531);
        label = new QLabel(AskGoodToLookDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 131, 20));
        label_2 = new QLabel(AskGoodToLookDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 130, 121, 16));
        editGoodName = new QLineEdit(AskGoodToLookDlg);
        editGoodName->setObjectName(QString::fromUtf8("editGoodName"));
        editGoodName->setGeometry(QRect(50, 90, 113, 20));
        editGoodNo = new QLineEdit(AskGoodToLookDlg);
        editGoodNo->setObjectName(QString::fromUtf8("editGoodNo"));
        editGoodNo->setGeometry(QRect(50, 170, 113, 20));
        label_3 = new QLabel(AskGoodToLookDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 50, 101, 16));
        dateFrom = new QDateEdit(AskGoodToLookDlg);
        dateFrom->setObjectName(QString::fromUtf8("dateFrom"));
        dateFrom->setGeometry(QRect(330, 90, 110, 22));
        label_4 = new QLabel(AskGoodToLookDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 100, 54, 12));
        line = new QFrame(AskGoodToLookDlg);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(193, 50, 20, 141));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(AskGoodToLookDlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(260, 160, 54, 12));
        dateTo = new QDateEdit(AskGoodToLookDlg);
        dateTo->setObjectName(QString::fromUtf8("dateTo"));
        dateTo->setGeometry(QRect(330, 160, 110, 22));
        queryBtn = new QPushButton(AskGoodToLookDlg);
        queryBtn->setObjectName(QString::fromUtf8("queryBtn"));
        queryBtn->setGeometry(QRect(480, 90, 75, 23));
        cancleBtn = new QPushButton(AskGoodToLookDlg);
        cancleBtn->setObjectName(QString::fromUtf8("cancleBtn"));
        cancleBtn->setGeometry(QRect(480, 150, 75, 23));
        line_2 = new QFrame(AskGoodToLookDlg);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(50, 190, 521, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(AskGoodToLookDlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 200, 531, 331));
        listView = new QListView(groupBox);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 20, 511, 301));

        retranslateUi(AskGoodToLookDlg);

        QMetaObject::connectSlotsByName(AskGoodToLookDlg);
    } // setupUi

    void retranslateUi(QDialog *AskGoodToLookDlg)
    {
        AskGoodToLookDlg->setWindowTitle(QApplication::translate("AskGoodToLookDlg", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AskGoodToLookDlg", "\350\276\223\345\205\245\350\246\201\346\237\245\350\257\242\347\232\204\350\264\247\347\211\251\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AskGoodToLookDlg", "\350\276\223\345\205\245\350\264\247\345\217\267*", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AskGoodToLookDlg", "\351\200\211\346\213\251\345\205\245\345\272\223\346\227\266\351\227\264\346\256\265", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AskGoodToLookDlg", "\350\265\267\345\247\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AskGoodToLookDlg", "\347\273\210\346\255\242\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        queryBtn->setText(QApplication::translate("AskGoodToLookDlg", "\345\274\200\345\247\213\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        cancleBtn->setText(QApplication::translate("AskGoodToLookDlg", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AskGoodToLookDlg", "\350\264\247\347\211\251\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AskGoodToLookDlg: public Ui_AskGoodToLookDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASKGOODTOLOOKDLG_H
