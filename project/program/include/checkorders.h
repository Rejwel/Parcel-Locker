#ifndef PARCELLOCKERPROJECT_CHECKORDERS_H
#define PARCELLOCKERPROJECT_CHECKORDERS_H

#include <QDialog>
#include <typedefs.h>
#include "showclientorders.h"

class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class CheckOrders; }
QT_END_NAMESPACE

class CheckOrders : public QDialog {
Q_OBJECT

public:
    explicit CheckOrders(MainWindow *parentWindow = nullptr, OrderManagerPtr orderManager = nullptr);
    ~CheckOrders() override;

public slots:
    void quitWindow();
    void showSingleButton();
    void showAllButton();

private:
    Ui::CheckOrders *ui;
    MainWindow *parentWindow;
    OrderManagerPtr orderManager;
    ShowClientOrders *showClientOrdersDialog;
};

#endif //PARCELLOCKERPROJECT_CHECKORDERS_H
