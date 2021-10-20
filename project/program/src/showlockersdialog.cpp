// You may need to build the project (run Qt uic code generator) to get "ui_ShowLockersDialog.h" resolved

#include "showlockersdialog.h"
#include "../ui/ui_showlockersdialog.h"
#include "../../library/include/managers/ParcelLockerManager.h"
#include "../../library/include/model/ParcelLocker.h"
#include "mainwindow.h"

ShowLockersDialog::ShowLockersDialog(MainWindow *parentWindow, ParcelLockerManagerPtr parcelLockerManager) :
        ui(new Ui::ShowLockersDialog), parentWindow(parentWindow), parcelLockerManager(parcelLockerManager) {
    ui->setupUi(this);

    int height = 125;
    int i = 0;
    parcelLockers = parcelLockerManager->findAllParcelLockers();

    for (auto x : parcelLockerManager->findAllParcelLockers()) {
        std::string temp;
        temp = x->getInfo();
        QPushButton *buttonParcelLocker = new QPushButton("Click", this);
        QLabel *label = new QLabel(QString::fromStdString(temp), this);
        label->move(150, height);
        buttonParcelLocker->move(50, height);
        buttonParcelLocker->show();
        label->show();
        connect(buttonParcelLocker, &QPushButton::released, this,
                [=]() -> void { parentWindow->setCurrentSelectedParcelLocker(parcelLockers[i]); this->close(); });
        height += 50;
        i++;
    }

    connect(ui->pushButton, &QPushButton::released, this, &ShowLockersDialog::closeWindow);

}

ShowLockersDialog::~ShowLockersDialog() {
    delete ui;
}

void ShowLockersDialog::closeWindow() {
    this->close();
}
