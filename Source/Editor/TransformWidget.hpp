#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include <QWidget>

namespace Ui { class TransformWidget; }

class TransformWidget : public QWidget {
    Q_OBJECT
public:
    explicit TransformWidget(QWidget *parent = 0);
    ~TransformWidget();

private:
    Ui::TransformWidget *ui;
};

#endif // TRANSFORMWIDGET_H
