#ifndef PARCELLOCKERPROJECT_SHOWCLIENTORDERS_H
#define PARCELLOCKERPROJECT_SHOWCLIENTORDERS_H

#include <QDialog>
#include <typedefs.h>
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class ShowClientOrders; }
QT_END_NAMESPACE

class ShowClientOrders : public QWidget {
Q_OBJECT

public:
    explicit ShowClientOrders(MainWindow *parentWindow = nullptr, OrderManagerPtr orderManager = nullptr, bool showAll = false);
    ~ShowClientOrders() override;

public slots:
    void quitWindow();
    void onClickButton();


private:
    bool showAll;
    Ui::ShowClientOrders *ui;
    MainWindow *parentWindow;
    OrderManagerPtr orderManager;
};

#endif //PARCELLOCKERPROJECT_SHOWCLIENTORDERS_H
