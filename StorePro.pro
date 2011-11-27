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
    ui/client.cpp \
    ui/askgoodtolookdlg.cpp \
    client.cpp

HEADERS  += \
    logic/workFlow.h \
    logic/upcntrbase.h \
    logic/ui.h \
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
    ui/client.h \
    ui/askgoodtolookdlg.h \
    client.h

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
    ui/askGoodToLookDlg.ui

OTHER_FILES +=

RESOURCES += \
    ui/bkg_icons.qrc
