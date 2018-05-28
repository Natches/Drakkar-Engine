#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include <QWidget>
#include "Engine/Components/TransformComponent.hpp"

namespace Ui { class TransformWidget; }

class TransformWidget : public QWidget {
    Q_OBJECT
public:
    explicit TransformWidget(QWidget *parent = 0);
    ~TransformWidget();

    void setTransform(drak::components::Transform* pXform);

private slots:
    void changedPosX(double x);
    void changedPosY(double y);
    void changedPosZ(double z);

    void changedDimX(double x);
    void changedDimY(double y);
    void changedDimZ(double z);

private:
    Ui::TransformWidget         *ui;
    drak::components::Transform *m_pXform;
};

#endif // TRANSFORMWIDGET_H
