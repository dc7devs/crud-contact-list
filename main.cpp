#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    QSplashScreen *splash = new QSplashScreen;

    splash->finish(&w);
    splash->setPixmap(QPixmap("favicon.png"));
    splash->show();

    w.show();

    delete splash;
    return a.exec();
}
