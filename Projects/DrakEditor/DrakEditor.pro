#----------------------------------------------------------
#
# Drakkar Editor
#
#----------------------------------------------------------

QT          += core gui widgets
DEFINES     += QT_DEPRECATED_WARNINGS

TARGET      = DrakEditor
TEMPLATE    = app

#----------------------------------------------------------

CONFIG      += c++17
CONFIG      -= debug_and_release debug_and_release_target

#----------------------------------------------------------

DKSRC       = "../../Source"

INCLUDEPATH += $$DKSRC
DEPENDPATH  += $$DKSRC

SOURCES     += \
            $$DKSRC/Editor/main.cpp                 \
            $$DKSRC/Editor/Editor.cpp               \
            $$DKSRC/Editor/framelesswindow.cpp      \
            $$DKSRC/Editor/windowdragger.cpp        \
            $$DKSRC/Editor/DarkStyle.cpp            \

HEADERS     += \
#---- Editor
            $$DKSRC/Editor/Editor.hpp               \
            $$DKSRC/Editor/DarkStyle.h              \
            $$DKSRC/Editor/framelesswindow.h        \
            $$DKSRC/Editor/windowdragger.h          \
#---- Engine
            $$DKSRC/Engine/Engine.hpp               \

#----------------------------------------------------------

#LIBDIR      = "../../Binaries"

#win32:LIBS  += \
#            -L$$LIBDIR/Release/x64/DrakEngine.lib    \

#----------------------------------------------------------

DESTDIR     = $$OUT_PWD
TEMPDIR     = $$DESTDIR/Intermediate

OBJECTS_DIR = $$TEMPDIR/.obj
MOC_DIR     = $$TEMPDIR/.moc
RCC_DIR     = $$TEMPDIR/.qrc
UI_DIR      = $$TEMPDIR/.ui

#----------------------------------------------------------

RSRCDIR     = "Resources"
RESOURCES   += \
            $$RSRCDIR/darkstyle.qrc                 \
            $$RSRCDIR/framelesswindow.qrc           \

RC_ICONS    += \
            $$RSRCDIR/Drakkar.ico

#----------------------------------------------------------

FORMS       += \
            Editor.ui                               \
            framelesswindow.ui                      \

#----------------------------------------------------------
