#ifndef PARCELLOCKERPROJECT_SHOWLOCKERSDIALOG_H
#define PARCELLOCKERPROJECT_SHOWLOCKERSDIALOG_H

#include <QDialog>
#include "typedefs.h"
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class ShowLockersDialog; }
QT_END_NAMESPACE

class ShowLockersDialog : public QDialog {
Q_OBJECT

public:
    explicit ShowLockersDialog(MainWindow *parentWindow, ParcelLockerManagerPtr parcelLockerManager);
    ~ShowLockersDialog() override;

public slots:
    void closeWindow();

private:
    Ui::ShowLockersDialog *ui;
    MainWindow *parentWindow;
    ParcelLockerManagerPtr parcelLockerManager;
    std::vector<ParcelLockerPtr> parcelLockers;
};

#endif //PARCELLOCKERPROJECT_SHOWLOCKERSDIALOG_H
