// You may need to build the project (run Qt uic code generator) to get "ui_CheckOrders.h" resolved

#include "checkorders.h"
#include <QDesktopWidget>
#include <QStyle>
#include "../ui/ui_checkorders.h"

CheckOrders::CheckOrders(MainWindow *parentWindow, OrderManagerPtr orderManager) :
        ui(new Ui::CheckOrders), parentWindow(parentWindow), orderManager(orderManager) {
    ui->setupUi(this);
    connect(ui->pushButton_3, &QPushButton::released, this, &CheckOrders::quitWindow);
    connect(ui->pushButton, &QPushButton::released, this, &CheckOrders::showSingleButton);
    connect(ui->pushButton_2, &QPushButton::released, this, &CheckOrders::showAllButton);
}

CheckOrders::~CheckOrders() {
    delete ui;
}

void CheckOrders::quitWindow() {
    this->close();
}

void CheckOrders::showSingleButton() {
    showClientOrdersDialog = new ShowClientOrders(parentWindow, orderManager, false);
    showClientOrdersDialog->setFixedSize(1500,500);
    showClientOrdersDialog->setStyleSheet("background:#262628; color:white;");
    showClientOrdersDialog->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,showClientOrdersDialog->size(),qApp->desktop()->availableGeometry()));
    showClientOrdersDialog->show();
}

void CheckOrders::showAllButton() {
    showClientOrdersDialog = new ShowClientOrders(parentWindow, orderManager, true);
    showClientOrdersDialog->setFixedSize(1500,500);
    showClientOrdersDialog->setStyleSheet("background:#262628; color:white;");
    showClientOrdersDialog->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,showClientOrdersDialog->size(),qApp->desktop()->availableGeometry()));
    showClientOrdersDialog->show();
}
