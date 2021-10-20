#ifndef PARCELLOCKERPROJECT_ADMINDIALOG_H
#define PARCELLOCKERPROJECT_ADMINDIALOG_H

#include <QDialog>
#include <typedefs.h>
#include "parcellockerdialog.h"

class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class AdminDialog; }
QT_END_NAMESPACE

class AdminDialog : public QDialog {
Q_OBJECT

public:
    explicit AdminDialog(MainWindow *parentWindow = nullptr, ClientManagerPtr clientManager = nullptr, ParcelLockerManagerPtr parcelLockerManager = nullptr);
    ~AdminDialog() override;

public slots:
    void onClickButton();

private:
    Ui::AdminDialog *ui;
    MainWindow *parentWindow;
    ClientManagerPtr clientManager;
    ParcelLockerManagerPtr parcelLockerManager;
    ParcelLockerDialog *parcelLockerDialog;

};

#endif //PARCELLOCKERPROJECT_ADMINDIALOG_H
