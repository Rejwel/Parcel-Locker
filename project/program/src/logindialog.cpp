// You may need to build the project (run Qt uic code generator) to get "ui_LoginDialog.h" resolved

#include <predicates/PredicateByLogin.h>
#include <QMessageBox>
#include <mainwindow.h>
#include "logindialog.h"
#include "../ui/ui_logindialog.h"
#include "../../library/include/exceptions/ModelException.h"
#include "../../library/include/managers/ClientManager.h"
#include "../../library/include/model/Client.h"

LoginDialog::LoginDialog(MainWindow *parentWindow, ClientManagerPtr clientManager) :
         ui(new Ui::LoginDialog), parentWindow(parentWindow), clientManager(clientManager){
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &LoginDialog::onButtonClicked);
}

LoginDialog::~LoginDialog() {
    delete ui;
}

void LoginDialog::onButtonClicked() {
    try
    {
        login = ui->lineEdit->text().toStdString();
        PredicateByLogin functor(login);
        password = ui->lineEdit_2->text().toStdString();

        if(clientManager->findClients(functor).size() == 0) throw ModelException("There is no client with this login");
        if(clientManager->findClients(functor).size() == 1 && clientManager->findClients(functor)[0]->getPassword() != password) throw ModelException("Wrong password");
        client =  clientManager->findClients(functor)[0];
        parentWindow->setCurrentLoggedClient();
        parentWindow->setCurrentLoggedClientInfo();
    }
    catch (ModelException &ex) {
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", ex.what());
        messageBox.setFixedSize(500,200);
    }
    this->close();
}

const ClientPtr &LoginDialog::getClient() const {
    return client;
}
