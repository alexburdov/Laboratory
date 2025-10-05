#include <QApplication>

#include "include/gui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    MainWindow mainWindows;
    mainWindows.showMaximized();

    return QApplication::exec();
}
