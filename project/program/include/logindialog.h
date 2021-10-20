#ifndef PARCELLOCKERPROJECT_LOGINDIALOG_H
#define PARCELLOCKERPROJECT_LOGINDIALOG_H

#include <QDialog>
#include <typedefs.h>

class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }
QT_END_NAMESPACE

class LoginDialog : public QDialog {
Q_OBJECT

public:
    explicit LoginDialog(MainWindow *parentWindow = nullptr, ClientManagerPtr clientManager = nullptr);
    ~LoginDialog() override;
    const ClientPtr &getClient() const;

public slots:
    void onButtonClicked();

private:
    Ui::LoginDialog *ui;
    MainWindow *parentWindow;
    ClientManagerPtr clientManager;
    ClientPtr client;
    std::string login;
    std::string password;
};

#endif //PARCELLOCKERPROJECT_LOGINDIALOG_H
