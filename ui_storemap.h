/********************************************************************************
** Form generated from reading UI file 'storemap.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREMAP_H
#define UI_STOREMAP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoreMap
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *editX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *editY;
    QPushButton *okButton;
    QFrame *line;
    QGroupBox *groupBox;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *StoreMap)
    {
        if (StoreMap->objectName().isEmpty())
            StoreMap->setObjectName(QString::fromUtf8("StoreMap"));
        StoreMap->resize(589, 428);
        layoutWidget = new QWidget(StoreMap);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 30, 209, 52));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(18, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        editX = new QLineEdit(layoutWidget);
        editX->setObjectName(QString::fromUtf8("editX"));

        horizontalLayout->addWidget(editX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        editY = new QLineEdit(layoutWidget);
        editY->setObjectName(QString::fromUtf8("editY"));

        horizontalLayout_2->addWidget(editY);


        verticalLayout->addLayout(horizontalLayout_2);

        okButton = new QPushButton(StoreMap);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(420, 30, 75, 23));
        line = new QFrame(StoreMap);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(40, 90, 461, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(StoreMap);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 120, 461, 291));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(5, 21, 451, 261));

        retranslateUi(StoreMap);

        QMetaObject::connectSlotsByName(StoreMap);
    } // setupUi

    void retranslateUi(QWidget *StoreMap)
    {
        StoreMap->setWindowTitle(QApplication::translate("StoreMap", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StoreMap", "\350\276\223\345\205\245X\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StoreMap", "\350\276\223\345\205\245Y\357\274\232", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("StoreMap", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("StoreMap", "\345\275\223\345\211\215\344\275\215\347\275\256\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StoreMap: public Ui_StoreMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREMAP_H
