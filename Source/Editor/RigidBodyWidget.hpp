#ifndef RIGIDBODYWIDGET_HPP
#define RIGIDBODYWIDGET_HPP

#include <QWidget>

namespace Ui { class RigidBodyWidget; }

class RigidBodyWidget : public QWidget {
    Q_OBJECT
public:
    explicit RigidBodyWidget(QWidget *parent = 0);
    ~RigidBodyWidget();

private:
    Ui::RigidBodyWidget *ui;
};

#endif // RIGIDBODYWIDGET_HPP
