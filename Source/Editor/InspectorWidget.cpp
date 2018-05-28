#include <QDebug>
#include <QLabel>

#include "InspectorWidget.hpp"

InspectorWidget::InspectorWidget(QWidget *parent)
:   QTreeWidget(parent) {
    setHeaderHidden(true);
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    setSelectionMode(QAbstractItemView::SingleSelection);

    addComponents();
}


InspectorWidget::~InspectorWidget() {

}


void InspectorWidget::addComponents() {
    transformWidget = new TransformWidget;
    addComponent(transformWidget, "Transform");

    boxColliderWidget = new BoxColliderWidget;
    addComponent(boxColliderWidget, "Box Collider");
}

void InspectorWidget::addComponent(QWidget* widget, QString name) {
    QTreeWidgetItem *parent = new QTreeWidgetItem(this);
    QTreeWidgetItem *child  = new QTreeWidgetItem();

    parent->setText(0, name);
    parent->setTextAlignment(0, Qt::AlignCenter);
    parent->addChild(child);

    setItemWidget(child, 0, widget);
}
