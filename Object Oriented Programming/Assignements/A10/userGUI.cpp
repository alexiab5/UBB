#include "userGUI.h"

UserGUI::UserGUI(QAbstractTableModel* shoppingBasketTableModel, Service& _service, QWidget *parent) : service(_service), trenchCoatsTableModel(shoppingBasketTableModel), QStackedWidget(parent) {
    this->mainUserPage = new QWidget;

    this->createComboBox();
    this->userModeTitle = new QLabel("Welcome to user mode!", this);
    this->trenchCoatsLayout = new QVBoxLayout;
    this->trenchCoatsLayout->addWidget(this->userModeTitle, 0, Qt::AlignCenter);

    this->trenchCoatsLayout->addLayout(this->comboBoxLayout);
    this->createUserButtons();
    this->createSizeInputLayout();
    this->closeButton = new QPushButton("EXIT");
    connect(this->closeButton, &QPushButton::clicked, this, &UserGUI::closeButtonClicked);
    this->createStackedWidgetLayout();
    this->createBrowsingButtons();

    this->trenchCoatsLayout->addLayout(this->userButtons);
    this->trenchCoatsLayout->addLayout(this->sizeInputLayout);
    this->trenchCoatsLayout->addLayout(this->trenchCoatsStackedLayout);
    this->trenchCoatsLayout->addLayout(this->browsingLayout);
    this->currentBasketSumLabelUserWindow = new QLabel{"Total price: 0.00", this};
    this->trenchCoatsLayout->addWidget(this->currentBasketSumLabelUserWindow, 0, Qt::AlignCenter);
    this->trenchCoatsLayout->addWidget(this->closeButton);

    this->mainUserPage->setLayout(this->trenchCoatsLayout);
    this->addWidget(mainUserPage);
    // create the shopping basket layout
    this->createShoppingCartLayout();
    this->addWidget(this->shoppingCartWidget);
    this->setCurrentIndex(0);
}

void UserGUI::closeButtonClicked() {
    emit CloseUserWindow();
}

void UserGUI::createComboBox() {
    this->comboBoxLayout = new QHBoxLayout;
    QLabel *label = new QLabel("Choose the type of file for your shopping basket", this);
    this->fileTypeComboBox = new QComboBox(this);
    this->fileTypeComboBox->addItem("CSV");
    this->fileTypeComboBox->addItem("HTML");
    connect(this->fileTypeComboBox, &QComboBox::currentIndexChanged, this, &UserGUI::changeShoppingBasketType);
    this->comboBoxLayout->addWidget(label);
    this->comboBoxLayout->addWidget(fileTypeComboBox);
}

void UserGUI::createUserButtons() {
    this->userButtons = new QHBoxLayout;
    this->browseTrenchCoatsButton = new QPushButton("Browse through available trench coats");
    connect(this->browseTrenchCoatsButton, &QPushButton::clicked, this, &UserGUI::browseButtonClicked);
    this->goToCartButton = new QPushButton("Go to shopping basket");
    connect(this->goToCartButton, &QPushButton::clicked, this, &UserGUI::goToShoppingCart);
    userButtons->addWidget(this->browseTrenchCoatsButton);
    userButtons->addWidget(this->goToCartButton);
}

void UserGUI::createSizeInputLayout() {
    this->sizeInputLayout = new QHBoxLayout;
    this->inputSizeLabel = new QLabel("Enter the size of the trench coat");
    this->sizeInput = new QLineEdit(this);
    this->sizeInputLayout->addWidget(inputSizeLabel);
    this->sizeInputLayout->addWidget(sizeInput);
}

void UserGUI::createStackedWidgetLayout() {
    this->trenchCoatsStackedLayout = new QHBoxLayout;
    this->stackedWidget = new QStackedWidget;
    this->firstPage = new QWidget;
    this->stackedWidget->addWidget(firstPage);
    this->stackedWidget->setCurrentIndex(0);
    trenchCoatsStackedLayout->addWidget(this->stackedWidget);
}

void UserGUI::createBrowsingButtons() {
    this->browsingLayout = new QHBoxLayout;
    this->nextButton = new QPushButton("Next");
    connect(this->nextButton, &QPushButton::clicked, this, &UserGUI::nextButtonClicked);
    this->addToCartButton = new QPushButton("Add to basket");
    connect(this->addToCartButton, &QPushButton::clicked, this, &UserGUI::addToCartButtonClicked);
    this->browsingLayout->addWidget(this->nextButton);
    this->browsingLayout->addWidget(this->addToCartButton);
}

void UserGUI::nextButtonClicked() {
    if(this->stackedWidget->currentIndex() + 1 >= this->stackedWidget->count()) {
        if (this->stackedWidget->count() != 0) {
            this->stackedWidget->setCurrentIndex(1);
            if(this->currentTrenchCoatsOnDisplay.size() > 0) // de revazut
                this->openTrenchCoatURL(this->currentTrenchCoatsOnDisplay[0]);
        }
    }
    else{
        this->stackedWidget->setCurrentIndex(this->stackedWidget->currentIndex() + 1);
        this->openTrenchCoatURL(this->currentTrenchCoatsOnDisplay[this->stackedWidget->currentIndex() - 1]);
    }
}

void UserGUI::addToCartButtonClicked() {
    int noOfTrenches = this->currentTrenchCoatsOnDisplay.size();
    if(noOfTrenches == 0)
        return;
    int currentOnDisplay = this->stackedWidget->currentIndex();
    if(currentOnDisplay <= 0)
        return;
    this->service.addToShoppingCartService(this->currentTrenchCoatsOnDisplay[currentOnDisplay - 1]);
    this->resetTotalPriceMainUserWindow();
    this->trenchCoatsTableModel->insertRows(this->trenchCoatsTableModel->rowCount(), 1);

    QMessageBox msg;
    msg.setText("Trench coat successfully added to shopping basket!");
    msg.exec();
}

void UserGUI::browseButtonClicked() {
    int noOfWidgets = this->stackedWidget->count();
    for (int i = noOfWidgets - 1; i > 0; i--) {
        QWidget* removedPage = this->stackedWidget->widget(i);
        this->stackedWidget->removeWidget(this->stackedWidget->widget(i));
        delete removedPage;
    }

    int size;
    this->currentTrenchCoatsOnDisplay.clear();
    try{
        QString sizeString = this->sizeInput->text();
        if(sizeString.isEmpty())
            this->currentTrenchCoatsOnDisplay = this->service.getAllTrenchCoatsService();
        else {
            size = sizeString.toInt();
            this->currentTrenchCoatsOnDisplay = this->service.getTrenchCoatsBySizeService(size);
        }
    }
    catch(std::exception &ex){
        QMessageBox msgBox;
        msgBox.setText("Sizes are between 32 and 54!");
        msgBox.exec();
        return;
    }

    int numberOfTrenches = this->currentTrenchCoatsOnDisplay.size();
    for (int i = 0; i < numberOfTrenches; i++) {
        QWidget* newPage = new QWidget;
        QVBoxLayout* pageLayout = new QVBoxLayout;
        QTableWidget* trenchView = new QTableWidget;

        trenchView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        QStringList header = {"Colour", "Size", "Price", "Quantity", "Photograph"};
        trenchView->setColumnCount(5);
        trenchView->setColumnWidth(4, 300);
        trenchView->setHorizontalHeaderLabels(header);
        int rowCount = trenchView->rowCount();
        trenchView->insertRow(rowCount);
        trenchView->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(this->currentTrenchCoatsOnDisplay[i].getColour())));
        trenchView->setItem(rowCount, 1, new QTableWidgetItem(QString::number(this->currentTrenchCoatsOnDisplay[i].getSize())));
        trenchView->setItem(rowCount, 2, new QTableWidgetItem(QString::number(this->currentTrenchCoatsOnDisplay[i].getPrice())));
        trenchView->setItem(rowCount, 3, new QTableWidgetItem(QString::number(this->currentTrenchCoatsOnDisplay[i].getQuantity())));
        trenchView->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(this->currentTrenchCoatsOnDisplay[i].getPhotograph())));

        trenchView->resizeColumnToContents(4);
        pageLayout->addWidget(trenchView);
        newPage->setLayout(pageLayout);
        this->stackedWidget->insertWidget(i + 1, newPage);
    }
    if (numberOfTrenches == 0) {
        QMessageBox msgBox;
        msgBox.setText("There are no trench coats available with that size!");
        msgBox.exec();
    }
    else {
        this->stackedWidget->setCurrentIndex(1);
        this->openTrenchCoatURL(this->currentTrenchCoatsOnDisplay[0]);
    }
}

void UserGUI::goToShoppingCart() {
//    this->reloadShoppingCartTable();
    this->resetTotalPriceShoppingCart();
    this->setCurrentIndex(1);
}

void UserGUI::openTrenchCoatURL(TrenchCoat &trench) {
    QString link = QString::fromStdString(trench.getPhotograph());
    QDesktopServices::openUrl(QUrl(link));
}

void UserGUI::changeShoppingBasketType() {
    int index = this->fileTypeComboBox->currentIndex();
    if(index == 0){
        this->service.setShoppingBasketType("csv");
        QMessageBox msgBox;
        msgBox.setText("Shopping basket type is now csv!");
        msgBox.exec();
    }
    else if(index == 1){
        this->service.setShoppingBasketType("html");
        QMessageBox msgBox;
        msgBox.setText("Shopping basket type is now html!");
        msgBox.exec();
    }
    this->resetTotalPriceMainUserWindow();
}

void UserGUI::createShoppingCartLayout() {
    this->shoppingCartWidget = new QWidget;
    this->shoppingCartLayout = new QVBoxLayout;
//    this->shoppingCartTableWidget = new QTableWidget;
//
//    this->shoppingCartTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    QStringList header = {"Colour", "Size", "Price", "Quantity", "Photograph"};
//    this->shoppingCartTableWidget->setColumnCount(5);
//    this->shoppingCartTableWidget->setColumnWidth(4, 300);
//    this->shoppingCartTableWidget->setHorizontalHeaderLabels(header);
//    std::vector<TrenchCoat> trenches = this->service.getShoppingCartService();
//    for(const auto& trench : trenches) {
//        int rowCount = this->shoppingCartTableWidget->rowCount();
//        this->shoppingCartTableWidget->insertRow(rowCount);
//        this->shoppingCartTableWidget->setItem(rowCount, 0, new QTableWidgetItem(
//                QString::fromStdString(trench.getColour())));
//        this->shoppingCartTableWidget->setItem(rowCount, 1,
//                            new QTableWidgetItem(QString::number(trench.getSize())));
//        this->shoppingCartTableWidget->setItem(rowCount, 2,
//                            new QTableWidgetItem(QString::number(trench.getPrice())));
//        this->shoppingCartTableWidget->setItem(rowCount, 3,
//                            new QTableWidgetItem(QString::number(trench.getQuantity())));
//        this->shoppingCartTableWidget->setItem(rowCount, 4, new QTableWidgetItem(
//                QString::fromStdString(trench.getPhotograph())));
//    }
//    this->shoppingCartTableWidget->resizeColumnToContents(4);;
//    this->shoppingCartLayout->addWidget(this->shoppingCartTableWidget);
    this->trenchCoatsTableView = new QTableView;
//    TrenchCoat t{"blabla", "http://www.google.com", 38, 3, 3};
//    this->service.addToShoppingCartService(t);
    this->trenchCoatsTableView->setModel(this->trenchCoatsTableModel);
    this->shoppingCartLayout->addWidget(this->trenchCoatsTableView);
    this->totalPriceLabelShopingCart = new QLabel;
    this->resetTotalPriceShoppingCart();
    this->shoppingCartLayout->addWidget(this->totalPriceLabelShopingCart);

    this->shoppingCartButtonsLayout = new QHBoxLayout;
    this->exportShoppingBasketButton= new QPushButton{"Export shopping basket"};
    connect(this->exportShoppingBasketButton, &QPushButton::clicked, this, &UserGUI::exportShoppingBasketButtonCLicked);

    this->buyAllButton = new QPushButton{"Buy all trench coats"};
    connect(this->buyAllButton, &QPushButton::clicked, this, &UserGUI::buyAllButtonClicked);

    this->shoppingCartButtonsLayout->addWidget(this->exportShoppingBasketButton);
    this->shoppingCartButtonsLayout->addWidget(this->buyAllButton);
    this->shoppingCartLayout->addLayout(this->shoppingCartButtonsLayout);
    this->shoppingCartWidget->setLayout(this->shoppingCartLayout);
    this->backToBrowsingButton = new QPushButton{"Back to browsing"};
    connect(this->backToBrowsingButton, &QPushButton::clicked, this, &UserGUI::backToBrowsingButtonClicked);
    this->shoppingCartLayout->addWidget(this->backToBrowsingButton);
}

void UserGUI::exportShoppingBasketButtonCLicked() {
    try{
        std::string fileName = this->service.getShoppingBasketFile();
        QString URL = QString::fromStdString(fileName);
        QDesktopServices::openUrl(QUrl(URL));
    }
    catch(std::exception &ex){
        QMessageBox msgBox;
        msgBox.setText("The shopping basket file could not be opened with its default application!");
        msgBox.exec();
    }
}

void UserGUI::buyAllButtonClicked() {
    int noOfItems = this->service.getNumberOfItemsInShoppingCartService();
    if(noOfItems == 0){
        QMessageBox msgBox;
        msgBox.setText("Your shopping basket is currently empty!");
        msgBox.exec();
        return;
    }
    this->trenchCoatsTableModel->removeRows(0,this->service.getNumberOfItemsInShoppingCartService());
//    this->service.buyAllService();
//    this->reloadShoppingCartTable();
    this->resetTotalPriceShoppingCart();
    QMessageBox msgBox;
    msgBox.setText("Thank you for your purchase!");
    msgBox.exec();
}

void UserGUI::backToBrowsingButtonClicked() {
    this->resetTotalPriceMainUserWindow();
    this->setCurrentIndex(0);
}

//void UserGUI::reloadShoppingCartTable() {
//    this->shoppingCartTableWidget->setRowCount(0);
//    std::vector<TrenchCoat> trenchCoats = this->service.getShoppingCartService();
//    for (const auto& trench : trenchCoats)
//    {
//        int rowCount = this->shoppingCartTableWidget->rowCount();
//        this->shoppingCartTableWidget->insertRow(rowCount);
//        this->shoppingCartTableWidget->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(trench.getColour())));
//        this->shoppingCartTableWidget->setItem(rowCount, 1, new QTableWidgetItem(QString::number(trench.getSize())));
//        this->shoppingCartTableWidget->setItem(rowCount, 2, new QTableWidgetItem(QString::number(trench.getPrice())));
//        this->shoppingCartTableWidget->setItem(rowCount, 3, new QTableWidgetItem(QString::number(trench.getQuantity())));
//        this->shoppingCartTableWidget->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(trench.getPhotograph())));
//    }
//    this->shoppingCartTableWidget->resizeColumnToContents(4);;
//}

void UserGUI::resetTotalPriceShoppingCart() {
    float currentSum = this->service.getTotalShoppingCartService();
    std::string sum ="Total price: " + std::to_string(currentSum);
    this->totalPriceLabelShopingCart->setText(QString::fromStdString(sum));
}

void UserGUI::resetTotalPriceMainUserWindow() {
    float currentSum = this->service.getTotalShoppingCartService();
    std::string sum ="Total price: " + std::to_string(currentSum);
    this->currentBasketSumLabelUserWindow->setText(QString::fromStdString(sum));
}
