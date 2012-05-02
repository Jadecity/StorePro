/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Nov 27 23:28:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *printAct;
    QAction *quitAct;
    QAction *inStoreAct;
    QAction *outStoreAct;
    QAction *chkGoodAct;
    QAction *recExcepAct;
    QAction *wDiaryAct;
    QAction *diaryHisAct;
    QAction *mthrAct;
    QAction *nxtMthrAct;
    QAction *brknRateAct;
    QAction *rnkComAct;
    QAction *loginAct;
    QAction *logoutAct;
    QAction *newAcntAct;
    QAction *chpasswdAct;
    QAction *bkpasswdAct;
    QAction *manDocAct;
    QAction *faqAct;
    QAction *storHisAct;
    QAction *curStorAct;
    QAction *lookGoodByPosi;
    QAction *lookGoodByInfo;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(916, 700);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(false);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        printAct = new QAction(MainWindow);
        printAct->setObjectName(QString::fromUtf8("printAct"));
        quitAct = new QAction(MainWindow);
        quitAct->setObjectName(QString::fromUtf8("quitAct"));
        inStoreAct = new QAction(MainWindow);
        inStoreAct->setObjectName(QString::fromUtf8("inStoreAct"));
        outStoreAct = new QAction(MainWindow);
        outStoreAct->setObjectName(QString::fromUtf8("outStoreAct"));
        chkGoodAct = new QAction(MainWindow);
        chkGoodAct->setObjectName(QString::fromUtf8("chkGoodAct"));
        recExcepAct = new QAction(MainWindow);
        recExcepAct->setObjectName(QString::fromUtf8("recExcepAct"));
        wDiaryAct = new QAction(MainWindow);
        wDiaryAct->setObjectName(QString::fromUtf8("wDiaryAct"));
        diaryHisAct = new QAction(MainWindow);
        diaryHisAct->setObjectName(QString::fromUtf8("diaryHisAct"));
        mthrAct = new QAction(MainWindow);
        mthrAct->setObjectName(QString::fromUtf8("mthrAct"));
        nxtMthrAct = new QAction(MainWindow);
        nxtMthrAct->setObjectName(QString::fromUtf8("nxtMthrAct"));
        brknRateAct = new QAction(MainWindow);
        brknRateAct->setObjectName(QString::fromUtf8("brknRateAct"));
        rnkComAct = new QAction(MainWindow);
        rnkComAct->setObjectName(QString::fromUtf8("rnkComAct"));
        loginAct = new QAction(MainWindow);
        loginAct->setObjectName(QString::fromUtf8("loginAct"));
        logoutAct = new QAction(MainWindow);
        logoutAct->setObjectName(QString::fromUtf8("logoutAct"));
        newAcntAct = new QAction(MainWindow);
        newAcntAct->setObjectName(QString::fromUtf8("newAcntAct"));
        chpasswdAct = new QAction(MainWindow);
        chpasswdAct->setObjectName(QString::fromUtf8("chpasswdAct"));
        bkpasswdAct = new QAction(MainWindow);
        bkpasswdAct->setObjectName(QString::fromUtf8("bkpasswdAct"));
        manDocAct = new QAction(MainWindow);
        manDocAct->setObjectName(QString::fromUtf8("manDocAct"));
        faqAct = new QAction(MainWindow);
        faqAct->setObjectName(QString::fromUtf8("faqAct"));
        storHisAct = new QAction(MainWindow);
        storHisAct->setObjectName(QString::fromUtf8("storHisAct"));
        curStorAct = new QAction(MainWindow);
        curStorAct->setObjectName(QString::fromUtf8("curStorAct"));
        lookGoodByPosi = new QAction(MainWindow);
        lookGoodByPosi->setObjectName(QString::fromUtf8("lookGoodByPosi"));
        lookGoodByInfo = new QAction(MainWindow);
        lookGoodByInfo->setObjectName(QString::fromUtf8("lookGoodByInfo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(120, 10, 781, 621));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 916, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName(QString::fromUtf8("menu_6"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_6->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menuFile->addAction(printAct);
        menuFile->addAction(quitAct);
        menu->addAction(inStoreAct);
        menu->addAction(outStoreAct);
        menu->addAction(chkGoodAct);
        menu->addAction(recExcepAct);
        menu_2->addAction(wDiaryAct);
        menu_2->addAction(diaryHisAct);
        menu_3->addAction(mthrAct);
        menu_3->addAction(nxtMthrAct);
        menu_3->addAction(brknRateAct);
        menu_3->addAction(rnkComAct);
        menu_3->addAction(storHisAct);
        menu_4->addAction(loginAct);
        menu_4->addAction(logoutAct);
        menu_4->addAction(newAcntAct);
        menu_4->addAction(chpasswdAct);
        menu_4->addAction(bkpasswdAct);
        menu_5->addAction(manDocAct);
        menu_5->addAction(faqAct);
        menu_6->addAction(curStorAct);
        menu_6->addAction(lookGoodByPosi);
        menu_6->addAction(lookGoodByInfo);
        toolBar->addAction(printAct);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(wDiaryAct);
        toolBar->addAction(diaryHisAct);
        toolBar->addSeparator();
        toolBar->addAction(mthrAct);
        toolBar->addAction(nxtMthrAct);
        toolBar->addAction(brknRateAct);
        toolBar->addAction(rnkComAct);
        toolBar->addSeparator();
        toolBar->addAction(loginAct);
        toolBar->addAction(logoutAct);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        printAct->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        quitAct->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        inStoreAct->setText(QApplication::translate("MainWindow", "\345\205\245\345\272\223", 0, QApplication::UnicodeUTF8));
        outStoreAct->setText(QApplication::translate("MainWindow", "\345\207\272\345\272\223", 0, QApplication::UnicodeUTF8));
        chkGoodAct->setText(QApplication::translate("MainWindow", "\351\252\214\350\264\247", 0, QApplication::UnicodeUTF8));
        recExcepAct->setText(QApplication::translate("MainWindow", "\345\274\202\345\270\270\344\272\213\344\273\266", 0, QApplication::UnicodeUTF8));
        wDiaryAct->setText(QApplication::translate("MainWindow", "\345\206\231\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        diaryHisAct->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        mthrAct->setText(QApplication::translate("MainWindow", "\346\234\254\346\234\210\345\220\236\345\220\220", 0, QApplication::UnicodeUTF8));
        nxtMthrAct->setText(QApplication::translate("MainWindow", "\344\270\213\346\234\210\345\220\236\345\220\220", 0, QApplication::UnicodeUTF8));
        brknRateAct->setText(QApplication::translate("MainWindow", "\345\202\250\350\264\247\347\240\264\346\215\237\347\216\207", 0, QApplication::UnicodeUTF8));
        rnkComAct->setText(QApplication::translate("MainWindow", "\346\216\222\345\272\217\345\205\254\345\217\270", 0, QApplication::UnicodeUTF8));
        loginAct->setText(QApplication::translate("MainWindow", "\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        logoutAct->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        newAcntAct->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\264\246\345\217\267", 0, QApplication::UnicodeUTF8));
        chpasswdAct->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        bkpasswdAct->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\346\211\276\345\233\236", 0, QApplication::UnicodeUTF8));
        manDocAct->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\350\257\264\346\230\216", 0, QApplication::UnicodeUTF8));
        faqAct->setText(QApplication::translate("MainWindow", "\347\226\221\351\227\256\350\247\243\347\255\224", 0, QApplication::UnicodeUTF8));
        storHisAct->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\345\255\230\345\202\250\347\273\237\350\256\241", 0, QApplication::UnicodeUTF8));
        curStorAct->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\344\273\223\345\202\250\351\207\217", 0, QApplication::UnicodeUTF8));
        lookGoodByPosi->setText(QApplication::translate("MainWindow", "\346\214\211\344\275\215\347\275\256\346\237\245\347\234\213\350\264\247\347\211\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lookGoodByPosi->setToolTip(QApplication::translate("MainWindow", "\346\214\211\344\275\215\347\275\256\346\237\245\347\234\213\350\264\247\347\211\251", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lookGoodByInfo->setText(QApplication::translate("MainWindow", "\346\214\211\344\277\241\346\201\257\346\237\245\347\234\213\350\264\247\347\211\251", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "NOtab", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\345\267\245\344\275\234", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\347\273\237\350\256\241", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("MainWindow", "\350\264\246\346\210\267\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        menu_5->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        menu_6->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
