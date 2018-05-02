#include "Editor.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication editorApp(argc, argv);
    Editor editorWin;
    editorWin.show();

    return editorApp.exec();
}
