#ifndef BOXCOLLIDERWIDGET_HPP
#define BOXCOLLIDERWIDGET_HPP

#include <QWidget>

namespace Ui { class BoxColliderWidget; }

class BoxColliderWidget : public QWidget {
    Q_OBJECT
public:
    explicit BoxColliderWidget(QWidget *parent = 0);
    ~BoxColliderWidget();

private:
    Ui::BoxColliderWidget *ui;
};

#endif // BOXCOLLIDERWIDGET_HPP
