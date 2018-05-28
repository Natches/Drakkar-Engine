#include "TransformWidget.hpp"
#include "ui_TransformWidget.h"

using namespace drak;
using namespace drak::components;

TransformWidget::TransformWidget(QWidget *parent)
:   QWidget(parent), ui(new Ui::TransformWidget) {
    ui->setupUi(this);
    //connect(this, )
}

TransformWidget::~TransformWidget() {
    delete ui;
}

void TransformWidget::setTransform(Transform* pXform) {
    ui->spin_PosX->setValue(pXform->getGlobalPosition().x);
    ui->spin_PosY->setValue(pXform->getGlobalPosition().x);
    ui->spin_PosZ->setValue(pXform->getGlobalPosition().x);

    //ui->spin_RotX->setValue(xform.getGlobalRotation().x);
    //ui->spin_RotX->setValue(xform.getGlobalRotation().x);
    //ui->spin_RotX->setValue(xform.getGlobalRotation().x);

    ui->spin_ScaleX->setValue(pXform->getGlobalScale().x);
    ui->spin_ScaleY->setValue(pXform->getGlobalScale().y);
    ui->spin_ScaleZ->setValue(pXform->getGlobalScale().z);
}
