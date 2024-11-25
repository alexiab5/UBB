#pragma once
#ifndef OOP_A8_9_ALEXIAB5_USERGUI_H
#define OOP_A8_9_ALEXIAB5_USERGUI_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QStackedWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QDesktopServices>
#include "service.h"
#include "trenchCoatsTableModel.h"
#include <QAbstractTableModel>
#include <QTableView>
#endif //OOP_A8_9_ALEXIAB5_USERGUI_H

class UserGUI : public QStackedWidget{
    Q_OBJECT
private:
    Service& service;
    std::vector<TrenchCoat> currentTrenchCoatsOnDisplay;
    void createComboBox();
    void createUserButtons();
    void createSizeInputLayout();
    void createStackedWidgetLayout();
    void createBrowsingButtons();
    void createShoppingCartLayout();
    void openTrenchCoatURL(TrenchCoat &trench);
//    void reloadShoppingCartTable();
    void resetTotalPriceShoppingCart();
    void resetTotalPriceMainUserWindow();
public:
    UserGUI(QAbstractTableModel* shoppingBasketTableModel, Service& _service, QWidget* parent=nullptr);
    ~UserGUI(){};
    QStackedWidget* stackedWidget;
public slots:
    void closeButtonClicked();
    void nextButtonClicked();
    void addToCartButtonClicked();
    void browseButtonClicked();
    void goToShoppingCart();
    void changeShoppingBasketType();
    void exportShoppingBasketButtonCLicked();
    void buyAllButtonClicked();
    void backToBrowsingButtonClicked();
signals:
    void CloseUserWindow();
private:
    QTableView* trenchCoatsTableView = nullptr;
    QAbstractTableModel* trenchCoatsTableModel= nullptr;
    QWidget* mainUserPage= nullptr;
    QWidget* shoppingCartWidget= nullptr;
    QVBoxLayout* shoppingCartLayout= nullptr;
    QHBoxLayout* shoppingCartButtonsLayout= nullptr;
    QPushButton* exportShoppingBasketButton= nullptr;
    QPushButton* buyAllButton= nullptr;
    QPushButton* backToBrowsingButton= nullptr;
    QHBoxLayout* comboBoxLayout= nullptr;
    QLabel* userModeTitle= nullptr;
    QVBoxLayout* trenchCoatsLayout= nullptr;
    QHBoxLayout* userButtons= nullptr;
    QHBoxLayout* sizeInputLayout= nullptr;
    QPushButton* closeButton= nullptr;
    QPushButton* browseTrenchCoatsButton= nullptr;
    QPushButton* goToCartButton= nullptr;
    QComboBox *fileTypeComboBox= nullptr;
    QLabel* inputSizeLabel= nullptr;
    QLineEdit* sizeInput= nullptr;
    QHBoxLayout* trenchCoatsStackedLayout= nullptr;
    QWidget* firstPage= nullptr;
    QHBoxLayout* browsingLayout= nullptr;
    QPushButton* nextButton= nullptr;
    QPushButton* addToCartButton= nullptr;
    QLabel* currentBasketSumLabelUserWindow= nullptr;
    QLabel* totalPriceLabelShopingCart= nullptr;
    QTableWidget* shoppingCartTableWidget= nullptr;
};