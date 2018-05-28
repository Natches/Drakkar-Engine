#include <QDebug>
#include <QLabel>

#include "Engine/Scene/LevelSystem.hpp"
#include "InspectorWidget.hpp"

using namespace drak;
using namespace drak::components;

InspectorWidget::InspectorWidget(QWidget *parent)
:   QTreeWidget(parent) {
    setHeaderHidden(true);
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    setSelectionMode(QAbstractItemView::SingleSelection);

    addComponents();
}


InspectorWidget::~InspectorWidget() {

}

void InspectorWidget::inspect(GameObject* target) {
    m_pTarget = target;
    transformWidget->setTransform(target->getComponent<Transform>());
}

void InspectorWidget::addComponents() {
    transformWidget = new TransformWidget;
    addComponent(transformWidget, "Transform");

    boxColliderWidget = new BoxColliderWidget;
    addComponent(boxColliderWidget, "Box Collider");

    rigidBodyWidget = new RigidBodyWidget;
    addComponent(rigidBodyWidget, "Rigid Body");
}

void InspectorWidget::addComponent(QWidget* widget, QString name) {
    QTreeWidgetItem *parent = new QTreeWidgetItem(this);
    QTreeWidgetItem *child  = new QTreeWidgetItem();

    parent->setText(0, name);
    parent->setTextAlignment(0, Qt::AlignCenter);
    parent->addChild(child);

    setItemWidget(child, 0, widget);
}
