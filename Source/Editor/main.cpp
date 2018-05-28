#include <QApplication>

#include "DarkStyle.h"
#include "framelesswindow.h"

#include "Editor.hpp"

int main(int argc, char *argv[]) {
    QApplication drakEditor(argc, argv);
    drakEditor.setStyle(new DarkStyle);
    drakEditor.setWindowIcon(QIcon(":/Drakkar.ico"));

    Editor editor;
    editor.setWindowTitle("Drakkar Editor");
    editor.setWindowState(Qt::WindowMaximized);
    //editor.show();

    FramelessWindow framelessWin;
    framelessWin.setContent(&editor);
    framelessWin.setWindowTitle("Drakkar Editor");
    framelessWin.setWindowState(Qt::WindowMaximized);
    framelessWin.show();


    return drakEditor.exec();
}
