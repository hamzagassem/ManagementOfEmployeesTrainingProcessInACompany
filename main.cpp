#include <QtGui/QApplication>
#include "mainwindow.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("F:/Hamza/projets/QT Projects/STICAP/style.qss");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        a.setStyleSheet(styleSheet);

        if (!createConnection())
               return -1 ;
    MainWindow w;
    w.showFullScreen();
    
    return a.exec();
}
