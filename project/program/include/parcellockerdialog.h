#ifndef PARCELLOCKERPROJECT_PARCELLOCKERDIALOG_H
#define PARCELLOCKERPROJECT_PARCELLOCKERDIALOG_H

#include <QDialog>
#include <typedefs.h>

class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class ParcelLockerDialog; }
QT_END_NAMESPACE

class ParcelLockerDialog : public QDialog {
Q_OBJECT

public:
    explicit ParcelLockerDialog(MainWindow *parentWindow = nullptr, ParcelLockerManagerPtr parcelLockerManager = nullptr);
    ~ParcelLockerDialog() override;

public slots:
    void onClickButton();

private:
    Ui::ParcelLockerDialog *ui;
    MainWindow *parentWindow;
    ParcelLockerManagerPtr parcelLockerManager;

    std::string city;
    std::string street;
    std::string number;
    AddressPtr address;
    std::string id;
    int freePlaces;
};

#endif //PARCELLOCKERPROJECT_PARCELLOCKERDIALOG_H
