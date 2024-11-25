#include "appGUI.h"
#include "trenchCoatsTableModel.h"

GUI::GUI(Service& _service, QWidget* parent) : QMainWindow(parent), service(_service) {
    this->buildGUI();
}

void GUI::buildGUI() {
    this->setFixedSize(1200, 300);
    this->setWindowTitle("Proper Trench Coats");

    // Create the stacked widget and set it as central widget for the main window
    this->mainWidget = new QStackedWidget{};
    this->setCentralWidget(this->mainWidget);
    this->tableModel = new TrenchCoatsTableModel{this->service};
    this->setUpChooseMode();
}

void GUI::setUpChooseMode(){
    this->chooseModeWidget = new QWidget{};
    this->chooseModeLayout = new QVBoxLayout{};

    this->chooseModeLabel = new QLabel{ "Choose the Mode:" };
    this->chooseModeLayout->addWidget(this->chooseModeLabel, 0, Qt::AlignHCenter);

    // Add userButtons to switch between modes
    this->adminButton = new QPushButton("ADMIN MODE");
    this->chooseModeLayout->addWidget(this->adminButton);
    connect(this->adminButton, &QPushButton::clicked, this, &GUI::openAdminWindow);

    //Connect the userButtons
    this->userButton = new QPushButton("USER MODE");
    this->chooseModeLayout->addWidget(this->userButton);
    connect(this->userButton, &QPushButton::clicked, this, &GUI::openUserWindow);

    this->chooseModeWidget->setLayout(this->chooseModeLayout);
    this->mainWidget->addWidget(this->chooseModeWidget);
}

GUI::~GUI(){}

void GUI::openAdminWindow()  {
    this->adminWindow = new AdminGUI(this->service, this);
    connect(this->adminWindow, SIGNAL(CloseAdminWindow()), this, SLOT(openMainWindow()));
    this->mainWidget->addWidget(this->adminWindow);
    this->mainWidget->setCurrentIndex(this->mainWidget->indexOf(this->adminWindow));
}

void GUI::openUserWindow() {
    this->userWindow = new UserGUI(this->tableModel, this->service, this);
    connect(this->userWindow, SIGNAL(CloseUserWindow()), this, SLOT(openMainWindow()));

    this->mainWidget->addWidget(this->userWindow);
    this->mainWidget->setCurrentIndex(this->mainWidget->indexOf(this->userWindow));
}

void GUI::openMainWindow(){
    this->mainWidget->setCurrentIndex(this->mainWidget->indexOf(this->chooseModeWidget));
}

