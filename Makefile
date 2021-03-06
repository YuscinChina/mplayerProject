#############################################################################
# Makefile for building: final_project
# Generated by qmake (2.01a) (Qt 4.7.0) on: ?? 9? 18 18:37:24 2020
# Project:  final_project.pro
# Template: app
# Command: /usr/local/Trolltech/qt_cortex-a8_4.3.2/bin/qmake -o Makefile final_project.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-linux-gcc
CXX           = arm-linux-g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/qws/linux-arm-g++ -I. -I/usr/local/Trolltech/qt_cortex-a8_4.3.2/include/QtCore -I/usr/local/Trolltech/qt_cortex-a8_4.3.2/include/QtNetwork -I/usr/local/Trolltech/qt_cortex-a8_4.3.2/include/QtGui -I/usr/local/Trolltech/qt_cortex-a8_4.3.2/include -I. -I. -I.
LINK          = arm-linux-g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/local/Trolltech/qt_cortex-a8_4.3.2/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/qt_cortex-a8_4.3.2/lib -lQtGui -L/usr/local/Trolltech/qt_cortex-a8_4.3.2/lib -lQtNetwork -lQtCore -lpthread 
AR            = arm-linux-ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/qt_cortex-a8_4.3.2/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = arm-linux-strip
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
		widget.cpp \
		lyric.cpp moc_widget.cpp \
		moc_lyric.cpp \
		qrc_res.cpp
OBJECTS       = main.o \
		widget.o \
		lyric.o \
		moc_widget.o \
		moc_lyric.o \
		qrc_res.o
DIST          = /usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/g++.conf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/unix.conf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/linux.conf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/qws.conf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/qconfig.pri \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/release.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/qt.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/moc.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/resources.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/uic.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/lex.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/include_source_dir.prf \
		final_project.pro
QMAKE_TARGET  = final_project
DESTDIR       = 
TARGET        = final_project

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

$(TARGET): ui_widget.h ui_lyric.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: final_project.pro  /usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/qws/linux-arm-g++/qmake.conf /usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/g++.conf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/unix.conf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/linux.conf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/qws.conf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/qconfig.pri \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/release.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/qt.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/moc.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/resources.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/uic.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/lex.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/include_source_dir.prf \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/lib/libQtGui.prl \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/lib/libQtNetwork.prl \
		/usr/local/Trolltech/qt_cortex-a8_4.3.2/lib/libQtCore.prl
	$(QMAKE) -o Makefile final_project.pro
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/g++.conf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/unix.conf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/linux.conf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/common/qws.conf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/qconfig.pri:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/release.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/default_post.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/qt.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/moc.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/resources.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/uic.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/yacc.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/lex.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/mkspecs/features/include_source_dir.prf:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/lib/libQtGui.prl:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/lib/libQtNetwork.prl:
/usr/local/Trolltech/qt_cortex-a8_4.3.2/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile final_project.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/final_project1.0.0 || $(MKDIR) .tmp/final_project1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/final_project1.0.0/ && $(COPY_FILE) --parents widget.h lyric.h .tmp/final_project1.0.0/ && $(COPY_FILE) --parents image/res.qrc .tmp/final_project1.0.0/ && $(COPY_FILE) --parents main.cpp widget.cpp lyric.cpp .tmp/final_project1.0.0/ && $(COPY_FILE) --parents widget.ui lyric.ui .tmp/final_project1.0.0/ && (cd `dirname .tmp/final_project1.0.0` && $(TAR) final_project1.0.0.tar final_project1.0.0 && $(COMPRESS) final_project1.0.0.tar) && $(MOVE) `dirname .tmp/final_project1.0.0`/final_project1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/final_project1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_widget.cpp moc_lyric.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_widget.cpp moc_lyric.cpp
moc_widget.cpp: lyric.h \
		ui_lyric.h \
		widget.h
	/usr/local/Trolltech/qt_cortex-a8_4.3.2/bin/moc $(DEFINES) $(INCPATH) widget.h -o moc_widget.cpp

moc_lyric.cpp: lyric.h
	/usr/local/Trolltech/qt_cortex-a8_4.3.2/bin/moc $(DEFINES) $(INCPATH) lyric.h -o moc_lyric.cpp

compiler_rcc_make_all: qrc_res.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_res.cpp
qrc_res.cpp: image/res.qrc \
		image/fenlei.png \
		image/close.png \
		image/pause.png \
		image/max.png \
		image/find.png \
		image/shouqi.png \
		image/zhuye.png \
		image/setting.png \
		image/home.png \
		image/1.png \
		image/shoucang.png \
		image/offsound.png \
		image/like.png \
		image/beforesong.png \
		image/min.png \
		image/nextsong.png \
		image/play.png \
		image/sound.png
	/usr/local/Trolltech/qt_cortex-a8_4.3.2/bin/rcc -name res image/res.qrc -o qrc_res.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_widget.h ui_lyric.h
compiler_uic_clean:
	-$(DEL_FILE) ui_widget.h ui_lyric.h
ui_widget.h: widget.ui
	/usr/local/Trolltech/qt_cortex-a8_4.3.2/bin/uic widget.ui -o ui_widget.h

ui_lyric.h: lyric.ui
	/usr/local/Trolltech/qt_cortex-a8_4.3.2/bin/uic lyric.ui -o ui_lyric.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp widget.h \
		lyric.h \
		ui_lyric.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

widget.o: widget.cpp widget.h \
		lyric.h \
		ui_lyric.h \
		ui_widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o widget.o widget.cpp

lyric.o: lyric.cpp lyric.h \
		ui_lyric.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lyric.o lyric.cpp

moc_widget.o: moc_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_widget.o moc_widget.cpp

moc_lyric.o: moc_lyric.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_lyric.o moc_lyric.cpp

qrc_res.o: qrc_res.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_res.o qrc_res.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

