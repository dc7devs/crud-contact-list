#include "main.h"
#include "contactdetails.h"
#include "mainwindow.h"

QList<tContactData> contactList;
tContactData pontToContactList;

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

QList<tContactData> ContactDetails::saveContact() {
    pontToContactList = {
        this->ui.lineEditName->text(),
        this->ui.spinBoxDay->value(),
        this->ui.spinBoxMonth->value()
    };


    QList<tContactData>::iterator it = contactList.begin();
    for (;it != contactList.end(); it++);
    contactList.insert(it, pontToContactList);

    return contactList;
}
