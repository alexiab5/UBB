//
// Created by alexia on 10.05.2024.
//
#include "adminGUI.h"

AdminGUI::AdminGUI(Service& _service, QWidget *parent) : QWidget(parent), service(_service){

    this->mainAdminLayout = new QVBoxLayout;
    this->trenchCoatInfoLayout = new QHBoxLayout;
    this->trenchCoatInfo = new QVBoxLayout;

//    this->setFixedSize(1200, 270);

    this->adminTitle = new QLabel("Welcome to Admin Mode!", this);
    this->mainAdminLayout->addWidget(this->adminTitle, 0, Qt::AlignHCenter);

    this->createColourLayout();
    this->createSizeLayout();
    this->createPriceLayout();
    this->createQuantityLayout();
    this->createPhotographLayout();
    this->createAdminButtons();

    this->trenchCoatInfoLayout->setAlignment(Qt::AlignVCenter);
    this->trenchCoatInfo->addLayout(this->colourLayout);
    this->trenchCoatInfo->addLayout(this->sizeLayout);
    this->trenchCoatInfo->addLayout(this->priceLayout);
    this->trenchCoatInfo->addLayout(this->quantityLayout);
    this->trenchCoatInfo->addLayout(this->photographLayout);
    this->trenchCoatInfo->addLayout(this->buttonsLayout);
    this->trenchCoatInfo->addStretch();

    this->trenchCoatInfoLayout->addLayout(this->trenchCoatInfo);

    this->createTableWidget();
    this->trenchCoatInfoLayout->addWidget(this->trenchCoatsTable);

    this->mainAdminLayout->addLayout(this->trenchCoatInfoLayout);
    this->closeButton = new QPushButton("EXIT");
    connect(this->closeButton, &QPushButton::clicked, this, &AdminGUI::closeButtonClicked);
    this->mainAdminLayout->addWidget(this->closeButton);
    //mainAdminLayout->setAlignment(Qt::AlignVCenter);
    this->setLayout(this->mainAdminLayout);
}

void AdminGUI::closeButtonClicked() {
    emit CloseAdminWindow();
}

void AdminGUI::createAdminButtons() {
    this->buttonsLayout = new QHBoxLayout;
    this->addButton = new QPushButton("ADD", this);
    this->deleteButton = new QPushButton("DELETE", this);
    this->updateButton = new QPushButton("UPDATE", this);
    connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::addButtonClicked);
    connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteButtonClicked);
    connect(this->updateButton, &QPushButton::clicked, this, &AdminGUI::updateButtonClicked);
    this->buttonsLayout->addWidget(this->addButton);
    this->buttonsLayout->addWidget(this->deleteButton);
    this->buttonsLayout->addWidget(this->updateButton);
}

void AdminGUI::createColourLayout() {
    this->colourLayout = new QHBoxLayout;
    this->colourLabel = new QLabel("Colour of the trench coat:");
    this->colourInput = new QLineEdit(this);
    this->colourLayout->addWidget(this->colourLabel);
    this->colourLayout->addWidget(this->colourInput);
}

void AdminGUI::createSizeLayout() {
    this->sizeLayout = new QHBoxLayout;
    this->sizeLabel = new QLabel("Size of the trench coat:");
    this->sizeInput = new QLineEdit(this);
    this->sizeLayout->addWidget(this->sizeLabel);
    this->sizeLayout->addWidget(this->sizeInput);
}

void AdminGUI::createPriceLayout() {
    this->priceLayout = new QHBoxLayout;
    this->priceLabel = new QLabel("Price of the trench coat:");
    this->priceInput = new QLineEdit(this);
    this->priceLayout->addWidget(this->priceLabel);
    this->priceLayout->addWidget(this->priceInput);
}

void AdminGUI::createQuantityLayout() {
    this->quantityLayout = new QHBoxLayout;
    this->quantityLabel = new QLabel("Quantity of the trench coat:");
    this->quantityInput = new QLineEdit(this);
    this->quantityLayout->addWidget(this->quantityLabel);
    this->quantityLayout->addWidget(this->quantityInput);
}

void AdminGUI::createPhotographLayout() {
    this->photographLayout = new QHBoxLayout;
    this->photographLabel = new QLabel("Photograph of the trench coat:");
    this->photographInput = new QLineEdit(this);
    this->photographLayout->addWidget(this->photographLabel);
    this->photographLayout->addWidget(this->photographInput);
}

void AdminGUI::createTableWidget() {
    this->trenchCoatsTable = new QTableWidget;
    QStringList header = {"Colour", "Size", "Price", "Quantity", "Photograph"};
    this->trenchCoatsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->trenchCoatsTable->setColumnCount(5);
    this->trenchCoatsTable->setColumnWidth(0, 80);
    this->trenchCoatsTable->setColumnWidth(1, 60);
    this->trenchCoatsTable->setColumnWidth(2, 60);
    this->trenchCoatsTable->setColumnWidth(3, 60);
    this->trenchCoatsTable->setColumnWidth(4, 300);
    this->trenchCoatsTable->setHorizontalHeaderLabels(header);

    std::vector<TrenchCoat> trenchCoats = this->service.getAllTrenchCoatsService();
    for (auto trench : trenchCoats)
    {
        int rowCount = this->trenchCoatsTable->rowCount();
        this->trenchCoatsTable->insertRow(rowCount);
        this->trenchCoatsTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(trench.getColour())));
        this->trenchCoatsTable->setItem(rowCount, 1, new QTableWidgetItem(QString::number(trench.getSize())));
        this->trenchCoatsTable->setItem(rowCount, 2, new QTableWidgetItem(QString::number(trench.getPrice())));
        this->trenchCoatsTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(trench.getQuantity())));
        this->trenchCoatsTable->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(trench.getPhotograph())));
    }
    trenchCoatsTable->resizeColumnToContents(4);
}

void AdminGUI::addButtonClicked() {
    TrenchCoat trench;
    try{
        trench = this->extractTrenchCoatInfo();
    }
    catch(ValidationException &ex){
        QMessageBox errorMessageBox;
        errorMessageBox.setText(ex.what());
        errorMessageBox.exec();
        return;
    }
    try{
        this->service.addTrenchCoatService(trench);
    }
    catch(RepositoryException &ex){
        QMessageBox errorMessageBox;
        errorMessageBox.setText(ex.what());
        errorMessageBox.exec();
        return;
    }
    this->reloadTrenchCoatsTable();
    QMessageBox errorMessageBox;
    errorMessageBox.setText("Trench coat successfully added!");
    errorMessageBox.exec();
}

void AdminGUI::deleteButtonClicked() {
    TrenchCoat trench;
    try{
        trench = this->extractTrenchCoatInfo();
    }
    catch(ValidationException &ex){
        QMessageBox errorMessageBox;
        errorMessageBox.setText(ex.what());
        errorMessageBox.exec();
        return;
    }
    try{
        this->service.removeTrenchCoatService(trench);
    }
    catch(RepositoryException &ex){
        QMessageBox errorMessageBox;
        errorMessageBox.setText(ex.what());
        errorMessageBox.exec();
        return;
    }
    this->reloadTrenchCoatsTable();
    QMessageBox errorMessageBox;
    errorMessageBox.setText("Trench coat successfully deleted!");
    errorMessageBox.exec();
}

void AdminGUI::updateButtonClicked() {
    TrenchCoat trench;
    try{
        trench = this->extractTrenchCoatInfo();
    }
    catch(ValidationException &ex){
        QMessageBox errorMessageBox;
        errorMessageBox.setText(ex.what());
        errorMessageBox.exec();
        return;
    }
    try{
        this->service.updateUniqueTrenchCoatService(trench);
    }
    catch(RepositoryException &ex){
        QMessageBox errorMessageBox;
        errorMessageBox.setText(ex.what());
        errorMessageBox.exec();
        return;
    }
    this->reloadTrenchCoatsTable();
    int index = this->service.searchForUniqueTrenchCoat(trench);
    this->selectRowTrenchCoatsTable(index);
    QMessageBox errorMessageBox;
    errorMessageBox.setText("Trench coat successfully updated!");
    errorMessageBox.exec();
}

TrenchCoat AdminGUI::extractTrenchCoatInfo() {
    QString colour = this->colourInput->text();
    QString photograph = this->photographInput->text();
    QString priceString = this->priceInput->text();
    QString quantityString = this->quantityInput->text();
    QString sizeString = this->sizeInput->text();

    float price;
    int quantity;
    int size;
    try{
        price = priceString.toFloat();
        quantity = quantityString.toInt();
        size = sizeString.toInt();
    }
    catch(std::exception &ex){
        throw ValidationException((std::string &) "Invalid number field!");
    }
    TrenchCoat trench{colour.toStdString(), photograph.toStdString(), size, quantity, price};
    TrenchCoatValidator::validateTrenchCoat(trench);
    return trench;
}

void AdminGUI::reloadTrenchCoatsTable() {
    this->trenchCoatsTable->setRowCount(0);
    std::vector<TrenchCoat> trenchCoats = this->service.getAllTrenchCoatsService();
    for (auto trench : trenchCoats)
    {
        int rowCount = this->trenchCoatsTable->rowCount();
        this->trenchCoatsTable->insertRow(rowCount);
        this->trenchCoatsTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(trench.getColour())));
        this->trenchCoatsTable->setItem(rowCount, 1, new QTableWidgetItem(QString::number(trench.getSize())));
        this->trenchCoatsTable->setItem(rowCount, 2, new QTableWidgetItem(QString::number(trench.getPrice())));
        this->trenchCoatsTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(trench.getQuantity())));
        this->trenchCoatsTable->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(trench.getPhotograph())));
    }
}

void AdminGUI::selectRowTrenchCoatsTable(int index) {
    if(index < 0 || index > this->trenchCoatsTable->rowCount())
        return;
    this->trenchCoatsTable->selectRow(index);
}

