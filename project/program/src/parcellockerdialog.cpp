// You may need to build the project (run Qt uic code generator) to get "ui_ParcelLockerDialog.h" resolved

#include <QMessageBox>
#include <exceptions/ModelException.h>
#include "parcellockerdialog.h"
#include "../ui/ui_parcellockerdialog.h"
#include "../../library/include/managers/ParcelLockerManager.h"
#include <model/Address.h>

ParcelLockerDialog::ParcelLockerDialog(MainWindow *parentWindow, ParcelLockerManagerPtr parcelLockerManager) :
        ui(new Ui::ParcelLockerDialog), parentWindow(parentWindow), parcelLockerManager(parcelLockerManager){
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &ParcelLockerDialog::onClickButton);
}

ParcelLockerDialog::~ParcelLockerDialog() {
    delete ui;
}

void ParcelLockerDialog::onClickButton() {
    try
    {
        city = ui->lineEdit->text().toStdString();
        street = ui->lineEdit_2->text().toStdString();
        number = ui->lineEdit_3->text().toStdString();
        id = ui->lineEdit_4->text().toStdString();
        freePlaces = ui->lineEdit_5->text().toInt();
        address = parcelLockerManager->createNewAddress(city,street,number);
        parcelLockerManager->registerParcelLocker(id,freePlaces, address);
        this->close();
    }
    catch (ModelException &ex) {
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", ex.what());
        messageBox.setFixedSize(500,200);
    }
}
