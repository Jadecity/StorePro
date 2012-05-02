/********************************************************************************
** Form generated from reading UI file 'diarydisp.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIARYDISP_H
#define UI_DIARYDISP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiaryDisp
{
public:
    QListWidget *listWidget;
    QFrame *line;
    QFrame *line_2;
    QWidget *widget;
    QLabel *label;

    void setupUi(QWidget *DiaryDisp)
    {
        if (DiaryDisp->objectName().isEmpty())
            DiaryDisp->setObjectName(QString::fromUtf8("DiaryDisp"));
        DiaryDisp->resize(826, 601);
        listWidget = new QListWidget(DiaryDisp);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 50, 741, 261));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        line = new QFrame(DiaryDisp);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(31, 296, 741, 41));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(DiaryDisp);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(31, 295, 741, 51));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(DiaryDisp);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 330, 741, 221));
        label = new QLabel(DiaryDisp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 54, 12));

        retranslateUi(DiaryDisp);

        QMetaObject::connectSlotsByName(DiaryDisp);
    } // setupUi

    void retranslateUi(QWidget *DiaryDisp)
    {
        DiaryDisp->setWindowTitle(QApplication::translate("DiaryDisp", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DiaryDisp", "\346\227\245\345\277\227\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DiaryDisp: public Ui_DiaryDisp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIARYDISP_H
