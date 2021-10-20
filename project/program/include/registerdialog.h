#ifndef PARCELLOCKERPROJECT_REGISTERDIALOG_H
#define PARCELLOCKERPROJECT_REGISTERDIALOG_H

#include <QDialog>
#include "../../library/include/typedefs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RegisterDialog; }
QT_END_NAMESPACE

class RegisterDialog : public QDialog {
Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr, ClientManagerPtr clientManager = nullptr);
    ~RegisterDialog() override;

private slots:
    void onButtonClicked();

private:
    Ui::RegisterDialog *ui;
    std::string login;
    std::string password;
    std::string firstName;
    std::string lastName;
    std::string personalId;
    ClientTypePtr clientType;
    ClientManagerPtr clientManager;
};

#endif //PARCELLOCKERPROJECT_REGISTERDIALOG_H
