#ifndef PARCELLOCKERPROJECT_MAINWINDOW_H
#define PARCELLOCKERPROJECT_MAINWINDOW_H

#include <QWidget>
#include "orderdialog.h"
#include "registerdialog.h"
#include "../../library/include/managers/ClientManager.h"
#include "../../library/include/managers/ParcelLockerManager.h"
#include "../../library/include/managers/OrderManager.h"
#include "../../library/include/managers/PackageManager.h"
#include "logindialog.h"
#include "admindialog.h"
#include "checkorders.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(MainWindow *parentWindow = nullptr);
    ~MainWindow() override;
    void setCurrentLoggedClient();
    void setCurrentLoggedClientInfo();
    void setCurrentSelectedParcelLocker(const ParcelLockerPtr &c);
    const ParcelLockerPtr &getCurrentSelectedParcelLocker() const;
    void logout();
    const ClientPtr &getCurrentLoggedClient() const;
    void saveFiles();
    void loadFiles();

private slots:
    void handleButtonOrder();
    void handleButtonRegister();
    void handleButtonLogin();
    void handleButtonAdminPanel();
    void handleButtonCheckOrder();

private:
    Ui::MainWindow *ui;
    OrderDialog *orderDialog;
    RegisterDialog *registerDialog;
    LoginDialog *loginDialog;
    AdminDialog *adminDialog;
    CheckOrders *checkOrderDialog;
    SaveFilesManagerPtr saveFilesManager;
    ClientManagerPtr clientManager;
    ParcelLockerManagerPtr parcelLockerManager;
    PackageManagerPtr packageManager;
    OrderManagerPtr orderManager;
    ClientPtr currentLoggedClient = nullptr;
    ParcelLockerPtr currentSelectedParcelLocker = nullptr;
    MainWindow *parentWindow = this;
    QPushButton *buttonLogin;
    QPushButton *buttonRegister;
    QPushButton *buttonLogout;
    QPushButton *buttonOrder;
    QPushButton *buttonCheckOrder;
    QPushButton *buttonCancelOrder;
    QPushButton *buttonChangeLocker;
    QPushButton *buttonAdmin;
};

#endif //PARCELLOCKERPROJECT_MAINWINDOW_H
