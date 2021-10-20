#include <iostream>
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
    int a = app.exec();
    mainWindow->saveFiles();
    return a;
}