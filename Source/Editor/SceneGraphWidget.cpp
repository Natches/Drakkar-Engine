#include "SceneGraphWidget.hpp"
#include "Engine/Engine.hpp"
#include "Engine/Scene/LevelSystem.hpp"

using namespace drak::core;

SceneGraphWidget::SceneGraphWidget(QWidget *parent)
:   QTreeWidget(parent) {
    setColumnCount(1);

    addTreeRoot("A");
    addTreeRoot("B");
    addTreeRoot("C");

    setHeaderLabel("Game Object");
    setDragEnabled(true);
    setDropIndicatorShown(true);
    setSelectionMode(QAbstractItemView::MultiSelection);
    setDragDropMode(QAbstractItemView::InternalMove);

    drak::core::Engine::Get().currentLevel().getGameObjects();

}


SceneGraphWidget::~SceneGraphWidget() {

}


void SceneGraphWidget::addTreeRoot(QString name) {
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(this);

    treeItem->setText(0, name);
    addTreeChild(treeItem, name + "A");
    addTreeChild(treeItem, name + "B");
}

void SceneGraphWidget::addTreeChild(QTreeWidgetItem *parent, QString name) {
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    treeItem->setText(0, name);
    parent->addChild(treeItem);
}

void SceneGraphWidget::dropEvent(QDropEvent *evt) {
    QModelIndex         index   = indexAt(evt->pos());
    QTreeWidgetItem*    item    = itemFromIndex(index);

    //item->setSelected(true);
    QTreeWidget::dropEvent(evt);
}
