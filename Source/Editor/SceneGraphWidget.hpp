#ifndef SCENEGRAPHWIDGET_HPP
#define SCENEGRAPHWIDGET_HPP

#include <QTreeWidget>
#include <QDropEvent>

class SceneGraphWidget final : public QTreeWidget {
    Q_OBJECT
public:
    explicit SceneGraphWidget(QWidget *parent = 0);
    ~SceneGraphWidget();

    void addTreeRoot(QString name);
    void addTreeChild(QTreeWidgetItem *parent, QString name);

protected:
    virtual void dropEvent(QDropEvent *event) override;
};

#endif // SCENEGRAPHWIDGET_HPP
