#include <QDebug>

#include "SceneGraphWidget.hpp"
#include "Engine/Engine.hpp"
#include "TransformWidget.hpp"

using namespace drak;
using namespace drak::core;

/**************************************************************************************************
 *  Scene GameObject
 *************************************************************************************************/

SceneGameObject::SceneGameObject(GameObject& obj, QTreeWidget* parent)
:   gameObject(obj),
    QTreeWidgetItem(parent) {
}


SceneGameObject::~SceneGameObject() {

}


void SceneGameObject::addGameObject(SceneGameObject *node) {
    node->setText(0, node->gameObject.name.c_str());
    addChild(node);
}


/**************************************************************************************************
 *  Scene Graph
 *************************************************************************************************/

SceneGraphWidget::SceneGraphWidget(QWidget *parent)
:   QTreeWidget(parent) {
    setColumnCount(1);

    setHeaderHidden(true);
    setDragEnabled(true);
    setDropIndicatorShown(true);

    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragDropMode(QAbstractItemView::InternalMove);
}


SceneGraphWidget::~SceneGraphWidget() {

}

void SceneGraphWidget::addGameObject(SceneGameObject* node) {
    node->setText(0, node->gameObject.name.c_str());
}


void SceneGraphWidget::dropEvent(QDropEvent *evt) {
    QModelIndex         index   = indexAt(evt->pos());
    QTreeWidgetItem*    item    = itemFromIndex(index);

    //item->setSelected(true);
    QTreeWidget::dropEvent(evt);
}
