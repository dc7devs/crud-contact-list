#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <time.h>
#include <QList>
#include <QString>
#include <QPushButton>
#include <QFileDialog>

#include <QtSql>
#include <qdebug.h>

using namespace std;

struct tContactData {
    int id;
    QString name;
    QString birthdayDay, birthdayMonth;
    QString pathImage = ":/images/assets/person-circle.png";
};

tContactData pontToContactList;
QString *pathImage = new QString(pontToContactList.pathImage);

#define STYLE_IMAGE "QPushButton{ icon: url("+*pathImage+");} QPushButton:hover { icon: url(:/images/assets/camera-hover.png); image: url("+*pathImage+");} QPushButton:disabled {}"
#define STYLE_IMAGE_DEFAULT "QPushButton{ icon: url(:/images/assets/person-circle.png);} QPushButton:hover { icon: url(:/images/assets/camera-hover.png); image: url(:/images/assets/person-circle.png);} QPushButton:disabled {}"

#endif
