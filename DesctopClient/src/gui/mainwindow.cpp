//
// Created by Aleksandr Burdovitzin on 06.10.2025.
//

#include "../../include/gui/mainwindow.h"

#include <qcoreapplication.h>
#include <QMenuBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    mainWidget = new QWidget;
    setCentralWidget(mainWidget);

    topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QLabel *infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
        "invoke a context menu</i>"));

    mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(5, 5, 5, 5);
    mainLayout->addWidget(topFiller);
    mainLayout->addWidget(infoLabel);
    mainLayout->addWidget(bottomFiller);
    mainWidget->setLayout(mainLayout);

    mainMenuBar = menuBar();

    mainToolBar = addToolBar(tr("Main Toolbar"));
    mainToolBar->setMovable(false);

    createActions();
    createMenus();
    createToolBar();

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    QString message = tr("A context menu is available by right-clicking");
    statusBar->showMessage(message);

    setWindowTitle(tr("Ecodor laboratory"));
}

MainWindow::~MainWindow() {
    if (mainWidget != nullptr) delete mainWidget;
    if (topFiller != nullptr) delete topFiller;
    if (bottomFiller != nullptr) delete bottomFiller;
    if (mainLayout != nullptr) delete mainLayout;
}

void MainWindow::onSetup() {
    QMessageBox::about(this, tr("Settings"), tr("Input Settings"));
}

void MainWindow::onLicense() {
    QMessageBox::about(this, tr("Licanse"), tr("Input License"));
}

void MainWindow::onAbout() {
    QMessageBox::about(this, tr("About Menu"),
                       tr("The <b>Menu</b> example shows how to create "
                           "menu-bar menus and context menus."));
}

void MainWindow::createActions() {
    createEmptyActions();
}

void MainWindow::createEmptyActions() {
    quitAction = new QAction(QIcon(":/res/icons/crushed.png"), tr("Quit"), this);

    setupAction = new QAction(QIcon(":/res/icons/laboratory.png"), tr("Settings"), this);
    licenseAction = new QAction(QIcon(":/res/icons/search.png"), tr("License"), this);
    aboutAction = new QAction(QIcon(":/res/icons/sand.png"), tr("About"), this);

    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

    connect(setupAction, SIGNAL(triggered()), this, SLOT(onSetup()));
    connect(licenseAction,SIGNAL(triggered()), this, SLOT(onLicense()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(onAbout()));
}

void MainWindow::createMenus() {
    createEmptyMenus();
}

void MainWindow::createEmptyMenus() {
    taskMenu = mainMenuBar->addMenu(tr("&File"));
    taskMenu->addAction(quitAction);

    aboutMenu = mainMenuBar->addMenu(tr("&About"));
    aboutMenu->addAction(setupAction);
    aboutMenu->addAction(licenseAction);
    aboutMenu->addAction(aboutAction);
}

void MainWindow::createToolBar() {
    createEmptyToolBar();
}

void MainWindow::createEmptyToolBar() {
    mainToolBar->addAction(setupAction);
    mainToolBar->addAction(licenseAction);
    mainToolBar->addAction(aboutAction);

    mainToolBar->addSeparator();

    mainToolBar->addAction(quitAction);
}

void MainWindow::setTaskType(TaskType taskType) {
    if (currentTaskType != taskType) {
        currentTaskType = taskType;
        mainToolBar->clear();
        mainMenuBar->clear();

        switch (taskType) {
            STONE_MATERIALS:
                setStoneMaterialsTask();
                break;
            ROAD_BITUMEN:
                setRoadBitumenTask();
                break;
            SUPPLEMENTS:
                setSupplementsTask();
                break;
            ASPHALT_CONCRETE:
                setAsphaltConcreteTask();
                break;
            SOILS:
                setSoilsTask();
                break;
            SELECTION:
                setSelectionTask();
                break;
            DEVICES:
                setDevicesTask();
                break;
            default:
                setEmptyTask();
                break;
        }
    }
}

void MainWindow::setStoneMaterialsTask() {
    setEmptyTask();
}

void MainWindow::setRoadBitumenTask() {
    setEmptyTask();
}

void MainWindow::setSupplementsTask() {
    setEmptyTask();
}

void MainWindow::setAsphaltConcreteTask() {
    setEmptyTask();
}

void MainWindow::setSoilsTask() {
    setEmptyTask();
}

void MainWindow::setSelectionTask() {
    setEmptyTask();
}

void MainWindow::setDevicesTask() {
    setEmptyTask();
}

void MainWindow::setEmptyTask() {
}
