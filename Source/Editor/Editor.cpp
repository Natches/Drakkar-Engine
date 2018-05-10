#include "Editor.hpp"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    init();
}

Editor::~Editor()
{
    delete ui;
}

void Editor::init()
{
    splitDockWidget(ui->dock_Project, ui->dock_Console, Qt::Horizontal);
}
