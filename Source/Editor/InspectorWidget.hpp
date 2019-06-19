#ifndef INSPECTORWIDGET_HPP
#define INSPECTORWIDGET_HPP

#include <QTreeWidget>
#include "TransformWidget.hpp"
#include "BoxColliderWidget.hpp"

class InspectorWidget final : public QTreeWidget {
    Q_OBJECT
public:
    explicit InspectorWidget(QWidget *parent = 0);
    ~InspectorWidget();

private:
    void addComponents();
    void addComponent(QWidget* widget, QString name);

private:
    TransformWidget     *transformWidget;
    BoxColliderWidget   *boxColliderWidget;
};

#endif // INSPECTORWIDGET_HPP
