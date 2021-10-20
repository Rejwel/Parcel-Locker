#include "admindialog.h"
#include "../ui/ui_admindialog.h"
#include <QStyle>
#include <QDesktopWidget>

AdminDialog::AdminDialog(MainWindow *parentWindow, ClientManagerPtr clientManager, ParcelLockerManagerPtr parcelLockerManager) :
        ui(new Ui::AdminDialog), parentWindow(parentWindow), clientManager(clientManager), parcelLockerManager(parcelLockerManager) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &AdminDialog::onClickButton);
}

AdminDialog::~AdminDialog() {
    delete ui;
}

void AdminDialog::onClickButton() {
    parcelLockerDialog = new ParcelLockerDialog(parentWindow, parcelLockerManager);
    parcelLockerDialog->setFixedSize(500,500);
    parcelLockerDialog->setStyleSheet("background:#262628; color:white;");
    parcelLockerDialog->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,parcelLockerDialog->size(),qApp->desktop()->availableGeometry()));
    parcelLockerDialog->show();
}
