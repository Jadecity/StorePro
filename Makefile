#############################################################################
# Makefile for building: StorePro
# Generated by qmake (2.01a) (Qt 4.6.2) on: ?? 11? 27 23:28:49 2011
# Project:  StorePro.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile StorePro.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
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
		client.cpp moc_workFlow.cpp \
		moc_upcntrbase.cpp \
		moc_testuecepmgr.cpp \
		moc_teststoragemgr.cpp \
		moc_testnetconnector.cpp \
		moc_testdiary.cpp \
		moc_testdatatrans.cpp \
		moc_storageMgr.cpp \
		moc_statics.cpp \
		moc_net.cpp \
		moc_excepEvents.cpp \
		moc_dataIO.cpp \
		moc_wastagedsp.cpp \
		moc_throughoutdisp.cpp \
		moc_storestatusdsp.cpp \
		moc_storemap.cpp \
		moc_mainwindow.cpp \
		moc_login_ui.cpp \
		moc_lncrankdsp.cpp \
		moc_excepeditor.cpp \
		moc_diaryeditor.cpp \
		moc_diarydisp.cpp \
		moc_askgoodtolookdlg.cpp \
		moc_client.cpp \
		qrc_bkg_icons.cpp
OBJECTS       = main.o \
		testuecepmgr.o \
		teststoragemgr.o \
		testnetconnector.o \
		testdiary.o \
		testdatatrans.o \
		storageMgr.o \
		statics.o \
		net.o \
		excepEvents.o \
		dataIO.o \
		workflow.o \
		wastagedsp.o \
		throughoutdisp.o \
		storestatusdsp.o \
		storemap.o \
		mainwindow.o \
		login_ui.o \
		lncrankdsp.o \
		excepeditor.o \
		diaryeditor.o \
		diarydisp.o \
		askgoodtolookdlg.o \
		client.o \
		moc_workFlow.o \
		moc_upcntrbase.o \
		moc_testuecepmgr.o \
		moc_teststoragemgr.o \
		moc_testnetconnector.o \
		moc_testdiary.o \
		moc_testdatatrans.o \
		moc_storageMgr.o \
		moc_statics.o \
		moc_net.o \
		moc_excepEvents.o \
		moc_dataIO.o \
		moc_wastagedsp.o \
		moc_throughoutdisp.o \
		moc_storestatusdsp.o \
		moc_storemap.o \
		moc_mainwindow.o \
		moc_login_ui.o \
		moc_lncrankdsp.o \
		moc_excepeditor.o \
		moc_diaryeditor.o \
		moc_diarydisp.o \
		moc_askgoodtolookdlg.o \
		moc_client.o \
		qrc_bkg_icons.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		StorePro.pro
QMAKE_TARGET  = StorePro
DESTDIR       = 
TARGET        = StorePro

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_wastageDsp.h ui_throughoutDisp.h ui_storestatusdsp.h ui_storemap.h ui_mainwindow.h ui_login_ui.h ui_lncRankDsp.h ui_excepEditor.h ui_diaryEditor.h ui_diarydisp.h ui_askGoodToLookDlg.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: StorePro.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtNetwork.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile StorePro.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtNetwork.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile StorePro.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/StorePro1.0.0 || $(MKDIR) .tmp/StorePro1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/StorePro1.0.0/ && $(COPY_FILE) --parents logic/workFlow.h logic/upcntrbase.h logic/ui.h logic/testuecepmgr.h logic/teststoragemgr.h logic/testnetconnector.h logic/testdiary.h logic/testdatatrans.h logic/storageMgr.h logic/statics.h logic/net.h logic/globalDataType.h logic/excepEvents.h logic/dataIO.h logic/cmddef.h ui/wastagedsp.h ui/throughoutdisp.h ui/storestatusdsp.h ui/storemap.h ui/mainwindow.h ui/login_ui.h ui/lncrankdsp.h ui/excepeditor.h ui/diaryeditor.h ui/diarydisp.h ui/askgoodtolookdlg.h client.h .tmp/StorePro1.0.0/ && $(COPY_FILE) --parents ui/bkg_icons.qrc .tmp/StorePro1.0.0/ && $(COPY_FILE) --parents main.cpp logic/testuecepmgr.cpp logic/teststoragemgr.cpp logic/testnetconnector.cpp logic/testdiary.cpp logic/testdatatrans.cpp logic/storageMgr.cpp logic/statics.cpp logic/net.cpp logic/excepEvents.cpp logic/dataIO.cpp logic/workflow.cpp ui/wastagedsp.cpp ui/throughoutdisp.cpp ui/storestatusdsp.cpp ui/storemap.cpp ui/mainwindow.cpp ui/login_ui.cpp ui/lncrankdsp.cpp ui/excepeditor.cpp ui/diaryeditor.cpp ui/diarydisp.cpp ui/askgoodtolookdlg.cpp client.cpp .tmp/StorePro1.0.0/ && $(COPY_FILE) --parents ui/wastageDsp.ui ui/throughoutDisp.ui ui/storestatusdsp.ui ui/storemap.ui ui/mainwindow.ui ui/login_ui.ui ui/lncRankDsp.ui ui/excepEditor.ui ui/diaryEditor.ui ui/diarydisp.ui ui/askGoodToLookDlg.ui .tmp/StorePro1.0.0/ && (cd `dirname .tmp/StorePro1.0.0` && $(TAR) StorePro1.0.0.tar StorePro1.0.0 && $(COMPRESS) StorePro1.0.0.tar) && $(MOVE) `dirname .tmp/StorePro1.0.0`/StorePro1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/StorePro1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_workFlow.cpp moc_upcntrbase.cpp moc_testuecepmgr.cpp moc_teststoragemgr.cpp moc_testnetconnector.cpp moc_testdiary.cpp moc_testdatatrans.cpp moc_storageMgr.cpp moc_statics.cpp moc_net.cpp moc_excepEvents.cpp moc_dataIO.cpp moc_wastagedsp.cpp moc_throughoutdisp.cpp moc_storestatusdsp.cpp moc_storemap.cpp moc_mainwindow.cpp moc_login_ui.cpp moc_lncrankdsp.cpp moc_excepeditor.cpp moc_diaryeditor.cpp moc_diarydisp.cpp moc_askgoodtolookdlg.cpp moc_client.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_workFlow.cpp moc_upcntrbase.cpp moc_testuecepmgr.cpp moc_teststoragemgr.cpp moc_testnetconnector.cpp moc_testdiary.cpp moc_testdatatrans.cpp moc_storageMgr.cpp moc_statics.cpp moc_net.cpp moc_excepEvents.cpp moc_dataIO.cpp moc_wastagedsp.cpp moc_throughoutdisp.cpp moc_storestatusdsp.cpp moc_storemap.cpp moc_mainwindow.cpp moc_login_ui.cpp moc_lncrankdsp.cpp moc_excepeditor.cpp moc_diaryeditor.cpp moc_diarydisp.cpp moc_askgoodtolookdlg.cpp moc_client.cpp
moc_workFlow.cpp: logic/upcntrbase.h \
		logic/dataIO.h \
		logic/net.h \
		logic/workFlow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/workFlow.h -o moc_workFlow.cpp

moc_upcntrbase.cpp: logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/upcntrbase.h -o moc_upcntrbase.cpp

moc_testuecepmgr.cpp: logic/net.h \
		logic/dataIO.h \
		logic/excepEvents.h \
		logic/upcntrbase.h \
		logic/testuecepmgr.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/testuecepmgr.h -o moc_testuecepmgr.cpp

moc_teststoragemgr.cpp: logic/storageMgr.h \
		logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h \
		logic/cmddef.h \
		logic/globalDataType.h \
		logic/teststoragemgr.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/teststoragemgr.h -o moc_teststoragemgr.cpp

moc_testnetconnector.cpp: logic/net.h \
		logic/testnetconnector.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/testnetconnector.h -o moc_testnetconnector.cpp

moc_testdiary.cpp: logic/storageMgr.h \
		logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h \
		logic/cmddef.h \
		logic/globalDataType.h \
		logic/testdiary.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/testdiary.h -o moc_testdiary.cpp

moc_testdatatrans.cpp: logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h \
		logic/testdatatrans.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/testdatatrans.h -o moc_testdatatrans.cpp

moc_storageMgr.cpp: logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h \
		logic/cmddef.h \
		logic/globalDataType.h \
		logic/storageMgr.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/storageMgr.h -o moc_storageMgr.cpp

moc_statics.cpp: logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h \
		logic/cmddef.h \
		logic/statics.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/statics.h -o moc_statics.cpp

moc_net.cpp: logic/net.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/net.h -o moc_net.cpp

moc_excepEvents.cpp: logic/upcntrbase.h \
		logic/dataIO.h \
		logic/net.h \
		logic/excepEvents.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/excepEvents.h -o moc_excepEvents.cpp

moc_dataIO.cpp: logic/net.h \
		logic/dataIO.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) logic/dataIO.h -o moc_dataIO.cpp

moc_wastagedsp.cpp: ui/wastagedsp.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/wastagedsp.h -o moc_wastagedsp.cpp

moc_throughoutdisp.cpp: ui/throughoutdisp.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/throughoutdisp.h -o moc_throughoutdisp.cpp

moc_storestatusdsp.cpp: ui/storestatusdsp.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/storestatusdsp.h -o moc_storestatusdsp.cpp

moc_storemap.cpp: ui/storemap.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/storemap.h -o moc_storemap.cpp

moc_mainwindow.cpp: ui/mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/mainwindow.h -o moc_mainwindow.cpp

moc_login_ui.cpp: ui/login_ui.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/login_ui.h -o moc_login_ui.cpp

moc_lncrankdsp.cpp: logic/globalDataType.h \
		ui/lncrankdsp.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/lncrankdsp.h -o moc_lncrankdsp.cpp

moc_excepeditor.cpp: ui/excepeditor.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/excepeditor.h -o moc_excepeditor.cpp

moc_diaryeditor.cpp: ui/diaryeditor.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/diaryeditor.h -o moc_diaryeditor.cpp

moc_diarydisp.cpp: logic/globalDataType.h \
		ui/diarydisp.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/diarydisp.h -o moc_diarydisp.cpp

moc_askgoodtolookdlg.cpp: ui/askgoodtolookdlg.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/askgoodtolookdlg.h -o moc_askgoodtolookdlg.cpp

moc_client.cpp: ui/mainwindow.h \
		client.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) client.h -o moc_client.cpp

compiler_rcc_make_all: qrc_bkg_icons.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_bkg_icons.cpp
qrc_bkg_icons.cpp: ui/bkg_icons.qrc \
		ui/icons/to_left90.png \
		ui/icons/to_left_120.png \
		ui/icons/to_right90.png \
		ui/icons/dragon_phoenix.png \
		ui/icons/to_left.jpg \
		ui/icons/to_right.jpg \
		ui/icons/to_left90_on.png \
		ui/icons/to_right90_on.png \
		ui/icons/天道酬勤.gif
	/usr/bin/rcc -name bkg_icons ui/bkg_icons.qrc -o qrc_bkg_icons.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_wastageDsp.h ui_throughoutDisp.h ui_storestatusdsp.h ui_storemap.h ui_mainwindow.h ui_login_ui.h ui_lncRankDsp.h ui_excepEditor.h ui_diaryEditor.h ui_diarydisp.h ui_askGoodToLookDlg.h
compiler_uic_clean:
	-$(DEL_FILE) ui_wastageDsp.h ui_throughoutDisp.h ui_storestatusdsp.h ui_storemap.h ui_mainwindow.h ui_login_ui.h ui_lncRankDsp.h ui_excepEditor.h ui_diaryEditor.h ui_diarydisp.h ui_askGoodToLookDlg.h
ui_wastageDsp.h: ui/wastageDsp.ui
	/usr/bin/uic-qt4 ui/wastageDsp.ui -o ui_wastageDsp.h

ui_throughoutDisp.h: ui/throughoutDisp.ui
	/usr/bin/uic-qt4 ui/throughoutDisp.ui -o ui_throughoutDisp.h

ui_storestatusdsp.h: ui/storestatusdsp.ui
	/usr/bin/uic-qt4 ui/storestatusdsp.ui -o ui_storestatusdsp.h

ui_storemap.h: ui/storemap.ui
	/usr/bin/uic-qt4 ui/storemap.ui -o ui_storemap.h

ui_mainwindow.h: ui/mainwindow.ui
	/usr/bin/uic-qt4 ui/mainwindow.ui -o ui_mainwindow.h

ui_login_ui.h: ui/login_ui.ui
	/usr/bin/uic-qt4 ui/login_ui.ui -o ui_login_ui.h

ui_lncRankDsp.h: ui/lncRankDsp.ui
	/usr/bin/uic-qt4 ui/lncRankDsp.ui -o ui_lncRankDsp.h

ui_excepEditor.h: ui/excepEditor.ui
	/usr/bin/uic-qt4 ui/excepEditor.ui -o ui_excepEditor.h

ui_diaryEditor.h: ui/diaryEditor.ui
	/usr/bin/uic-qt4 ui/diaryEditor.ui -o ui_diaryEditor.h

ui_diarydisp.h: ui/diarydisp.ui
	/usr/bin/uic-qt4 ui/diarydisp.ui -o ui_diarydisp.h

ui_askGoodToLookDlg.h: ui/askGoodToLookDlg.ui
	/usr/bin/uic-qt4 ui/askGoodToLookDlg.ui -o ui_askGoodToLookDlg.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp ui/login_ui.h \
		ui/mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

testuecepmgr.o: logic/testuecepmgr.cpp logic/testuecepmgr.h \
		logic/net.h \
		logic/dataIO.h \
		logic/excepEvents.h \
		logic/upcntrbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o testuecepmgr.o logic/testuecepmgr.cpp

teststoragemgr.o: logic/teststoragemgr.cpp logic/teststoragemgr.h \
		logic/storageMgr.h \
		logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h \
		logic/cmddef.h \
		logic/globalDataType.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o teststoragemgr.o logic/teststoragemgr.cpp

testnetconnector.o: logic/testnetconnector.cpp logic/testnetconnector.h \
		logic/net.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o testnetconnector.o logic/testnetconnector.cpp

testdiary.o: logic/testdiary.cpp logic/testdiary.h \
		logic/storageMgr.h \
		logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h \
		logic/cmddef.h \
		logic/globalDataType.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o testdiary.o logic/testdiary.cpp

testdatatrans.o: logic/testdatatrans.cpp logic/testdatatrans.h \
		logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o testdatatrans.o logic/testdatatrans.cpp

storageMgr.o: logic/storageMgr.cpp logic/storageMgr.h \
		logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h \
		logic/cmddef.h \
		logic/globalDataType.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o storageMgr.o logic/storageMgr.cpp

statics.o: logic/statics.cpp logic/statics.h \
		logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h \
		logic/cmddef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o statics.o logic/statics.cpp

net.o: logic/net.cpp logic/net.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o net.o logic/net.cpp

excepEvents.o: logic/excepEvents.cpp logic/excepEvents.h \
		logic/upcntrbase.h \
		logic/dataIO.h \
		logic/net.h \
		logic/cmddef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o excepEvents.o logic/excepEvents.cpp

dataIO.o: logic/dataIO.cpp logic/dataIO.h \
		logic/net.h \
		logic/upcntrbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataIO.o logic/dataIO.cpp

workflow.o: logic/workflow.cpp logic/workFlow.h \
		logic/upcntrbase.h \
		logic/dataIO.h \
		logic/net.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o workflow.o logic/workflow.cpp

wastagedsp.o: ui/wastagedsp.cpp ui/wastagedsp.h \
		ui_wastageDsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o wastagedsp.o ui/wastagedsp.cpp

throughoutdisp.o: ui/throughoutdisp.cpp ui/throughoutdisp.h \
		ui_throughoutDisp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o throughoutdisp.o ui/throughoutdisp.cpp

storestatusdsp.o: ui/storestatusdsp.cpp ui/storestatusdsp.h \
		ui_storestatusdsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o storestatusdsp.o ui/storestatusdsp.cpp

storemap.o: ui/storemap.cpp ui/storemap.h \
		ui_storemap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o storemap.o ui/storemap.cpp

mainwindow.o: ui/mainwindow.cpp ui/mainwindow.h \
		ui_mainwindow.h \
		ui/askgoodtolookdlg.h \
		ui/diaryeditor.h \
		ui/excepeditor.h \
		ui/lncrankdsp.h \
		logic/globalDataType.h \
		ui/storemap.h \
		ui/storestatusdsp.h \
		ui/throughoutdisp.h \
		ui/wastagedsp.h \
		ui/diarydisp.h \
		ui/login_ui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o ui/mainwindow.cpp

login_ui.o: ui/login_ui.cpp ui/login_ui.h \
		ui_login_ui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o login_ui.o ui/login_ui.cpp

lncrankdsp.o: ui/lncrankdsp.cpp ui/lncrankdsp.h \
		logic/globalDataType.h \
		ui_lncRankDsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lncrankdsp.o ui/lncrankdsp.cpp

excepeditor.o: ui/excepeditor.cpp ui/excepeditor.h \
		ui_excepEditor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o excepeditor.o ui/excepeditor.cpp

diaryeditor.o: ui/diaryeditor.cpp ui/diaryeditor.h \
		ui_diaryEditor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o diaryeditor.o ui/diaryeditor.cpp

diarydisp.o: ui/diarydisp.cpp ui/diarydisp.h \
		logic/globalDataType.h \
		ui_diarydisp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o diarydisp.o ui/diarydisp.cpp

askgoodtolookdlg.o: ui/askgoodtolookdlg.cpp ui/askgoodtolookdlg.h \
		ui_askGoodToLookDlg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o askgoodtolookdlg.o ui/askgoodtolookdlg.cpp

client.o: client.cpp client.h \
		ui/mainwindow.h \
		ui/askgoodtolookdlg.h \
		ui/diaryeditor.h \
		ui/excepeditor.h \
		ui/lncrankdsp.h \
		logic/globalDataType.h \
		ui/storemap.h \
		ui/throughoutdisp.h \
		ui/wastagedsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o client.o client.cpp

moc_workFlow.o: moc_workFlow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_workFlow.o moc_workFlow.cpp

moc_upcntrbase.o: moc_upcntrbase.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_upcntrbase.o moc_upcntrbase.cpp

moc_testuecepmgr.o: moc_testuecepmgr.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_testuecepmgr.o moc_testuecepmgr.cpp

moc_teststoragemgr.o: moc_teststoragemgr.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_teststoragemgr.o moc_teststoragemgr.cpp

moc_testnetconnector.o: moc_testnetconnector.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_testnetconnector.o moc_testnetconnector.cpp

moc_testdiary.o: moc_testdiary.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_testdiary.o moc_testdiary.cpp

moc_testdatatrans.o: moc_testdatatrans.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_testdatatrans.o moc_testdatatrans.cpp

moc_storageMgr.o: moc_storageMgr.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_storageMgr.o moc_storageMgr.cpp

moc_statics.o: moc_statics.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_statics.o moc_statics.cpp

moc_net.o: moc_net.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_net.o moc_net.cpp

moc_excepEvents.o: moc_excepEvents.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_excepEvents.o moc_excepEvents.cpp

moc_dataIO.o: moc_dataIO.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dataIO.o moc_dataIO.cpp

moc_wastagedsp.o: moc_wastagedsp.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_wastagedsp.o moc_wastagedsp.cpp

moc_throughoutdisp.o: moc_throughoutdisp.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_throughoutdisp.o moc_throughoutdisp.cpp

moc_storestatusdsp.o: moc_storestatusdsp.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_storestatusdsp.o moc_storestatusdsp.cpp

moc_storemap.o: moc_storemap.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_storemap.o moc_storemap.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_login_ui.o: moc_login_ui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_login_ui.o moc_login_ui.cpp

moc_lncrankdsp.o: moc_lncrankdsp.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_lncrankdsp.o moc_lncrankdsp.cpp

moc_excepeditor.o: moc_excepeditor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_excepeditor.o moc_excepeditor.cpp

moc_diaryeditor.o: moc_diaryeditor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_diaryeditor.o moc_diaryeditor.cpp

moc_diarydisp.o: moc_diarydisp.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_diarydisp.o moc_diarydisp.cpp

moc_askgoodtolookdlg.o: moc_askgoodtolookdlg.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_askgoodtolookdlg.o moc_askgoodtolookdlg.cpp

moc_client.o: moc_client.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_client.o moc_client.cpp

qrc_bkg_icons.o: qrc_bkg_icons.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_bkg_icons.o qrc_bkg_icons.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

