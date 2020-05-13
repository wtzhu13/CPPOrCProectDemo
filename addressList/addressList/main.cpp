#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QProcess>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));
    QProcess process;
    process.start("C:\\mysql\\bin\\mysqld.exe");
    if(!createConnection()) { return 1;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
