#ifndef PARCELLOCKERPROJECT_ORDERDIALOG_H
#define PARCELLOCKERPROJECT_ORDERDIALOG_H

#include <QDialog>
#include "typedefs.h"
#include "showlockersdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class OrderDialog; }
QT_END_NAMESPACE

class OrderDialog : public QDialog {
Q_OBJECT

public:
    explicit OrderDialog(MainWindow *parentWindow, ParcelLockerManagerPtr parcelLockerManager = nullptr, OrderManagerPtr orderManager = nullptr, PackageManagerPtr packageManager = nullptr);
    ~OrderDialog() override;

private slots:
    void onButtonClicked();
    void onButtonClickedOpenParcelLockerDialog();

private:
    Ui::OrderDialog *ui;
    ParcelLockerPtr parcelLocker;
    ShowLockersDialog *showLockersDialog;
    MainWindow *parentWindow;

    ParcelLockerManagerPtr parcelLockerManager;
    OrderManagerPtr orderManager;
    PackageManagerPtr packageManager;

    PackageTypePtr packageType;
    PackagePtr package;
    OrderPtr order;

    double weight;
    int priority;
    bool fragile;
    bool payment;
    std::string comment;
};

#endif //PARCELLOCKERPROJECT_ORDERDIALOG_H
