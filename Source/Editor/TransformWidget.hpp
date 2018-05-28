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

private:
    Ui::TransformWidget *ui;
};

#endif // TRANSFORMWIDGET_H
