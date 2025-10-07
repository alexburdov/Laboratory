//
// Created by Aleksandr Burdovitzin on 06.10.2025.
//

#include <QApplication>

#include "include/gui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    MainWindow mainWindows;
    mainWindows.showMaximized();

    return QApplication::exec();
}
