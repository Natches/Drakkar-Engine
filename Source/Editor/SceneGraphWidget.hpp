#ifndef SCENEGRAPHWIDGET_HPP
#define SCENEGRAPHWIDGET_HPP

#include <QTreeWidget>
#include <QDropEvent>
#include "Engine/GameObject.hpp"

/**************************************************************************************************
 *  Scene GameObject
 *************************************************************************************************/

class SceneGameObject final : public QTreeWidgetItem {
public:
    explicit SceneGameObject(drak::GameObject& obj, QTreeWidget* parent = 0);
    ~SceneGameObject();

    void addGameObject(SceneGameObject *node);
    drak::GameObject& gameObject;
};


/**************************************************************************************************
 *  Scene Graph
 *************************************************************************************************/

class SceneGraphWidget final : public QTreeWidget {
    Q_OBJECT
public:
    explicit SceneGraphWidget(QWidget *parent = 0);
    ~SceneGraphWidget();

    void addGameObject(SceneGameObject* node);

protected:
    virtual void dropEvent(QDropEvent *event) override;

};

#endif // SCENEGRAPHWIDGET_HPP
