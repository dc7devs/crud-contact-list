#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <qdebug.h>
#include <time.h>
#include <QList>
#include <QString>
#include <QPushButton>

using namespace std;

struct tContactData {
    int id;
    QString name;
    int birthdayDay, birthdayMonth;
    QString pathImage = ":/assets/assets/p-circle.svg";
};

//bool comparator(tContactData CurrentData, tContactData NewData) {
//    return (NewData.name < CurrentData.name);
//}

#endif
