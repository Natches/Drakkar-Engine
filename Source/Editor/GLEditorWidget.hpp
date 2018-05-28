#ifndef GLEDITORWIDGET_HPP
#define GLEDITORWIDGET_HPP

#include <QOpenGLWidget>

class GLEditorWidget final : public QOpenGLWidget {
    Q_OBJECT
public:
    explicit GLEditorWidget(QWidget *parent = 0);
    ~GLEditorWidget();

protected:
    /**********************************************************************************************
     *  QOpenGLWindow Overrides
     *********************************************************************************************/
    void initializeGL()         override;
    void resizeGL(int w, int h) override;
    void paintGL()              override;
};

#endif // GLEDITORWIDGET_HPP
