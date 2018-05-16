/********************************************************************************
** Form generated from reading UI file 'Editor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QAction *toggleView_Console;
    QAction *toggleView_Inspector;
    QAction *toggleView_Project;
    QAction *newProject;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *toggleView_SceneGraph;
    QAction *actionAdd_Cube;
    QAction *actionWireframe;
    QAction *actionPlay;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuScene;
    QDockWidget *dock_Inspector;
    QWidget *dockWidgetContents_10;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QDockWidget *dock_Console;
    QWidget *dockWidgetContents_11;
    QToolBar *toolBar;
    QDockWidget *dock_Project;
    QWidget *dockWidgetContents_12;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QListView *listView;
    QDockWidget *dock_SceneGraph;
    QWidget *dockWidgetContents_2;
    QDockWidget *dock_RenderTarget;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QStringLiteral("Editor"));
        Editor->resize(1600, 900);
        QFont font;
        font.setFamily(QStringLiteral("Input"));
        font.setPointSize(10);
        Editor->setFont(font);
        Editor->setWindowOpacity(1);
        Editor->setAutoFillBackground(false);
        Editor->setStyleSheet(QStringLiteral(""));
        Editor->setDockNestingEnabled(true);
        Editor->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::GroupedDragging|QMainWindow::VerticalTabs);
        toggleView_Console = new QAction(Editor);
        toggleView_Console->setObjectName(QStringLiteral("toggleView_Console"));
        toggleView_Console->setCheckable(true);
        toggleView_Console->setChecked(true);
        toggleView_Console->setEnabled(true);
        toggleView_Inspector = new QAction(Editor);
        toggleView_Inspector->setObjectName(QStringLiteral("toggleView_Inspector"));
        toggleView_Inspector->setCheckable(true);
        toggleView_Inspector->setChecked(true);
        toggleView_Inspector->setEnabled(true);
        toggleView_Project = new QAction(Editor);
        toggleView_Project->setObjectName(QStringLiteral("toggleView_Project"));
        toggleView_Project->setCheckable(true);
        toggleView_Project->setChecked(true);
        toggleView_Project->setEnabled(true);
        newProject = new QAction(Editor);
        newProject->setObjectName(QStringLiteral("newProject"));
        newProject->setEnabled(false);
        actionOpen = new QAction(Editor);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setEnabled(true);
        actionSave = new QAction(Editor);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        toggleView_SceneGraph = new QAction(Editor);
        toggleView_SceneGraph->setObjectName(QStringLiteral("toggleView_SceneGraph"));
        toggleView_SceneGraph->setCheckable(true);
        toggleView_SceneGraph->setChecked(true);
        toggleView_SceneGraph->setEnabled(true);
        actionAdd_Cube = new QAction(Editor);
        actionAdd_Cube->setObjectName(QStringLiteral("actionAdd_Cube"));
        actionAdd_Cube->setEnabled(false);
        actionWireframe = new QAction(Editor);
        actionWireframe->setObjectName(QStringLiteral("actionWireframe"));
        actionWireframe->setCheckable(true);
        actionWireframe->setChecked(true);
        actionWireframe->setEnabled(true);
        actionPlay = new QAction(Editor);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/darkstyle/icon_play_pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon);
        centralWidget = new QWidget(Editor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        Editor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Editor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuView->setEnabled(true);
        menuScene = new QMenu(menuBar);
        menuScene->setObjectName(QStringLiteral("menuScene"));
        menuScene->setEnabled(true);
        Editor->setMenuBar(menuBar);
        dock_Inspector = new QDockWidget(Editor);
        dock_Inspector->setObjectName(QStringLiteral("dock_Inspector"));
        dock_Inspector->setMinimumSize(QSize(340, 450));
        dock_Inspector->setMaximumSize(QSize(340, 524287));
        dock_Inspector->setCursor(QCursor(Qt::ArrowCursor));
        dock_Inspector->setAcceptDrops(false);
        dock_Inspector->setStyleSheet(QStringLiteral(""));
        dock_Inspector->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_10 = new QWidget();
        dockWidgetContents_10->setObjectName(QStringLiteral("dockWidgetContents_10"));
        dockWidgetContents_10->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(dockWidgetContents_10);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(dockWidgetContents_10);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(320, 0));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(1);
        scrollArea->setMidLineWidth(1);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 322, 413));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        dock_Inspector->setWidget(dockWidgetContents_10);
        Editor->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_Inspector);
        dock_Console = new QDockWidget(Editor);
        dock_Console->setObjectName(QStringLiteral("dock_Console"));
        dock_Console->setEnabled(true);
        dock_Console->setMinimumSize(QSize(512, 192));
        dock_Console->setLayoutDirection(Qt::LeftToRight);
        dock_Console->setStyleSheet(QLatin1String("QDockWidget \n"
"{\n"
"    border: 1px solid black;\n"
"}"));
        dock_Console->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_11 = new QWidget();
        dockWidgetContents_11->setObjectName(QStringLiteral("dockWidgetContents_11"));
        dock_Console->setWidget(dockWidgetContents_11);
        Editor->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dock_Console);
        toolBar = new QToolBar(Editor);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMinimumSize(QSize(24, 24));
        toolBar->setMaximumSize(QSize(16777215, 16777215));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(24, 24));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolBar->setFloatable(false);
        Editor->addToolBar(Qt::TopToolBarArea, toolBar);
        dock_Project = new QDockWidget(Editor);
        dock_Project->setObjectName(QStringLiteral("dock_Project"));
        dock_Project->setMinimumSize(QSize(192, 192));
        dock_Project->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable);
        dock_Project->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);
        dockWidgetContents_12 = new QWidget();
        dockWidgetContents_12->setObjectName(QStringLiteral("dockWidgetContents_12"));
        gridLayout = new QGridLayout(dockWidgetContents_12);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(1);
        gridLayout->setContentsMargins(1, 0, 1, 1);
        treeView = new QTreeView(dockWidgetContents_12);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setMaximumSize(QSize(256, 16777215));

        gridLayout->addWidget(treeView, 0, 0, 1, 1);

        listView = new QListView(dockWidgetContents_12);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMovement(QListView::Static);
        listView->setLayoutMode(QListView::Batched);
        listView->setViewMode(QListView::IconMode);
        listView->setUniformItemSizes(true);
        listView->setWordWrap(true);

        gridLayout->addWidget(listView, 0, 1, 1, 1);

        dock_Project->setWidget(dockWidgetContents_12);
        Editor->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dock_Project);
        dock_SceneGraph = new QDockWidget(Editor);
        dock_SceneGraph->setObjectName(QStringLiteral("dock_SceneGraph"));
        dock_SceneGraph->setMinimumSize(QSize(256, 300));
        dock_SceneGraph->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        dock_SceneGraph->setWidget(dockWidgetContents_2);
        Editor->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock_SceneGraph);
        dock_RenderTarget = new QDockWidget(Editor);
        dock_RenderTarget->setObjectName(QStringLiteral("dock_RenderTarget"));
        dock_RenderTarget->setStyleSheet(QStringLiteral("background:rgb(32, 32, 32)"));
        dock_RenderTarget->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dock_RenderTarget->setAllowedAreas(Qt::NoDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dock_RenderTarget->setWidget(dockWidgetContents);
        Editor->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock_RenderTarget);
        dock_Console->raise();
        dock_SceneGraph->raise();
        dock_RenderTarget->raise();

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuScene->menuAction());
        menuFile->addAction(newProject);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuView->addAction(toggleView_SceneGraph);
        menuView->addAction(toggleView_Project);
        menuView->addAction(toggleView_Inspector);
        menuView->addAction(toggleView_Console);
        menuView->addAction(actionWireframe);
        menuScene->addAction(actionAdd_Cube);

        retranslateUi(Editor);

        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QMainWindow *Editor)
    {
        Editor->setWindowTitle(QApplication::translate("Editor", "MainWindow", nullptr));
        toggleView_Console->setText(QApplication::translate("Editor", "Console", nullptr));
        toggleView_Inspector->setText(QApplication::translate("Editor", "Inspector", nullptr));
        toggleView_Project->setText(QApplication::translate("Editor", "Project", nullptr));
        newProject->setText(QApplication::translate("Editor", "New", nullptr));
        actionOpen->setText(QApplication::translate("Editor", "Open", nullptr));
        actionSave->setText(QApplication::translate("Editor", "Save", nullptr));
        toggleView_SceneGraph->setText(QApplication::translate("Editor", "Scene Graph", nullptr));
        actionAdd_Cube->setText(QApplication::translate("Editor", "Add Cube", nullptr));
        actionWireframe->setText(QApplication::translate("Editor", "Wireframe", nullptr));
        actionPlay->setText(QApplication::translate("Editor", "Play", nullptr));
        menuFile->setTitle(QApplication::translate("Editor", "File", nullptr));
        menuView->setTitle(QApplication::translate("Editor", "View", nullptr));
        menuScene->setTitle(QApplication::translate("Editor", "Scene", nullptr));
        dock_Inspector->setWindowTitle(QApplication::translate("Editor", "Inspector", nullptr));
        dock_Console->setWindowTitle(QApplication::translate("Editor", "Console", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Editor", "toolBar", nullptr));
        dock_Project->setWindowTitle(QApplication::translate("Editor", "Project", nullptr));
        dock_SceneGraph->setWindowTitle(QApplication::translate("Editor", "Scene Graph", nullptr));
        dock_RenderTarget->setWindowTitle(QApplication::translate("Editor", "Scene", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
