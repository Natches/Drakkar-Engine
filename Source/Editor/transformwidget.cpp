#include "TransformWidget.hpp"
#include "ui_TransformWidget.h"

using namespace drak;
using namespace drak::components;

TransformWidget::TransformWidget(QWidget *parent)
:   QWidget(parent), ui(new Ui::TransformWidget) {
    ui->setupUi(this);

    connect(ui->spin_PosX, SIGNAL(valueChanged(double)), this, SLOT(changedPosX(double)));
    connect(ui->spin_PosY, SIGNAL(valueChanged(double)), this, SLOT(changedPosY(double)));
    connect(ui->spin_PosZ, SIGNAL(valueChanged(double)), this, SLOT(changedPosZ(double)));

    connect(ui->spin_ScaleX, SIGNAL(valueChanged(double)), this, SLOT(changedDimX(double)));
    connect(ui->spin_ScaleY, SIGNAL(valueChanged(double)), this, SLOT(changedDimY(double)));
    connect(ui->spin_ScaleZ, SIGNAL(valueChanged(double)), this, SLOT(changedDimZ(double)));
}

TransformWidget::~TransformWidget() {
    delete ui;
}

void TransformWidget::setTransform(Transform* pXform) {
    m_pXform = pXform;

    ui->spin_PosX->setValue(m_pXform->getGlobalPosition().x);
    ui->spin_PosY->setValue(m_pXform->getGlobalPosition().y);
    ui->spin_PosZ->setValue(m_pXform->getGlobalPosition().z);

    //ui->spin_RotX->setValue(xform.getLocalRotation().x);
    //ui->spin_RotY->setValue(xform.getLocalRotation().y);
    //ui->spin_RotZ->setValue(xform.getLocalRotation().z);

    ui->spin_ScaleX->setValue(m_pXform->getGlobalScale().x);
    ui->spin_ScaleY->setValue(m_pXform->getGlobalScale().y);
    ui->spin_ScaleZ->setValue(m_pXform->getGlobalScale().z);
}

void TransformWidget::changedPosX(double x) {
    auto& v = m_pXform->getGlobalPosition();
    m_pXform->setGlobalPosition(math::Vec3f(x, v.y, v.z));
}

void TransformWidget::changedPosY(double y) {
    auto& v = m_pXform->getGlobalPosition();
    m_pXform->setGlobalPosition(math::Vec3f(v.x, y, v.z));
}

void TransformWidget::changedPosZ(double z) {
    auto& v = m_pXform->getGlobalPosition();
    m_pXform->setGlobalPosition(math::Vec3f(v.x, v.y, z));
}

void TransformWidget::changedDimX(double x) {
    auto& v = m_pXform->getGlobalScale();
    m_pXform->setGlobalScale(math::Vec3f(x, v.y, v.z));
}

void TransformWidget::changedDimY(double y) {
    auto& v = m_pXform->getGlobalScale();
    m_pXform->setGlobalScale(math::Vec3f(v.x, y, v.z));
}

void TransformWidget::changedDimZ(double z) {
    auto& v = m_pXform->getGlobalScale();
    m_pXform->setGlobalScale(math::Vec3f(v.x, v.y, z));
}
