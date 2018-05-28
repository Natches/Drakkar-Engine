#include "RigidBodyWidget.hpp"
#include "ui_RigidBodyWidget.h"

RigidBodyWidget::RigidBodyWidget(QWidget *parent)
:   QWidget(parent), ui(new Ui::RigidBodyWidget) {
    ui->setupUi(this);
}

RigidBodyWidget::~RigidBodyWidget() {
    delete ui;
}
