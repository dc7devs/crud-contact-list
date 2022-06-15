#include "main.h"
#include "mainwindow.h"

QList<tContactData> contactList;

ContactDetails::ContactDetails(QWidget *parent): QMainWindow(parent) {
    this->ui.setupUi(this);

    connect(this->ui.backPutton, &QPushButton::clicked, this, &ContactDetails::backTomainwindow);
    connect(this->ui.ButtonSave, &QPushButton::clicked, this, &ContactDetails::saveContact);
}

ContactDetails::~ContactDetails() {}

void ContactDetails::backTomainwindow(){
    MainWindow* ScreenMainWindow = new MainWindow;
    ScreenMainWindow->show();

    close();
}

bool ContactDetails::comparator(tContactData CurrentData, tContactData NewData) {
    return (NewData.name < CurrentData.name);
}

void ContactDetails::saveContact() {
    tContactData pontToContactList;

    srand(time(NULL));
    int id = 1000 + rand() % 9999;
    QList<tContactData>::iterator it = contactList.begin();
    for(;it!=contactList.end() && id != it->id; it++) {
        id = 1000 + rand() % 9999;
    };

    pontToContactList = {
        id,
        this->ui.lineEditName->text(),
        this->ui.spinBoxDay->value(),
        this->ui.spinBoxMonth->value()
    };

    if (pontToContactList.name != "" && pontToContactList.birthdayDay != 0 && pontToContactList.birthdayMonth != 0) {
        it = contactList.begin();
        for (;it != contactList.end(); it++);
        contactList.insert(it, pontToContactList);
    } else;

//     MainWindow->ui.ListContact->addItem(pontToContactList);

    // contactList.sort(comparator); // organizar a lista em ordem alfabetica

//    qDebug() << "size cotact list(depois): " << contactList.size();
//    for(QList<tContactData>::iterator it = contactList.begin(); it != contactList.end(); it++) {
//          qDebug() << it->id;
//          qDebug() << it->name;
//          qDebug() << it->birthdayDay << "/" << it->birthdayMonth << "\n";
//    }
}

