/********************************************************************************
** Form generated from reading UI file 'excepEditor.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCEPEDITOR_H
#define UI_EXCEPEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExcepEditor
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPlainTextEdit *absEdit;
    QLabel *label;
    QLineEdit *titleEdit;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_7;
    QPlainTextEdit *detailEdit;
    QPlainTextEdit *reasonEdit;
    QPlainTextEdit *schemeEdit;
    QLineEdit *handlerIDEdit;
    QLineEdit *handlerNameEdit;
    QPushButton *cancleButton;
    QPushButton *handinButton;

    void setupUi(QWidget *ExcepEditor)
    {
        if (ExcepEditor->objectName().isEmpty())
            ExcepEditor->setObjectName(QString::fromUtf8("ExcepEditor"));
        ExcepEditor->resize(676, 563);
        scrollArea = new QScrollArea(ExcepEditor);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 631, 531));
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 962, 972));
        absEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        absEdit->setObjectName(QString::fromUtf8("absEdit"));
        absEdit->setGeometry(QRect(70, 60, 501, 81));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 54, 12));
        titleEdit = new QLineEdit(scrollAreaWidgetContents);
        titleEdit->setObjectName(QString::fromUtf8("titleEdit"));
        titleEdit->setGeometry(QRect(70, 30, 491, 20));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 54, 12));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 850, 54, 12));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 920, 141, 16));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 54, 12));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 600, 54, 12));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 360, 54, 12));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 880, 71, 16));
        detailEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        detailEdit->setObjectName(QString::fromUtf8("detailEdit"));
        detailEdit->setGeometry(QRect(70, 150, 501, 161));
        reasonEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        reasonEdit->setObjectName(QString::fromUtf8("reasonEdit"));
        reasonEdit->setGeometry(QRect(70, 380, 501, 211));
        schemeEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        schemeEdit->setObjectName(QString::fromUtf8("schemeEdit"));
        schemeEdit->setGeometry(QRect(70, 620, 501, 171));
        schemeEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        schemeEdit->setTabChangesFocus(false);
        schemeEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        handlerIDEdit = new QLineEdit(scrollAreaWidgetContents);
        handlerIDEdit->setObjectName(QString::fromUtf8("handlerIDEdit"));
        handlerIDEdit->setGeometry(QRect(80, 850, 471, 20));
        handlerNameEdit = new QLineEdit(scrollAreaWidgetContents);
        handlerNameEdit->setObjectName(QString::fromUtf8("handlerNameEdit"));
        handlerNameEdit->setGeometry(QRect(90, 880, 461, 20));
        cancleButton = new QPushButton(scrollAreaWidgetContents);
        cancleButton->setObjectName(QString::fromUtf8("cancleButton"));
        cancleButton->setGeometry(QRect(480, 930, 75, 23));
        handinButton = new QPushButton(scrollAreaWidgetContents);
        handinButton->setObjectName(QString::fromUtf8("handinButton"));
        handinButton->setGeometry(QRect(400, 910, 75, 23));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(ExcepEditor);

        QMetaObject::connectSlotsByName(ExcepEditor);
    } // setupUi

    void retranslateUi(QWidget *ExcepEditor)
    {
        ExcepEditor->setWindowTitle(QApplication::translate("ExcepEditor", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ExcepEditor", "\346\240\207\351\242\230", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ExcepEditor", "\346\221\230\350\246\201", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ExcepEditor", "\345\244\204\347\220\206\344\272\272ID", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ExcepEditor", "\346\227\266\351\227\264\357\274\210\347\224\261\347\263\273\347\273\237\350\207\252\345\212\250\350\216\267\345\217\226\357\274\211", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ExcepEditor", "\350\257\246\347\273\206\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ExcepEditor", "\345\244\204\347\220\206\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ExcepEditor", "\345\217\221\347\224\237\345\216\237\345\233\240", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ExcepEditor", "\345\244\204\347\220\206\344\272\272\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        cancleButton->setText(QApplication::translate("ExcepEditor", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        handinButton->setText(QApplication::translate("ExcepEditor", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExcepEditor: public Ui_ExcepEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCEPEDITOR_H
