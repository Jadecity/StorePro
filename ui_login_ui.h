/********************************************************************************
** Form generated from reading UI file 'login_ui.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_UI_H
#define UI_LOGIN_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Login_ui
{
public:
    QPushButton *toleftbtn;
    QPushButton *torightbtn;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QLabel *label;
    QLineEdit *nameEdit;
    QSplitter *splitter;
    QLabel *label_2;
    QLineEdit *passwdEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *status;

    void setupUi(QDialog *Login_ui)
    {
        if (Login_ui->objectName().isEmpty())
            Login_ui->setObjectName(QString::fromUtf8("Login_ui"));
        Login_ui->resize(483, 268);
        Login_ui->setMinimumSize(QSize(483, 268));
        Login_ui->setMaximumSize(QSize(483, 268));
        Login_ui->setSizeGripEnabled(false);
        toleftbtn = new QPushButton(Login_ui);
        toleftbtn->setObjectName(QString::fromUtf8("toleftbtn"));
        toleftbtn->setEnabled(true);
        toleftbtn->setGeometry(QRect(20, 150, 51, 81));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/invagate/icons/to_left90.png"), QSize(), QIcon::Normal, QIcon::Off);
        toleftbtn->setIcon(icon);
        toleftbtn->setIconSize(QSize(90, 90));
        toleftbtn->setFlat(false);
        torightbtn = new QPushButton(Login_ui);
        torightbtn->setObjectName(QString::fromUtf8("torightbtn"));
        torightbtn->setGeometry(QRect(400, 150, 51, 81));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/invagate/icons/to_right90.png"), QSize(), QIcon::Normal, QIcon::Off);
        torightbtn->setIcon(icon1);
        torightbtn->setIconSize(QSize(90, 90));
        torightbtn->setAutoDefault(false);
        torightbtn->setDefault(false);
        torightbtn->setFlat(false);
        splitter_3 = new QSplitter(Login_ui);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(110, 150, 251, 81));
        splitter_3->setOrientation(Qt::Vertical);
        splitter_3->setOpaqueResize(true);
        splitter_3->setHandleWidth(10);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName(QString::fromUtf8("label"));
        splitter_2->addWidget(label);
        nameEdit = new QLineEdit(splitter_2);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setMaxLength(32767);
        nameEdit->setCursorPosition(6);
        splitter_2->addWidget(nameEdit);
        splitter_3->addWidget(splitter_2);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        splitter->addWidget(label_2);
        passwdEdit = new QLineEdit(splitter);
        passwdEdit->setObjectName(QString::fromUtf8("passwdEdit"));
        passwdEdit->setEchoMode(QLineEdit::Password);
        splitter->addWidget(passwdEdit);
        splitter_3->addWidget(splitter);
        label_3 = new QLabel(Login_ui);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 240, 24, 16));
        label_4 = new QLabel(Login_ui);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 240, 54, 12));
        label_5 = new QLabel(Login_ui);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 0, 301, 141));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/invagate/icons/dragon_phoenix.png")));
        status = new QLabel(Login_ui);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(110, 250, 241, 16));

        retranslateUi(Login_ui);

        QMetaObject::connectSlotsByName(Login_ui);
    } // setupUi

    void retranslateUi(QDialog *Login_ui)
    {
        Login_ui->setWindowTitle(QApplication::translate("Login_ui", "Dialog", 0, QApplication::UnicodeUTF8));
        toleftbtn->setText(QString());
        torightbtn->setText(QString());
        label->setText(QApplication::translate("Login_ui", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        nameEdit->setText(QApplication::translate("Login_ui", "\345\234\250\346\255\244\350\276\223\345\205\245\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Login_ui", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        passwdEdit->setText(QApplication::translate("Login_ui", "\345\234\250\346\255\244\350\276\223\345\205\245\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Login_ui", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Login_ui", "\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        status->setText(QApplication::translate("Login_ui", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login_ui: public Ui_Login_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_UI_H
