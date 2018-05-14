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
    delete ui;
}

void Editor::loadFonts()
{
    QFontDatabase::addApplicationFont(":/Input-Regular.ttf");
    QFont font(":/Input", 10, 1);
    QApplication::setFont(font);
}

void Editor::init()
{
    loadFonts();

    splitDockWidget(ui->dock_Project, ui->dock_Console, Qt::Horizontal);
    drak::core::Engine::Get().startup();
}
