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
        $$DKSRC/Editor/Editor.cpp \
        $$DKSRC/Editor/framelesswindow.cpp \
        $$DKSRC/Editor/windowdragger.cpp \
        $$DKSRC/Editor/DarkStyle.cpp \

HEADERS += \
        $$DKSRC/Editor/Editor.hpp \
        $$DKSRC/Editor/DarkStyle.h \
        $$DKSRC/Editor/framelesswindow.h \
        $$DKSRC/Editor/windowdragger.h \
        $$DKSRC/Engine/Engine.hpp \

#------------------------------------------------------

DESTDIR     = $$OUT_PWD
TEMPDIR     = $$DESTDIR/Intermediate

OBJECTS_DIR = $$TEMPDIR/.obj
MOC_DIR     = $$TEMPDIR/.moc
RCC_DIR     = $$TEMPDIR/.qrc
UI_DIR      = $$TEMPDIR/.ui

#------------------------------------------------------

RSRCDIR     = "Resources"
RESOURCES   += \
            $$RSRCDIR/darkstyle.qrc \
            $$RSRCDIR/framelesswindow.qrc \

#------------------------------------------------------

#win32:LIBS += ../../Binaries

#------------------------------------------------------

FORMS += \
    Editor.ui \
    framelesswindow.ui \
