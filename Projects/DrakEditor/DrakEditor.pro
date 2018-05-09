#------------------------------------------------------
#
# Drakkar Editor
#
#------------------------------------------------------

QT += core gui widgets

TARGET = DrakEditor
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

#------------------------------------------------------

CONFIG += c++17
CONFIG -= debug_and_release debug_and_release_target

#------------------------------------------------------

DKSRC = "../../Source"

INCLUDEPATH += $$DKSRC
DEPENDPATH  += $$DKSRC

SOURCES += \
        $$DKSRC/Editor/main.cpp \
        $$DKSRC/Editor/Editor.cpp

HEADERS += \
        $$DKSRC/Editor/Editor.hpp \
        $$DKSRC/Engine/Engine.hpp

#win32:LIBS += ../../Binaries

DESTDIR     = $$OUT_PWD

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR     = $$DESTDIR/.moc
RCC_DIR     = $$DESTDIR/.qrc
UI_DIR      = $$DESTDIR/.ui

#------------------------------------------------------

required_qt_dll.path = %{buildDir}
required_qt_dll.files = $$QMAKE_LIBDIR_QT/QtCore.dll
INSTALLS += required_qt_dll


QT_QPA_PLATFORM_PLUGIN_PATH = %QTDIR%\plugins\platforms\

#------------------------------------------------------

FORMS += \
    Editor.ui
