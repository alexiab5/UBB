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
    void reloadShoppingCartTable();
    void resetTotalPriceShoppingCart();
    void resetTotalPriceMainUserWindow();
public:
    UserGUI(Service& _service, QWidget* parent=nullptr);
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
    QWidget* mainUserPage;
    QWidget* shoppingCartWidget;
    QVBoxLayout* shoppingCartLayout;
    QHBoxLayout* shoppingCartButtonsLayout;
    QPushButton* exportShoppingBasketButton;
    QPushButton* buyAllButton;
    QPushButton* backToBrowsingButton;
    QHBoxLayout* comboBoxLayout;
    QLabel* userModeTitle;
    QVBoxLayout* trenchCoatsLayout;
    QHBoxLayout* userButtons;
    QHBoxLayout* sizeInputLayout;
    QPushButton* closeButton;
    QPushButton* browseTrenchCoatsButton;
    QPushButton* goToCartButton;
    QComboBox *fileTypeComboBox;
    QLabel* inputSizeLabel;
    QLineEdit* sizeInput;
    QHBoxLayout* trenchCoatsStackedLayout;
    QWidget* firstPage;
    QHBoxLayout* browsingLayout;
    QPushButton* nextButton;
    QPushButton* addToCartButton;
    QLabel* currentBasketSumLabelUserWindow;
    QLabel* totalPriceLabelShopingCart;
    QTableWidget* shoppingCartTableWidget;
};