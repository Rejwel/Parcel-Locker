// You may need to build the project (run Qt uic code generator) to get "ui_RegisterDialog.h" resolved

#include <mainwindow.h>
#include <QMessageBox>
#include "registerdialog.h"
#include "../ui/ui_registerdialog.h"
#include "../../library/include/clientTypes/Default.h"
#include "../../library/include/exceptions/ModelException.h"

RegisterDialog::RegisterDialog(QWidget *parent, ClientManagerPtr clientManager) :
        QDialog(parent), ui(new Ui::RegisterDialog), clientManager(clientManager) {
    clientType = std::make_shared<Default>();
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &RegisterDialog::onButtonClicked);
}

RegisterDialog::~RegisterDialog() {
    delete ui;
}

void RegisterDialog::onButtonClicked() {
    try
    {
        login = ui->lineEdit->text().toStdString();
        password = ui->lineEdit_2->text().toStdString();
        firstName = ui->lineEdit_8->text().toStdString();
        lastName = ui->lineEdit_9->text().toStdString();
        personalId = ui->lineEdit_10->text().toStdString();
        clientManager->registerClient(login, password, firstName, lastName, personalId, clientType);
    }
    catch (ModelException &ex) {
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", ex.what());
        messageBox.setFixedSize(500,200);
    }
    this->close();
}
