#include <QApplication>

#include "DarkStyle.h"
#include "framelesswindow.h"

#include "Editor.hpp"

int main(int argc, char *argv[])
{
    QApplication drakEditor(argc, argv);
    drakEditor.setStyle(new DarkStyle);

    Editor editor;

    FramelessWindow framelessWin;
    framelessWin.setContent(&editor);
    framelessWin.setWindowState(Qt::WindowMaximized);
    framelessWin.setWindowTitle("Drakkar Editor");
    framelessWin.show();

    return drakEditor.exec();
}
