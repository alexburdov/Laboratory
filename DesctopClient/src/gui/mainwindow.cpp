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

void MainWindow::onTODO() {
    qDebug() << "DO TO";
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
    createChooseActions();
    createStoneMaterialsActions();
    createRoadMaterialsActions();
    createSupplementsActions();
    createAsphaltConcreteActions();
    createSoilsActions();
    createSelectionActions();
    createDevicesActions();
    createEmptyActions();
}

void MainWindow::createChooseActions() {
    chooseStoneMaterialsAction = new QAction(tr("Stone Material"), this);
    chooseRoadBitumenAction = new QAction(tr("Road Bitumen"), this);
    chooseSupplementsAction = new QAction(tr("Supplements"), this);
    chooseAsphaltСoncreteAction = new QAction(tr("Asphalt Сoncrete"), this);
    chooseSoilsAction = new QAction(tr("Soils"), this);
    chooseSelectionAction = new QAction(tr("Selection"), this);
    chooseDevicesAction = new QAction(tr("Devices"), this);

    quitAction = new QAction(QIcon(":/res/icons/quit.png"), tr("Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);
}

void MainWindow::createStoneMaterialsActions() {
    smCrushedStoneAction = new QAction(QIcon(":/res/icons/rocks.png"), tr("Crushed rock from hard rocks"), this); // Щебень из твердых горных пород
    smSandAction = new QAction(QIcon(":/res/icons/sand.png"), tr("Sand"), this); // Песок
    smGravelMixAction = new QAction(QIcon(":/res/icons/crushed.png"), tr("Screenings from crushed sedimentary rocks"), this); // Отсев из дробления осадочных горных пород
    smDropoutAction = new QAction(QIcon(":/res/icons/powder.png"), tr("Mineral powder"), this); // Минеральный порошок
    smPowderAction = new QAction(QIcon(":/res/icons/search.png"), tr("Search for an object"), this); // Поиск объекта
    smObjectSearchAction  = new QAction(QIcon(":/res/icons/rocks_kind.png"), tr("Rocks"), this); // Горные породы
    smRocksDictAction = new QAction(QIcon(":/res/icons/manufacturer.png"), tr("Material manufacturer"), this); // Производитель материала
    smManufacturerDictAction = new QAction(QIcon(":/res/icons/test_organization.png"), tr("Organizations conducting tests"), this); // Организации, проводящие испытания
    smTestingOrgDictAction = new QAction(QIcon(":/res/icons/certificate_center.png"), tr("Certification centers"), this); // Сертификационные центры
    smCertificationCentersDictAction = new QAction(QIcon(":/res/icons/choice.png"), tr("Selecting a Database"), this); // Выбор базы данных
    smImportAction = new QAction(QIcon(":/res/icons/import.png"), tr("Import data"), this); // Импорт данных
    smExportAction = new QAction(QIcon(":/res/icons/export.png"), tr("Export data"), this); // Экспорт данных
}

void MainWindow::createRoadMaterialsActions() {
    rdPetroleumBitumenAction = new QAction(QIcon(":/res/icons/bitumen.png"), tr("Petroleum bitumen"), this); // Нефтяные битумы
    rdBitumenGradesDictAction = new QAction(QIcon(":/res/icons/bitumen_grades.png"), tr("Bitumen grades"), this); // Марки битумов
    rdManufacturerDictAction = new QAction(QIcon(":/res/icons/manufacturer.png"), tr("Manufacturer of materials"), this); // Производитель матерьялов
    rdTestingOrgDictAction = new QAction(QIcon(":/res/icons/test_organization.png"), tr("Organizations conducting tests"), this); // Организации, проводящие испытания
    rdCertificationCentersAction = new QAction(QIcon(":/res/icons/certificate_center.png"), tr("Certification centers"), this); // Сертификационные центры
    rdRegulatoryDocumentsAction = new QAction(QIcon(":/res/icons/document_list.png"), tr("Regulatory documents"), this); // Нормативные документы
    rdImportAction = new QAction(QIcon(":/res/icons/import.png"), tr("Import data"), this); // Импорт данных
    rdExportAction = new QAction(QIcon(":/res/icons/export.png"), tr("Export data"), this); // Экспорт данных
}

void MainWindow::createSupplementsActions() {
    suModifyingSupplementsAction = new QAction(QIcon(":/res/icons/modifying_additives.png"), tr("Modifying additives"), this); // Модифицирующие добавки
    suManufacturerDictAction = new QAction(QIcon(":/res/icons/manufacturer.png"), tr("Manufacturer of modifying additives"), this); // Производитель модифицирующих добавок
    suCertificationCentersAction = new QAction(QIcon(":/res/icons/certificate_center.png"), tr("Certification centers"), this); // Сертификационные центры
    suImportAction = new QAction(QIcon(":/res/icons/import.png"), tr("Import data"), this); // Импорт данных
    suExportAction = new QAction(QIcon(":/res/icons/export.png"), tr("Export data"), this); // Экспорт данных
}

void MainWindow::createAsphaltConcreteActions() {
    acAsphaltConcreteAction = new QAction(QIcon(":/res/icons/asphalt_concrete.png"), tr("Asphalt concrete mixtures"), this); // Асфальтобетонные смеси
    acFellingsAction = new QAction(QIcon(":/res/icons/felling.png"), tr("Fellings"), this); // Вырубки
    acACRequeredDictAction = new QAction(QIcon(":/res/icons/compaction.png"), tr("Requirements for asphalt concrete"), this); // Требования к асфальтобетону
    acACMixedTypeDictAction = new QAction(QIcon(":/res/icons/materials_type.png"), tr("Types of asphalt concrete mixtures"), this); // Типы асфальтобетонных смесей
    acHighwaysDictAction = new QAction(QIcon(":/res/icons/highways.png"), tr("Highways"), this); // Автомобильные дороги
    acTestingOrgDictAction = new QAction(QIcon(":/res/icons/test_organization.png"), tr("Organizations conducting tests"), this); // Организации, проводящие испытания
    acCertificationCentersDictAction = new QAction(QIcon(":/res/icons/certificate_center.png"), tr("Certification centers"), this); // Сертификационные центры
    acImportAction = new QAction(QIcon(":/res/icons/import.png"), tr("Import data"), this); // Импорт данных
    acExportAction = new QAction(QIcon(":/res/icons/export.png"), tr("Export data"), this); // Экспорт данных
}

void MainWindow::createSoilsActions() {
    soCompactionFactorAction = new QAction(QIcon(":/res/icons/compaction.png"), tr("Compaction factor"), this); // Коэффициент уплотнения
    soCohesiveSoilsAction = new QAction(QIcon(":/res/icons/cohesive_soils.png"), tr("Cohesive soils"), this); // Связанные грунты
    soUncohesiveSoilsAction = new QAction(QIcon(":/res/icons/uncohesive_soils.png"), tr("Uncohesive soils"), this); // Несвязные грунты
    soSoilsTypeDictAction = new QAction(QIcon(":/res/icons/type_of_soil.png"), tr("Soil types"), this); // Типы грунтов
    soHighwaysDictAction = new QAction(QIcon(":/res/icons/highways.png"), tr("Highways"), this); // Автомобильные дороги
    soCertificationCentersDictAction = new QAction(QIcon(":/res/icons/certificate_center.png"), tr("Certification centers"), this); // Сертификационные центры
    soImportAction = new QAction(QIcon(":/res/icons/import.png"), tr("Import data"), this); // Импорт данных
    soExportAction = new QAction(QIcon(":/res/icons/export.png"), tr("Export data"), this); // Экспорт данных
}

void MainWindow::createSelectionActions() {
    seRocksSelectionAction = new QAction(QIcon(":/res/icons/selection_of_materials.png"), tr("Selection of stone materials"), this); // Подбор каменных материалов
    seGostRequirementsAction = new QAction(QIcon(":/res/icons/curve.png"), tr("Requirements for the particle size distribution curve"), this); // Требования к кривой гранулометрического состава
    seTypeOfMaterialsAction = new QAction(QIcon(":/res/icons/materials_type.png"), tr("Types of materials"), this); // Типы материалов
    seACMixedTypeDictAction = new QAction(QIcon(":/res/icons/type_ac_mixed.png"), tr("Types of asphalt concrete mixtures"), this); // Типы асфальтобетонных смесей
    seHighwaysDictAction = new QAction(QIcon(":/res/icons/highways.png"), tr("Highways"), this); // Автомобильные дороги
    seTestingOrgDictAction = new QAction(QIcon(":/res/icons/test_organization.png"), tr("Organizations conducting tests"), this); // Организации, проводящие испытания
    seCertificationCentersDictAction = new QAction(QIcon(":/res/icons/certificate_center.png"), tr("Certification centers"), this); // Сертификационные центры
    seImportAction = new QAction(QIcon(":/res/icons/import.png"), tr("Import data"), this); // Импорт данных
    seExportAction = new QAction(QIcon(":/res/icons/export.png"), tr("Export data"), this); // Экспорт данных
}

void MainWindow::createDevicesActions() {
    deTestFacilitiesAction = new QAction(QIcon(":/res/icons/test_facilities.png"), tr("Test facilities"), this); // Средства испытания
    deTestEquipmentAction = new QAction(QIcon(":/res/icons/test_equipment.png"), tr("Test equipment"), this); // Испытательное оборудование
    deAuxiliaryEquipmentAction = new QAction(QIcon(":/res/icons/auxiliary_equipment.png"), tr("Auxiliary equipment"), this); // Вспомогательное оборудование
    deStandardSamplesAction = new QAction(QIcon(":/res/icons/standart_samples.png"), tr("Standard samples"), this); // Стандартные образцы
    deCountriesDictAction = new QAction(QIcon(":/res/icons/country_list.png"), tr("Country of origin"), this); // Страна-изготовитель
    deManufacturerDictAction = new QAction(QIcon(":/res/icons/factory_list.png"), tr("Manufacturers and suppliers"), this); // Изготовители и поставщики
    deMeasuringValueDictAction = new QAction(QIcon(":/res/icons/list_of_measured_quantities.png"), tr("Measured quantities"), this); // Измерительные величины
    deRegulatoryDocumentDictAction = new QAction(QIcon(":/res/icons/document_list.png"), tr("Regulatory documents"), this); // Нормативные документы
    deRegulatoryDocTypeDictAction = new QAction(QIcon(":/res/icons/type_of_documents.png"), tr("Type of regulatory documents"), this); // Тип нормативных документов
    deMetrologicalControlDictAction = new QAction(QIcon(":/res/icons/type_of_control.png"), tr("Type of metrological control"), this); // Вид метрологического контроля
    deMetrologicalOrganizationDictAction = new QAction(QIcon(":/res/icons/metrological_control.png"), tr("Organization implementing metrological control"), this); // Организация, осуществляющая метрологический контроль
    deCategoriesSODictAction = new QAction(QIcon(":/res/icons/category_so.png"), tr("Categories CO"), this); // Категории СО
    deImportAction = new QAction(QIcon(":/res/icons/import.png"), tr("Import data"), this); // Импорт данных
    deExportAction = new QAction(QIcon(":/res/icons/export.png"), tr("Export data"), this); // Экспорт данных
}

void MainWindow::createEmptyActions() {
    setupAction = new QAction(QIcon(":/res/icons/settings.png"), tr("Settings"), this);
    licenseAction = new QAction(QIcon(":/res/icons/license.png"), tr("License"), this);
    aboutAction = new QAction(QIcon(":/res/icons/about.png"), tr("About"), this);

    connect(setupAction, SIGNAL(triggered()), this, SLOT(onSetup()));
    connect(licenseAction,SIGNAL(triggered()), this, SLOT(onLicense()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(onAbout()));
}

void MainWindow::createMenus() {
    createChooseMenus();

    createStoneMaterialsMenus();
    createRoadMaterialsMenus();
    createSupplementsMenus();
    createAsphaltConcreteMenus();
    createSoilsMenus();
    createSelectionMenus();
    createDevicesMenus();

    createEmptyMenus();
}

void MainWindow::createChooseMenus() {
}

void MainWindow::createStoneMaterialsMenus() {
}

void MainWindow::createRoadMaterialsMenus() {
}

void MainWindow::createSupplementsMenus() {
}

void MainWindow::createAsphaltConcreteMenus() {
}

void MainWindow::createSoilsMenus() {
}

void MainWindow::createSelectionMenus() {
}

void MainWindow::createDevicesMenus() {
}

void MainWindow::createEmptyMenus() {
    // taskMenu = mainMenuBar->addMenu(tr("&File"));
    // taskMenu->addAction(quitAction);

    aboutMenu = mainMenuBar->addMenu(tr("&About"));
    aboutMenu->addAction(setupAction);
    aboutMenu->addAction(licenseAction);
    aboutMenu->addAction(aboutAction);
}

void MainWindow::createToolBar() {
    createEmptyToolBar();
}

void MainWindow::createChooseToolBar() {
}

void MainWindow::createStoneMaterialsToolBar() {
}

void MainWindow::createRoadMaterialsToolBar() {
}

void MainWindow::createSupplementsToolBar() {
}

void MainWindow::createAsphaltConcreteToolBar() {
}

void MainWindow::createSoilsToolBar() {
}

void MainWindow::createSelectionToolBar() {
}

void MainWindow::createDevicesToolBar() {
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
