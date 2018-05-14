#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

#include "transformwidget.h"

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();

private:
    void init();
    void setupDocks();
    void setupToolbar();

    void loadFonts();

private slots:
    //void on_newProject_triggered();

    void on_toggleView_Project_triggered();
    void on_toggleView_Inspector_triggered();
    void on_toggleView_Console_triggered();
    void on_toggleView_SceneGraph_triggered();

    //void on_treeView_clicked(const QModelIndex &index);

    //void on_actionWireframe_triggered(bool checked);
    //void on_actionAdd_Cube_triggered();

private:
    Ui::Editor *ui;

    TransformWidget		*transformWidget;
    //QFileSystemModel    *folderModel, *fileModel;
};

#endif // EDITOR_H
