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
    void onTODO();

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

    void createChooseActions();
    void createStoneMaterialsActions();
    void createRoadMaterialsActions();
    void createSupplementsActions();
    void createAsphaltConcreteActions();
    void createSoilsActions();
    void createSelectionActions();
    void createDevicesActions();
    void createEmptyActions();

    void createMenus();

    void createChooseMenus();
    void createStoneMaterialsMenus();
    void createRoadMaterialsMenus();
    void createSupplementsMenus();
    void createAsphaltConcreteMenus();
    void createSoilsMenus();
    void createSelectionMenus();
    void createDevicesMenus();
    void createEmptyMenus();

    void createToolBar();

    void createChooseToolBar();
    void createStoneMaterialsToolBar();
    void createRoadMaterialsToolBar();
    void createSupplementsToolBar();
    void createAsphaltConcreteToolBar();
    void createSoilsToolBar();
    void createSelectionToolBar();
    void createDevicesToolBar();
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

    //========================================
    QMenu *chooseMenu;

    QAction *chooseStoneMaterialsAction;
    QAction *chooseRoadBitumenAction;
    QAction *chooseSupplementsAction;
    QAction *chooseAsphaltСoncreteAction;
    QAction *chooseSoilsAction;
    QAction *chooseSelectionAction;
    QAction *chooseDevicesAction;
    //----------------------------------------
    QAction *quitAction;
    //========================================

    // Каменные материалы (SM)
    QMenu *smMaterials;
    QMenu *smSearch;
    QMenu *smDictonary;
    QMenu *smTools;

    QAction *smCrushedStoneAction;
    QAction *smSandAction;
    QAction *smGravelMixAction;
    QAction *smDropoutAction;
    QAction *smPowderAction;
    QAction *smObjectSearchAction;
    QAction *smRocksDictAction;
    QAction *smManufacturerDictAction;
    QAction *smTestingOrgDictAction;
    QAction *smCertificationCentersDictAction;
    QAction *smImportAction;
    QAction *smExportAction;

    // Дорожные битумы (RD)
    QMenu *rdMaterials;
    QMenu *rdDictonary;
    QMenu *rdTools;

    QAction *rdPetroleumBitumenAction;
    QAction *rdBitumenGradesDictAction;
    QAction *rdManufacturerDictAction;
    QAction *rdTestingOrgDictAction;
    QAction *rdCertificationCentersAction;
    QAction *rdRegulatoryDocumentsAction;
    QAction *rdImportAction;
    QAction *rdExportAction;

    // Добавки (SU)
    QMenu *suMaterials;
    QMenu *suDictonary;
    QMenu *suTools;

    QAction *suModifyingSupplementsAction;
    QAction *suManufacturerDictAction;
    QAction *suCertificationCentersAction;
    QAction *suImportAction;
    QAction *suExportAction;

    // Асфальтобетон (AC)
    QMenu *acMaterials;
    QMenu *acDictonary;
    QMenu *acTools;

    QAction *acAsphaltConcreteAction;
    QAction *acFellingsAction;
    QAction *acACRequeredDictAction;
    QAction *acACMixedTypeDictAction;
    QAction *acHighwaysDictAction;
    QAction *acTestingOrgDictAction;
    QAction *acCertificationCentersDictAction;
    QAction *acImportAction;
    QAction *acExportAction;

    // Грунты (SO)
    QMenu *soMaterials;
    QMenu *soDictonary;
    QMenu *soTools;

    QAction *soCompactionFactorAction;
    QAction *soCohesiveSoilsAction;
    QAction *soUncohesiveSoilsAction;
    QAction *soSoilsTypeDictAction;
    QAction *soHighwaysDictAction;
    QAction *soCertificationCentersDictAction;
    QAction *soImportAction;
    QAction *soExportAction;

    // Подбор (SE)
    QMenu *seMaterials;
    QMenu *seDictonary;
    QMenu *seTools;

    QAction *seRocksSelectionAction;
    QAction *seGostRequirementsAction;
    QAction *seTypeOfMaterialsAction;
    QAction *seACMixedTypeDictAction;
    QAction *seHighwaysDictAction;
    QAction *seTestingOrgDictAction;
    QAction *seCertificationCentersDictAction;
    QAction *seImportAction;
    QAction *seExportAction;

    // Приборы (DE)
    QMenu *deMaterials;
    QMenu *deDictonary;
    QMenu *deTools;

    QAction *deTestFacilitiesAction; //Средства испытания
    QAction *deTestEquipmentAction; //Испытательное оборудование
    QAction *deAuxiliaryEquipmentAction; //Вспомогательное оборудование
    QAction *deStandardSamplesAction; //Стандартные образцы
    QAction *deCountriesDictAction;
    QAction *deManufacturerDictAction;
    QAction *deMeasuringValueDictAction;
    QAction *deRegulatoryDocumentDictAction;
    QAction *deRegulatoryDocTypeDictAction;
    QAction *deMetrologicalControlDictAction;
    QAction *deMetrologicalOrganizationDictAction;
    QAction *deCategoriesSODictAction;
    QAction *deImportAction;
    QAction *deExportAction;
    //========================================

    QMenu *aboutMenu;

    QAction *setupAction;
    QAction *licenseAction;
    QAction *aboutAction;
};
#endif // MAINWINDOW_H
