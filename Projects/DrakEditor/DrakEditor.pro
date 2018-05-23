###############################################################################
#
#                               Drakkar Editor
#
###############################################################################

QT          += core gui widgets opengl
DEFINES     += QT_DEPRECATED_WARNINGS

TARGET      = DrakEditor
TEMPLATE    = app

CONFIG      += c++17
CONFIG      -= debug_and_release debug_and_release_target

###############################################################################

DKBIN       = "../../Binaries"

CONFIG(debug, debug|release) {
    DESTDIR = $$DKBIN/Debug/x64
}
CONFIG(release, debug|release) {
    DESTDIR = $$DKBIN/Release/x64
}

###############################################################################

LIBS        +=                                      \
            $$DESTDIR/DrakEngine.lib                \

###############################################################################

DKSRC       = "../../Source"

INCLUDEPATH += $$DKSRC
DEPENDPATH  += $$DKSRC

SOURCES     +=                                      \
            $$DKSRC/Editor/DarkStyle.cpp            \
            $$DKSRC/Editor/framelesswindow.cpp      \
            $$DKSRC/Editor/windowdragger.cpp        \
            $$DKSRC/Editor/main.cpp                 \
            $$DKSRC/Editor/Editor.cpp               \
            $$DKSRC/Editor/GLEditorWidget.cpp       \
            $$DKSRC/Editor/TransformWidget.cpp      \
            $$DKSRC/Editor/SceneGraphWidget.cpp     \

HEADERS     +=                                      \
            $$DKSRC/Editor/DarkStyle.h              \
            $$DKSRC/Editor/framelesswindow.h        \
            $$DKSRC/Editor/windowdragger.h          \
            $$DKSRC/Editor/Editor.hpp               \
            $$DKSRC/Editor/GLEditorWidget.hpp       \
            $$DKSRC/Editor/TransformWidget.hpp      \
            $$DKSRC/Editor/SceneGraphWidget.hpp     \
            $$DKSRC/Engine/Engine.hpp               \

###############################################################################

RSRCDIR     = "Resources"

RESOURCES   +=                                      \
            $$RSRCDIR/darkstyle.qrc                 \
            $$RSRCDIR/framelesswindow.qrc           \

RC_ICONS    +=                                      \
            $$RSRCDIR/Drakkar.ico                   \

###############################################################################

FORMDIR     = "Forms"

FORMS       +=                                      \
            $$FORMDIR/Editor.ui                     \
            $$FORMDIR/framelesswindow.ui            \
            $$FORMDIR/transformwidget.ui            \

###############################################################################

TEMPDIR     = "Intermediate"

OBJECTS_DIR = $$TEMPDIR/obj
MOC_DIR     = $$TEMPDIR/moc
RCC_DIR     = $$TEMPDIR/qrc
UI_DIR      = $$DKSRC/Editor

###############################################################################
