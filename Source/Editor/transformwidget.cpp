#include "TransformWidget.hpp"
#include "ui_TransformWidget.h"

TransformWidget::TransformWidget(QWidget *parent)
:   QWidget(parent), ui(new Ui::TransformWidget) {
    ui->setupUi(this);
}

TransformWidget::~TransformWidget() {
    delete ui;
}
