#include <QLabel>
#include <QDesktopWidget>
#include <QStyle>
#include <QInputDialog>
#include <QDir>
#include <exceptions/ModelException.h>
#include <QMessageBox>
#include "orderdialog.h"
#include "../ui/ui_orderdialog.h"
#include "mainwindow.h"
#include <functions.h>
#include <packages/TinyPackage.h>
#include <packages/SmallPackage.h>
#include <packages/MediumPackage.h>
#include <packages/LargePackage.h>
#include <packages/HugePackage.h>
#include <exceptions/PackageException.h>
#include "mainwindow.h"
#include "model/ParcelLocker.h"

OrderDialog::OrderDialog(MainWindow *parentWindow, ParcelLockerManagerPtr parcelLockerManager, OrderManagerPtr orderManager, PackageManagerPtr packageManager) :
        ui(new Ui::OrderDialog), parentWindow(parentWindow), parcelLockerManager(parcelLockerManager), orderManager(orderManager), packageManager(packageManager) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &OrderDialog::onButtonClicked);
    connect(ui->pushButton_2, &QPushButton::released, this, &OrderDialog::onButtonClickedOpenParcelLockerDialog);
}

OrderDialog::~OrderDialog() {
    delete ui;
}

void OrderDialog::onButtonClicked() {
    try
    {
        parcelLocker = parentWindow->getCurrentSelectedParcelLocker();
        weight = ui->lineEdit->text().toDouble();
        priority = ui->lineEdit_2->text().toInt();
        fragile = ui->checkBox->isChecked();
        payment = ui->checkBox_2->isChecked();
        comment = ui->textEdit->toPlainText().toStdString();

        if(ui->comboBox->currentIndex() == 0) packageType = std::make_shared<TinyPackage>();
        else if(ui->comboBox->currentIndex() == 1) packageType = std::make_shared<SmallPackage>();
        else if(ui->comboBox->currentIndex() == 2) packageType = std::make_shared<MediumPackage>();
        else if(ui->comboBox->currentIndex() == 3) packageType = std::make_shared<LargePackage>();
        else if(ui->comboBox->currentIndex() == 4) packageType = std::make_shared<HugePackage>();

        package = packageManager->registerPackage(generateUUID(), weight, priority, fragile, payment, packageType);
        order = orderManager->makeOrder(generateUUID(), parentWindow->getCurrentLoggedClient(), package, parentWindow->getCurrentSelectedParcelLocker(), comment);
        parcelLocker->packPackage();
        parentWindow->setCurrentSelectedParcelLocker(nullptr);
        QMessageBox messageBox;
        std::string message = "Order has been approved with id\n" + boost::lexical_cast<std::string>(order->getId());
        messageBox.information(nullptr, "Done", QString::fromStdString(message));
        messageBox.setFixedSize(500,200);
        this->close();
    }
    catch (ModelException &ex) {
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", ex.what());
        messageBox.setFixedSize(500,200);
    }
    catch (PackageException &ex) {
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", ex.what());
        messageBox.setFixedSize(500,200);
    }
}

void OrderDialog::onButtonClickedOpenParcelLockerDialog() {
    showLockersDialog = new ShowLockersDialog(parentWindow, parcelLockerManager);
    showLockersDialog->setFixedSize(500,500);
    showLockersDialog->setStyleSheet("background:#262628; color:white;");
    showLockersDialog->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,showLockersDialog->size(),qApp->desktop()->availableGeometry()));
    showLockersDialog->show();
}