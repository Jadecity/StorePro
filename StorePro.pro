#-------------------------------------------------
#
# Project created by QtCreator 2011-11-27T12:57:16
#
#-------------------------------------------------

QT       += core gui network

TARGET = StorePro
TEMPLATE = app


SOURCES += main.cpp \
    logic/testuecepmgr.cpp \
    logic/teststoragemgr.cpp \
    logic/testnetconnector.cpp \
    logic/testdiary.cpp \
    logic/testdatatrans.cpp \
    logic/storageMgr.cpp \
    logic/statics.cpp \
    logic/net.cpp \
    logic/excepEvents.cpp \
    logic/dataIO.cpp \
    logic/workflow.cpp \
    ui/wastagedsp.cpp \
    ui/throughoutdisp.cpp \
    ui/storestatusdsp.cpp \
    ui/storemap.cpp \
    ui/mainwindow.cpp \
    ui/login_ui.cpp \
    ui/lncrankdsp.cpp \
    ui/excepeditor.cpp \
    ui/diaryeditor.cpp \
    ui/diarydisp.cpp \
    ui/askgoodtolookdlg.cpp \
    client.cpp \
    logic/accountmgr.cpp \
    ui/exchange_table.cpp \
    ui/instore_table.cpp \
    ui/outstore_table.cpp \
    ui/check_table.cpp \
    ui/overtimetab.cpp \
    ui/draw3dpiechart.cpp

HEADERS  += \
    logic/workFlow.h \
    logic/upcntrbase.h \
    logic/testuecepmgr.h \
    logic/teststoragemgr.h \
    logic/testnetconnector.h \
    logic/testdiary.h \
    logic/testdatatrans.h \
    logic/storageMgr.h \
    logic/statics.h \
    logic/net.h \
    logic/globalDataType.h \
    logic/excepEvents.h \
    logic/dataIO.h \
    logic/cmddef.h \
    ui/wastagedsp.h \
    ui/throughoutdisp.h \
    ui/storestatusdsp.h \
    ui/storemap.h \
    ui/mainwindow.h \
    ui/login_ui.h \
    ui/lncrankdsp.h \
    ui/excepeditor.h \
    ui/diaryeditor.h \
    ui/diarydisp.h \
    ui/askgoodtolookdlg.h \
    client.h \
    logic/accountmgr.h \
    ui/exchange_table.h \
    ui/instore_table.h \
    ui/outstore_table.h \
    ui/check_table.h \
    ui/overtimetab.h \
    ui/draw3dpiechart.h

FORMS    += \
    ui/wastageDsp.ui \
    ui/throughoutDisp.ui \
    ui/storestatusdsp.ui \
    ui/storemap.ui \
    ui/mainwindow.ui \
    ui/login_ui.ui \
    ui/lncRankDsp.ui \
    ui/excepEditor.ui \
    ui/diaryEditor.ui \
    ui/diarydisp.ui \
    ui/askGoodToLookDlg.ui \
    ui/exchange_table.ui \
    ui/instore_table.ui \
    ui/outstore_table.ui \
    ui/check_table.ui \
    ui/overtimetab.ui

RESOURCES += \
    ui/bkg_icons.qrc
RC_FILE = StorePro.rc
