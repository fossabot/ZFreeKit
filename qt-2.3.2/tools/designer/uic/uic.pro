TEMPLATE	= app
CONFIG		+= qt console warn_on release
HEADERS		= uic.h ../shared/widgetdatabase.h ../shared/domtool.h ../integration/kdevelop/kdewidgets.h
SOURCES		= uic.cpp ../shared/widgetdatabase.cpp ../shared/domtool.cpp ../integration/kdevelop/kdewidgets.cpp
TARGET		= uic
INCLUDEPATH	= ../shared ../util ../../../src/3rdparty/zlib/
unix:LIBS	+= -L$(QT2DIR)/lib -lqutil -L../lib
win32:LIBS	+= $(QT2DIR)/lib/qutil.lib
DEFINES 	+= UIC
DESTDIR		= $(QT2DIR)/bin
