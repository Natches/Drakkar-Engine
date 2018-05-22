#include <QTimer>
#include "Engine/Engine.hpp"
#include "GLEditorWidget.hpp"

GLEditorWidget::GLEditorWidget(QWidget *parent)
:   QOpenGLWidget(parent) {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
    makeCurrent();
}


GLEditorWidget::~GLEditorWidget() {

}

void GLEditorWidget::initializeGL() {

}

void GLEditorWidget::resizeGL(int w, int h) {

}

void GLEditorWidget::paintGL() {

}

