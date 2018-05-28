#ifndef INSPECTORWIDGET_HPP
#define INSPECTORWIDGET_HPP

#include <QTreeWidget>
#include "Engine/GameObject.hpp"
#include "TransformWidget.hpp"
#include "BoxColliderWidget.hpp"
#include "RigidBodyWidget.hpp"

class InspectorWidget final : public QTreeWidget {
    Q_OBJECT
public:
    explicit InspectorWidget(QWidget *parent = 0);
    ~InspectorWidget();

    void inspect(drak::GameObject* target);

private:
    void addComponents();
    void addComponent(QWidget* widget, QString name);

private:
    TransformWidget     *transformWidget;
    BoxColliderWidget   *boxColliderWidget;
    RigidBodyWidget     *rigidBodyWidget;

    drak::GameObject    *m_pTarget;
};

#endif // INSPECTORWIDGET_HPP
