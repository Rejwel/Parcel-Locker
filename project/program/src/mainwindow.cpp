#include <QPushButton>
#include <QStyle>
#include <QScreen>
#include <QLabel>
#include <QPainter>
#include <QInputDialog>
#include <QDir>
#include <string>
#include <QResource>
#include <QMessageBox>
#include "mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include <model/Client.h>
#include "managers/SaveFilesManager.h"

MainWindow::MainWindow(MainWindow *parentWindow) :
         ui(new Ui::MainWindow), parentWindow(parentWindow) {
    int height = 125;

    clientManager = std::make_shared<ClientManager>();
    parcelLockerManager = std::make_shared<ParcelLockerManager>();
    orderManager = std::make_shared<OrderManager>();
    packageManager = std::make_shared<PackageManager>();

    // setting up width and height, centering window
    ui->setupUi(this);

    this->setFixedSize(500,500);

    // setting up bg image for application
    // you need to specify full path to work
    std::string stringPathToBackground = QCoreApplication::applicationDirPath().toStdString() + "/../../program/images/background.png";
    QString PathToBackground = QString::fromStdString(stringPathToBackground);
    QPixmap bkgnd(PathToBackground);
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatioByExpanding);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);


    // button for login
    buttonLogin = new QPushButton("&Login", this);
    buttonLogin->move(10,10);
    buttonLogin->show();
    connect(buttonLogin, &QPushButton::released, this, &MainWindow::handleButtonLogin);

    // button for register
    buttonRegister = new QPushButton("&Register", this);
    buttonRegister->move(10,40);
    buttonRegister->show();
    connect(buttonRegister, &QPushButton::released, this, &MainWindow::handleButtonRegister);

    // button for logout
    buttonLogout = new QPushButton("&Logout", this);
    buttonLogout->move(10,70);
    buttonLogout->setVisible(false);
    connect(buttonLogout, &QPushButton::released, this, &MainWindow::logout);

    // button for admin panel
    buttonAdmin = new QPushButton("&Admin Panel", this);
    buttonAdmin->move(400,10);
    buttonAdmin->show();
    connect(buttonAdmin, &QPushButton::released, this, &MainWindow::handleButtonAdminPanel);

    // button for order
    buttonOrder = new QPushButton("&Make order", this);
    buttonOrder->setEnabled(false);
    buttonOrder->setMinimumWidth(200);
    buttonOrder->move(150,height);
    buttonOrder->show();
    connect(buttonOrder, &QPushButton::released, this, &MainWindow::handleButtonOrder);

    // button for check order
    buttonCheckOrder = new QPushButton("&Check order", this);
    buttonCheckOrder->setEnabled(false);
    buttonCheckOrder->setMinimumWidth(200);
    buttonCheckOrder->move(150,height+50);
    buttonCheckOrder->show();
    connect(buttonCheckOrder, &QPushButton::released, this, &MainWindow::handleButtonCheckOrder);

    // button for cancel order
    buttonCancelOrder = new QPushButton("&Cancel order", this);
    buttonCancelOrder->setEnabled(false);
    buttonCancelOrder->setMinimumWidth(200);
    buttonCancelOrder->move(150,height+100);
    buttonCancelOrder->show();
//    connect(buttonCancelOrder, &QPushButton::released, this, &MainWindow::handleButtonOrder);

    // button for change parcel locker
    buttonChangeLocker = new QPushButton("&Change locker", this);
    buttonChangeLocker->setEnabled(false);
    buttonChangeLocker->setMinimumWidth(200);
    buttonChangeLocker->move(150,height+150);
    buttonChangeLocker->show();
//    connect(buttonChangeLocker, &QPushButton::released, this, &MainWindow::handleButtonOrder);


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handleButtonOrder() {
    orderDialog = new OrderDialog(this, parcelLockerManager, orderManager, packageManager);
    orderDialog->setFixedSize(500,500);
    orderDialog->setStyleSheet("background:#262628; color:white;");
    orderDialog->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,orderDialog->size(),normalGeometry()));
    orderDialog->show();
}

void MainWindow::handleButtonRegister() {
    registerDialog = new RegisterDialog(this, clientManager);
    registerDialog->setFixedSize(500,500);
    registerDialog->setStyleSheet("background:#262628; color:white;");
    registerDialog->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,registerDialog->size(),normalGeometry()));
    registerDialog->show();
}

void MainWindow::handleButtonLogin() {
    loginDialog = new LoginDialog(this, clientManager);
    loginDialog->setFixedSize(500,500);
    loginDialog->setStyleSheet("background:#262628; color:white;");
    loginDialog->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,loginDialog->size(),normalGeometry()));
    loginDialog->show();
}

void MainWindow::handleButtonAdminPanel() {
    adminDialog = new AdminDialog(this, clientManager, parcelLockerManager);
    adminDialog->setFixedSize(500,500);
    adminDialog->setStyleSheet("background:#262628; color:white;");
    adminDialog->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,adminDialog->size(),normalGeometry()));
    adminDialog->show();
}

void MainWindow::handleButtonCheckOrder() {
    checkOrderDialog = new CheckOrders(this, orderManager);
    checkOrderDialog->setFixedSize(500,500);
    checkOrderDialog->setStyleSheet("background:#262628; color:white;");
    checkOrderDialog->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,checkOrderDialog->size(),normalGeometry()));
    checkOrderDialog->show();
}

void MainWindow::setCurrentLoggedClient() {
    MainWindow::currentLoggedClient = loginDialog->getClient();
}

void MainWindow::setCurrentLoggedClientInfo() {
    ui->label->setText(QString::fromStdString("Logged as : " + currentLoggedClient->getLogin()));
    ui->label->setStyleSheet("color:white;");
    buttonLogin->setEnabled(false);
    buttonRegister->setEnabled(false);
    buttonLogout->setVisible(true);
    buttonOrder->setEnabled(true);
    buttonCheckOrder->setEnabled(true);
    buttonCancelOrder->setEnabled(true);
    buttonChangeLocker->setEnabled(true);
}

void MainWindow::logout() {
    currentLoggedClient = nullptr;
    ui->label->setText(QString::fromStdString(""));
    buttonLogin->setEnabled(true);
    buttonRegister->setEnabled(true);
    buttonOrder->setEnabled(false);
    buttonCheckOrder->setEnabled(false);
    buttonCancelOrder->setEnabled(false);
    buttonChangeLocker->setEnabled(false);
    buttonLogout->setVisible(false);
}

void MainWindow::setCurrentSelectedParcelLocker(const ParcelLockerPtr &c) {
    MainWindow::currentSelectedParcelLocker = c;
}

const ParcelLockerPtr &MainWindow::getCurrentSelectedParcelLocker() const {
    return currentSelectedParcelLocker;
}

const ClientPtr &MainWindow::getCurrentLoggedClient() const {
    return currentLoggedClient;
}

void MainWindow::saveFiles() {
    saveFilesManager = std::make_shared<SaveFilesManager>(clientManager, packageManager, orderManager, parcelLockerManager);
    saveFilesManager->save();
}

void MainWindow::loadFiles() {
    saveFilesManager = std::make_shared<SaveFilesManager>(clientManager, packageManager, orderManager, parcelLockerManager);
    saveFilesManager->load();
}





