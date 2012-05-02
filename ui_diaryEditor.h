/********************************************************************************
** Form generated from reading UI file 'diaryEditor.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIARYEDITOR_H
#define UI_DIARYEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiaryEditor
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QDateEdit *dateEdit;
    QLabel *label;
    QLineEdit *titleEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPlainTextEdit *contentEdit;
    QPushButton *handinBtn;
    QPushButton *cancleBtn;
    QLabel *label_4;
    QLineEdit *nameEdit;

    void setupUi(QWidget *DiaryEditor)
    {
        if (DiaryEditor->objectName().isEmpty())
            DiaryEditor->setObjectName(QString::fromUtf8("DiaryEditor"));
        DiaryEditor->resize(645, 561);
        scrollArea = new QScrollArea(DiaryEditor);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 601, 531));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 599, 529));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 571, 511));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(70, 70, 110, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 54, 12));
        titleEdit = new QLineEdit(groupBox);
        titleEdit->setObjectName(QString::fromUtf8("titleEdit"));
        titleEdit->setGeometry(QRect(70, 20, 113, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 54, 12));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 130, 54, 12));
        contentEdit = new QPlainTextEdit(groupBox);
        contentEdit->setObjectName(QString::fromUtf8("contentEdit"));
        contentEdit->setGeometry(QRect(10, 160, 501, 261));
        handinBtn = new QPushButton(groupBox);
        handinBtn->setObjectName(QString::fromUtf8("handinBtn"));
        handinBtn->setGeometry(QRect(430, 40, 75, 23));
        cancleBtn = new QPushButton(groupBox);
        cancleBtn->setObjectName(QString::fromUtf8("cancleBtn"));
        cancleBtn->setGeometry(QRect(430, 110, 75, 23));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 450, 54, 12));
        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(70, 450, 113, 20));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(DiaryEditor);

        QMetaObject::connectSlotsByName(DiaryEditor);
    } // setupUi

    void retranslateUi(QWidget *DiaryEditor)
    {
        DiaryEditor->setWindowTitle(QApplication::translate("DiaryEditor", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DiaryEditor", "\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DiaryEditor", "\346\240\207\351\242\230", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DiaryEditor", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DiaryEditor", "\346\255\243\346\226\207", 0, QApplication::UnicodeUTF8));
        handinBtn->setText(QApplication::translate("DiaryEditor", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        cancleBtn->setText(QApplication::translate("DiaryEditor", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DiaryEditor", "\344\275\234\350\200\205\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DiaryEditor: public Ui_DiaryEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIARYEDITOR_H
