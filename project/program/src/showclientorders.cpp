#include "showclientorders.h"
#include "../ui/ui_showclientorders.h"
#include <managers/OrderManager.h>
#include <exceptions/ModelException.h>
#include <QMessageBox>
#include "mainwindow.h"
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

ShowClientOrders::ShowClientOrders(MainWindow *parentWindow, OrderManagerPtr orderManager, bool showAll) :
        showAll(showAll), ui(new Ui::ShowClientOrders), parentWindow(parentWindow), orderManager(orderManager){
    ui->setupUi(this);
    if(showAll)
    {
        ui->tableWidget->setColumnCount(2);
        ui->tableWidget->setRowCount(100);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->label_2->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->pushButton->setVisible(false);
        int i = 0;
        for(auto x : orderManager->getAllClientOrders(parentWindow->getCurrentLoggedClient()))
        {
            ui->tableWidget->insertRow(i);
            QTableWidgetItem *first = new QTableWidgetItem (QString::fromStdString(boost::lexical_cast<std::string>(x->getId())));
            QTableWidgetItem *second = new QTableWidgetItem (QString::fromStdString(boost::lexical_cast<std::string>(x->getInfo())));
            ui->tableWidget->setItem(i,0, first);
            ui->tableWidget->setItem(i,1, second);
            i++;
        }
    }

    connect(ui->pushButton, &QPushButton::released, this, &ShowClientOrders::onClickButton);
    connect(ui->pushButton_2, &QPushButton::released, this, &ShowClientOrders::quitWindow);
}

void ShowClientOrders::onClickButton() {
    try
    {
        ui->tableWidget->setColumnCount(2);
        ui->tableWidget->setRowCount(100);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        std::string id = ui->lineEdit->text().toStdString();
        int i = 0;
        for(auto x : orderManager->getClientOrder(id))
        {
            ui->tableWidget->insertRow(i);
            QTableWidgetItem *first = new QTableWidgetItem (QString::fromStdString(boost::lexical_cast<std::string>(x->getId())));
            QTableWidgetItem *second = new QTableWidgetItem (QString::fromStdString(boost::lexical_cast<std::string>(x->getInfo())));
            ui->tableWidget->setItem(i,0, first);
            ui->tableWidget->setItem(i,1, second);
            i++;
        }
        ui->pushButton->setEnabled(false);
    }
    catch (ModelException &ex) {
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", ex.what());
        messageBox.setFixedSize(500,200);
    }
}

ShowClientOrders::~ShowClientOrders() {
    delete ui;
}

void ShowClientOrders::quitWindow() {
    this->close();
}

