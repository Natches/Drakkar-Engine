#include <QTimer>
#include "Engine/Engine.hpp"
#include "GLEditorWidget.hpp"

GLEditorWidget::GLEditorWidget(QWidget *parent)
:   QOpenGLWidget(parent) {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(16);

    QSurfaceFormat format;
    format.setVersion(4,5);
    format.setOption(QSurfaceFormat::DeprecatedFunctions);
    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    create();
}

GLEditorWidget::~GLEditorWidget() {
    drak::core::Engine::Get().shutdown();
}

void GLEditorWidget::initializeGL() {
    drak::core::Engine::Get().startup(true);
}

void GLEditorWidget::resizeGL(int w, int h) {

}

void GLEditorWidget::paintGL() {
    drak::core::Engine::Get().renderScene();
}

