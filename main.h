#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <QList>
#include <QString>
#include <qdebug.h>
#include <QPushButton>

struct tContactData {
    QString name;
    int birthdayDay, birthdayMonth;
};

//bool comparator(tContactData CurrentData, tContactData NewData) {
//    return (NewData.name < CurrentData.name);
//}

#endif
