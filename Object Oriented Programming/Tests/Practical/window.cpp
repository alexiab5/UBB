//
// Created by alexia on 27.06.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window.h" resolved

#include "window.h"
#include "ui_Window.h"
#include <QMessageBox>

Window::Window(TableModel* tableModel, Service& service, Researcher researcher, QWidget *parent) :
        QWidget(parent), ui(new Ui::Window), service(service), researcher(researcher), tableModel(tableModel) {
    ui->setupUi(this);

    std::stringstream title;
    title << researcher.getName() << " - " << researcher.getPosition();
    this->setWindowTitle(QString::fromStdString(title.str()));
    this->connectButtons();
    if(researcher.getPosition() != "senior")
        ui->saveAllButton->setEnabled(false);
    this->checkEnableDevelopButton();

    this->filterProxymodel = new QSortFilterProxyModel{this};
    this->filterProxymodel->setSourceModel(tableModel);
    ui->tableView->setModel(this->filterProxymodel);


    this->filterProxymodel->sort(4, Qt::AscendingOrder);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

Window::~Window() {
    delete ui;
}

void Window::connectButtons() {
    connect(ui->addButton, &QPushButton::clicked, this, &Window::addButtonClicked);
    connect(ui->acceptButton, &QPushButton::clicked, this, &Window::acceptButtonClicked);
    connect(ui->developButton, &QPushButton::clicked, this, &Window::developButtonClicked);
    connect(ui->saveAllButton, &QPushButton::clicked, this, &Window::saveAllButtonClicked);
    connect(ui->saveDescriptionButton, &QPushButton::clicked, this, &Window::saveDescriptionButtonClicked);
}

void Window::addButtonClicked() {
    std::string title = ui->titleLineEdit->text().toStdString();
    std::string description = ui->descriptionLineEdit->text().toStdString();
    int duration = ui->dutationLineEdit->text().toInt();
    if(description.empty()){
        QMessageBox::critical(this, "Error", "Empty description!");
        return;
    }
    if(duration != 1 && duration != 2 && duration != 3){
        QMessageBox::critical(this, "Error", "Invalid duration!");
        return;
    }
    Idea i{title, description, "proposed", researcher.getName(), duration};
    this->tableModel->addIdea(i);
}

void Window::acceptButtonClicked() {
    auto selected = ui->tableView->selectionModel()->selectedIndexes();
    if (selected.empty())
        return;
    auto row = selected[0].row();
    try {
        this->tableModel->acceptIdea(row);
    }
    catch(std::invalid_argument &ex){
        QMessageBox::critical(this, "Error", ex.what());
    }
    this->checkEnableDevelopButton();
}

void Window::developButtonClicked() {
    ui->saveDescriptionButton->setEnabled(true);
    auto s = this->service.getAcceptedIdeasForResearcher(researcher);
    if(s.empty())
        return;
    ui->listWidget->clear();
    for(auto i : s){
        std::stringstream ss;
        ss << i;
        ui->listWidget->addItem(QString::fromStdString(ss.str()));
    }
}

void Window::saveAllButtonClicked() {
    this->service.saveAcceptedIdeas();
}

void Window::checkEnableDevelopButton() {
    auto s = this->service.getAcceptedIdeasForResearcher(researcher);
    if(s.empty()) {
        ui->saveDescriptionButton->setEnabled(false);
        ui->developButton->setEnabled(false);
    }
    else {
        ui->developButton->setEnabled(true);
    }
}

void Window::saveDescriptionButtonClicked() {
    this->service.saveIdeasForResearcher(researcher);
}
