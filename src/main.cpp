#include "mainwindow.h"
#include "dialog.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog d;
    MainWindow w;
    d.insertWindow(&w);
    d.show();
    return a.exec();
}
