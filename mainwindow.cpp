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
    this->ui.ButtonSave->setVisible(true);
    this->ui.ButtonEdit->setVisible(false);
    this->ui.ButtonDelete->setVisible(false);

    this->ui.titleSection->setText("");

    this->ui.lineEditName->setText("");
    this->ui.comboBoxDay->currentText();
    this->ui.comboBoxMonth->currentText();

    this->ui.lineEditName->setDisabled(false);
    this->ui.comboBoxDay->setDisabled(false);
    this->ui.comboBoxMonth->setDisabled(false);

    this->ui.DetailsScreen->setVisible(true);
}
// LER CONTATO
void MainWindow::readContact(QListWidgetItem *item) {
    this->ui.ButtonSave->setVisible(false);
    this->ui.ButtonEdit->setVisible(true);
    this->ui.ButtonDelete->setVisible(true);

    this->ui.titleSection->setText("Detalhes do Contato");

    this->ui.lineEditName->setDisabled(true);
    this->ui.comboBoxDay->setDisabled(true);
    this->ui.comboBoxMonth->setDisabled(true);

    this->ui.DetailsScreen->setVisible(true);

    this->ui.lineEditName->setText(item->data(2).toString());
    this->ui.comboBoxDay->setCurrentText(item->data(3).toString());
    this->ui.comboBoxMonth->setCurrentText(item->data(4).toString());
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

    pontToContactList = {
        id,
        this->ui.lineEditName->text(),
        this->ui.comboBoxDay->currentText().toInt(),
        this->ui.comboBoxMonth->currentText().toInt()
    };

    if (pontToContactList.name != "" && pontToContactList.birthdayDay != 0 && pontToContactList.birthdayMonth != 0) {
        //QVariant datas(pontToContactList);
        // QIcon(pontToContactList.pathImage), pontToContactList.name

        QListWidgetItem *NewItem = new QListWidgetItem;

        NewItem->setData(1, pontToContactList.id);
        NewItem->setData(2, pontToContactList.name);
        NewItem->setData(3, pontToContactList.birthdayDay);
        NewItem->setData(4, pontToContactList.birthdayMonth);
        NewItem->setData(5, pontToContactList.pathImage);


        NewItem->setText(NewItem->data(2).toString());
        NewItem->setIcon(QIcon(NewItem->data(5).toString()));

        //for (int i=0; i<this->ui.ListContact->count(); ++i) {
            this->ui.ListContact->insertItem(this->ui.ListContact->count(), NewItem);
        //}
        this->ui.DetailsScreen->setVisible(false);
    }
}

MainWindow::~MainWindow() {}


//it = contactList.begin();
//for (;it != contactList.end(); it++);
//contactList.insert(it, pontToContactList);
