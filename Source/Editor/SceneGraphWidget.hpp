#ifndef SCENEGRAPHWIDGET_HPP
#define SCENEGRAPHWIDGET_HPP

#include <QTreeWidget>

class SceneGraphWidget : public QTreeWidget {
    Q_OBJECT
public:
    explicit SceneGraphWidget(QWidget *parent = 0);
    ~SceneGraphWidget();
};

#endif // SCENEGRAPHWIDGET_HPP
