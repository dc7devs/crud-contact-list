#include "mainwindow.h"

QList<tContactData> contactList;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->ui.setupUi(this);
    this->ui.DetailsScreen->setVisible(false);

    connect(this->ui.AddNewContact, &QPushButton::clicked, this, &MainWindow::createContact);
    connect(this->ui.ListContact, &QListWidget::itemClicked, this, &MainWindow::readContact);

    connect(this->ui.backPutton, &QPushButton::clicked, this, &MainWindow::backTomainwindow);
    connect(this->ui.ButtonSave, &QPushButton::clicked, this, &MainWindow::saveContact);
}

// CRIAR CONTATO
void MainWindow::createContact() {
    this->ui.DetailsScreen->setVisible(true);
}
// LER CONTATO
void MainWindow::readContact(QListWidgetItem *item) {

}
// ATUALIZAR CONTATO
void MainWindow::updateContact(tContactData contact) {
}
// REMOVER CONTATO
void  MainWindow::deleteContact(tContactData contact) {
}


void MainWindow::backTomainwindow(){
    this->ui.DetailsScreen->setVisible(false);
}
void MainWindow::saveContact() {
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
        this->ui.comboBoxDay->currentText().toInt(),
        this->ui.comboBoxMonth->currentText().toInt()
    };

    if (pontToContactList.name != "" && pontToContactList.birthdayDay != 0 && pontToContactList.birthdayMonth != 0) {
        it = contactList.begin();
        for (;it != contactList.end(); it++);
        contactList.insert(it, pontToContactList);

        this->ui.DetailsScreen->setVisible(false);
    } else;

    // contactList.sort(comparator); // organizar a lista em ordem alfabetica
}

MainWindow::~MainWindow() {}
