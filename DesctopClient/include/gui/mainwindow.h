//
// Created by Aleksandr Burdovitzin on 06.10.2025.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QStatusBar>

class Definitions;

class MainWindow : public QMainWindow {
    Q_OBJECT

    enum TaskType {
        STONE_MATERIALS, // Каменные материалы (SM)
        ROAD_BITUMEN, // Дорожные битумы (RD)
        SUPPLEMENTS, // Добавки (SU)
        ASPHALT_CONCRETE, // Асфальтобетон (AC)
        SOILS, // Грунты (SO)
        SELECTION, // Подбор (SE)
        DEVICES // Приборы (DE)
    };

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void onSetup();

    void onLicense();

    void onAbout();

private:
    QWidget *mainWidget;
    QWidget *topFiller;
    QWidget *bottomFiller;
    QVBoxLayout *mainLayout;
    QStatusBar *statusBar;

    QMenuBar *mainMenuBar;
    QToolBar *mainToolBar;

    TaskType currentTaskType;

    void createActions();

    void createEmptyActions();

    void createMenus();

    void createEmptyMenus();

    void createToolBar();

    void createEmptyToolBar();

    void setTaskType(TaskType taskType);

    void setStoneMaterialsTask();

    void setRoadBitumenTask();

    void setSupplementsTask();

    void setAsphaltConcreteTask();

    void setSoilsTask();

    void setSelectionTask();

    void setDevicesTask();

    void setEmptyTask();

    QMenu *taskMenu;


    QMenu *aboutMenu;


    QAction *quitAction;
    QAction *setupAction;
    QAction *licenseAction;
    QAction *aboutAction;
};
#endif // MAINWINDOW_H
