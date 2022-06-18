#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <qdebug.h>
#include <time.h>
#include <QList>
#include <QString>
#include <QPushButton>
#include <QFileDialog>

using namespace std;

struct tContactData {
    int id;
    QString name;
    int birthdayDay, birthdayMonth;
    QString pathImage = ":/images/assets/person-circle.png";
};

//bool comparator(tContactData CurrentData, tContactData NewData) {
//    return (NewData.name < CurrentData.name);
//}

tContactData pontToContactList;
QString *pathImage = new QString(pontToContactList.pathImage);

#define STYLE_IMAGE "QPushButton{ icon: url("+*pathImage+");} QPushButton:hover { icon: url(:/images/assets/camera-hover.png); image: url("+*pathImage+");} QPushButton:disabled {filter: grayscale(0);}"
#define STYLE_IMAGE_DEFAULT "QPushButton{ icon: url(:/images/assets/person-circle.png);} QPushButton:hover { icon: url(:/images/assets/camera-hover.png); image: url(:/images/assets/person-circle.png);} QPushButton:disabled {filter: grayscale(0);"

#endif
