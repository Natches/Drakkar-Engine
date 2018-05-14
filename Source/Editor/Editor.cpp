#include <QFontDatabase>

#include "Editor.hpp"
#include "ui_editor.h"
#include "Engine/Engine.hpp"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    init();
}

Editor::~Editor()
{
    drak::core::Engine::Get().shutdown();
    delete ui;
}

void Editor::init()
{
    loadFonts();
    setupDocks();
    setupToolbar();

    drak::core::Engine::Get().startup();
    drak::core::Engine::Get().startLoop();
}

void Editor::setupDocks()
{
    setCentralWidget(ui->dock_RenderTarget);
    splitDockWidget(ui->dock_Project, ui->dock_Console, Qt::Horizontal);

    ui->scrollArea->setWidget(new TransformWidget);
}

void Editor::setupToolbar()
{
    QWidget* spacerL = new QWidget(this);
    spacerL->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    spacerL->setVisible(true);
    ui->toolBar->addWidget(spacerL);

    ui->toolBar->addAction(ui->actionPlay);

    QWidget* spacerR = new QWidget(this);
    spacerR->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    spacerR->setVisible(true);
    ui->toolBar->addWidget(spacerR);
}

/*
void Editor::setProjectPath(QString dir)
{
    QModelIndex folderRoot = folderModel->setRootPath(dir);
    ui->treeView->setModel(folderModel);
    ui->treeView->setRootIndex(folderRoot);
    ui->treeView->setColumnHidden(1, true);
    ui->treeView->setColumnHidden(2, true);
    ui->treeView->setColumnHidden(3, true);

    QModelIndex fileRoot = fileModel->setRootPath(dir);
    ui->listView->setModel(fileModel);
    ui->listView->setRootIndex(fileRoot);
}
*/

void Editor::loadFonts()
{
    QFontDatabase::addApplicationFont(":/Input-Regular.ttf");
    QFont font(":/Input", 10, 1);
    QApplication::setFont(font);
}

/*
void Editor::on_newProject_triggered()
{
    QString directory =
            QFileDialog::getExistingDirectory(
                this,
                tr("Select a project directory."),
                QCoreApplication::applicationDirPath());
    setProjectPath(directory);
}
*/

void Editor::on_toggleView_SceneGraph_triggered() {
    ui->dock_SceneGraph->toggleViewAction()->trigger();
}

void Editor::on_toggleView_Project_triggered() {
    ui->dock_Project->toggleViewAction()->trigger();
}

void Editor::on_toggleView_Inspector_triggered() {
    ui->dock_Inspector->toggleViewAction()->trigger();
}

void Editor::on_toggleView_Console_triggered() {
    ui->dock_Console->toggleViewAction()->trigger();
}

/*
void Editor::on_treeView_clicked(const QModelIndex &index) {
    ui->listView->setRootIndex(fileModel->setRootPath(fileModel->fileInfo(index).absoluteFilePath()));
}

void Editor::on_actionWireframe_triggered(bool toggle)
{

}

void Editor::on_actionAdd_Cube_triggered()
{

}
*/
