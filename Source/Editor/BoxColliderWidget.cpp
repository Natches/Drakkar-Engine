#include "BoxColliderWidget.hpp"
#include "ui_BoxColliderWidget.h"

BoxColliderWidget::BoxColliderWidget(QWidget *parent)
:   QWidget(parent), ui(new Ui::BoxColliderWidget) {
    ui->setupUi(this);
}

BoxColliderWidget::~BoxColliderWidget() {
    delete ui;
}
