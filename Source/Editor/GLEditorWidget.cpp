#include <QTimer>
#include <QDebug>
#include "Engine/Engine.hpp"
#include "GLEditorWidget.hpp"

using namespace drak::core;


GLEditorWidget::GLEditorWidget(QWidget *parent)
:   QOpenGLWidget(parent) {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(16);

    create();
}


GLEditorWidget::~GLEditorWidget() {
    Engine::Get().shutdown();
}


void GLEditorWidget::initializeGL() {
    QSurfaceFormat format;
    format.setVersion(4,5);
    format.setOption(QSurfaceFormat::DeprecatedFunctions);
    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    Engine::Get().startup(true);
    Engine::Get().loadScene("Scene");
}


void GLEditorWidget::resizeGL(int w, int h) {

}


void GLEditorWidget::paintGL() {
    Engine::Get().renderScene();
}

