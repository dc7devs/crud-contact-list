#include "main.h"
#include "mainwindow.h"
#include <QMessageBox>

static QSqlDatabase DB=QSqlDatabase::addDatabase("QSQLITE");

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->ui.setupUi(this);
    this->ui.DetailsScreen->setVisible(false);
    this->ui.Modal->setVisible(false);
    this->ui.ButtonAddImage->setStyleSheet(STYLE_IMAGE_DEFAULT);

    QString dir=qApp->applicationDirPath();
    QString banco=dir+"/banco/contactlist";

    DB.setDatabaseName(banco);

    if(!DB.open()) {
        qDebug() << "Não foi possivel abrir o banco de dados :(";
    } else {
        qDebug() << "Banco aberto com sucesso!";
    }

    refreshQListWidget();

    connect(this->ui.AddNewContact, &QPushButton::clicked, this, &MainWindow::createContactScreen);
    connect(this->ui.ListContact, &QListWidget::itemClicked, this, &MainWindow::readContactScreen);

    connect(this->ui.ButtonEdit,  &QPushButton::clicked, this, &MainWindow::updateContactScreen);
    connect(this->ui.ButtonDelete, &QPushButton::clicked, this, &MainWindow::deleteContactScreen);

    connect(this->ui.SearchNameImput, &QLineEdit::textChanged, this, &MainWindow::searchName);
    connect(this->ui.ListButtons, &QListWidget::itemClicked, this, &MainWindow::searchNameForLetter);

    connect(this->ui.backPutton, &QPushButton::clicked, this, &MainWindow::backTomainwindow);
    connect(this->ui.ButtonAddImage, SIGNAL(clicked()), this, SLOT(addImage()));
    connect(this->ui.ButtonSave, &QPushButton::clicked, this, &MainWindow::saveContact);
    connect(this->ui.ButtonUpdate, &QPushButton::clicked, this, &MainWindow::updateContact);
}

void MainWindow::createContactScreen() {
    this->ui.ButtonSave->setVisible(true);
    this->ui.ButtonUpdate->setVisible(false);
    this->ui.ButtonEdit->setVisible(false);
    this->ui.ButtonDelete->setVisible(false);
    this->ui.ListContact->reset();

    this->ui.titleSection->setText("");

    *pathImage = ":/images/assets/person-circle.png";
    this->ui.ButtonAddImage->setStyleSheet(STYLE_IMAGE_DEFAULT);
    this->ui.ButtonAddImage->setDisabled(false);
    this->ui.lineEditName->setText("");
    this->ui.comboBoxDay->setCurrentIndex(-1);
    this->ui.comboBoxMonth->setCurrentIndex(-1);

    this->ui.lineEditName->setDisabled(false);
    this->ui.comboBoxDay->setDisabled(false);
    this->ui.comboBoxMonth->setDisabled(false);

    this->ui.DetailsScreen->setVisible(true);
}
void MainWindow::readContactScreen(QListWidgetItem *item) {
    this->ui.ButtonSave->setVisible(false);
    this->ui.ButtonUpdate->setVisible(false);
    this->ui.ButtonEdit->setVisible(true);
    this->ui.ButtonDelete->setVisible(true);
    this->ui.ListContact->reset();

    this->ui.titleSection->setText("Detalhes do Contato");

    this->ui.ButtonAddImage->setStyleSheet(STYLE_IMAGE);
    this->ui.ButtonAddImage->setDisabled(true);
    this->ui.lineEditName->setDisabled(true);
    this->ui.comboBoxDay->setDisabled(true);
    this->ui.comboBoxMonth->setDisabled(true);

    this->ui.DetailsScreen->setVisible(true);
    item->setSelected(true);

    int ID = item->data(6).toInt();
    readToDatabase(ID);
    this->ui.ButtonAddImage->setStyleSheet(STYLE_IMAGE);
}
void MainWindow::updateContactScreen() {
    this->ui.ButtonSave->setVisible(false);
    this->ui.ButtonUpdate->setVisible(true);
    this->ui.ButtonEdit->setVisible(false);
    this->ui.ButtonDelete->setVisible(false);

    this->ui.titleSection->setText("Editando Contato");

    this->ui.ButtonAddImage->setStyleSheet(STYLE_IMAGE);
    this->ui.ButtonAddImage->setDisabled(false);
    this->ui.lineEditName->setDisabled(false);
    this->ui.comboBoxDay->setDisabled(false);
    this->ui.comboBoxMonth->setDisabled(false);
}
void  MainWindow::deleteContactScreen() {
    // this->ui.Modal->setVisible(true);
    int ID = this->ui.ListContact->currentItem()->data(6).toInt();
    QMessageBox::StandardButton option = QMessageBox::question(this,"","Tem certeza que deseja excluir esse contato?", QMessageBox::Yes|QMessageBox::No);

    if(option == QMessageBox::Yes) {
        deleteToDatabase(ID);
        this->ui.DetailsScreen->setVisible(false);
    }
}

void MainWindow::searchName() {
    for(int i=0; i<this->ui.ListContact->count(); i++) {
        if(this->ui.ListContact->item(i)->text().toLower().contains(this->ui.SearchNameImput->text().toLower())) {
            this->ui.ListContact->item(i)->setHidden(false);

            if(this->ui.SearchNameImput->text() == "") {
                this->ui.ListContact->reset();
            }
        } else {
            this->ui.ListContact->item(i)->setHidden(true);
        }
    }
}
void MainWindow::searchNameForLetter(QListWidgetItem *item) {
    for(int i=0; i<this->ui.ListContact->count(); i++) {
        if(this->ui.ListContact->item(i)->text().toLower()[0] == item->text().toLower()) {
           this->ui.ListContact->item(i)->setHidden(false);
        } else {
            this->ui.ListContact->item(i)->setHidden(true);
        }
    }
}
void MainWindow::addImage() {
    QFileDialog dialog(this);

    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);

    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp *.jpeg *.gif)"));

    *pathImage = fileName != "" ? fileName : ":/images/assets/person-circle.png";
     this->ui.ButtonAddImage->setStyleSheet(STYLE_IMAGE);
}
void MainWindow::backTomainwindow(){
    this->ui.DetailsScreen->setVisible(false);
}

void MainWindow::saveContact() {
    pontToContactList = {
        this->ui.ListContact->count() != 0 ? this->ui.ListContact->count() +1: 1,
        this->ui.lineEditName->text(),
        this->ui.comboBoxDay->currentText(),
        this->ui.comboBoxMonth->currentText(),
        *pathImage
    };

    if (pontToContactList.name != "" && pontToContactList.birthdayDay != "" && pontToContactList.birthdayMonth != "") {
        addToDatabase();

        this->ui.DetailsScreen->setVisible(false);
    }
}
void MainWindow::updateContact() {
    int ID = this->ui.ListContact->currentItem()->data(6).toInt();
    updateToDatabase(ID);

    this->ui.DetailsScreen->setVisible(false);
}

void MainWindow::addToDatabase() {
    QSqlQuery query;
    query.prepare("INSERT INTO TB_CONTACT_LIST (id,name,day,month,pathimage) VALUES"
                  "("+QString::number(pontToContactList.id)+","
                  "'"+pontToContactList.name+"',"
                  "'"+pontToContactList.birthdayDay+"',"
                  "'"+pontToContactList.birthdayMonth+"',"
                  "'"+pontToContactList.pathImage+"')");

    if(query.exec()) {
        // int Row=0;
        // int NameSorted;
        QListWidgetItem *NewItem = new QListWidgetItem;

        NewItem->setData(2, pontToContactList.name);
        NewItem->setData(3, pontToContactList.birthdayDay);
        NewItem->setData(4, pontToContactList.birthdayMonth);
        NewItem->setData(5, pontToContactList.pathImage);
        NewItem->setData(6, pontToContactList.id);

        NewItem->setText(NewItem->data(2).toString());
        NewItem->setIcon(QIcon(NewItem->data(5).toString()));

        this->ui.ListContact->insertItem(this->ui.ListContact->count(), NewItem);
    } else {
        qDebug() << "Erro ao inserir contato no banco de dados!";
    }
}
void MainWindow::readToDatabase(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM TB_CONTACT_LIST WHERE id="+QString::number(id));

    if(query.exec()) {
        query.first();
        this->ui.lineEditName->setText(query.value(1).toString());
        this->ui.comboBoxDay->setCurrentText(query.value(2).toString());
        this->ui.comboBoxMonth->setCurrentText(query.value(3).toString());
        *pathImage = query.value(4).toString();
    }
}
void MainWindow::updateToDatabase(int id) {
    QString name = this->ui.lineEditName->text();
    QString day = this->ui.comboBoxDay->currentText();
    QString month = this->ui.comboBoxMonth->currentText();
    QString pathimg = *pathImage;

    if (name != "" && day != "" && month != "") {
        QSqlQuery query;
        query.prepare("UPDATE TB_CONTACT_LIST SET name      = '"+name+"', "
                                                 "day       = '"+day+"',  "
                                                 "month     = '"+month+"',"
                                                 "pathimage = '"+pathimg+"' WHERE id="+QString::number(id));
        if(query.exec()) {
            refreshQListWidget();
        }
    }
}
void MainWindow::deleteToDatabase(int id) {
    QSqlQuery query;

    query.prepare("DELETE FROM TB_CONTACT_LIST WHERE id="+QString::number(id));
    if(query.exec()) {
        refreshQListWidget();
    }
}

void MainWindow::refreshQListWidget() {
    QSqlQuery query;
    query.prepare("SELECT * FROM TB_CONTACT_LIST");
    if(query.exec()) {
        int Row=0;

        while(this->ui.ListContact->count() > 0) {
            this->ui.ListContact->takeItem(0);
        }
        while(query.next()){
            QListWidgetItem *NewItem = new QListWidgetItem;
            int ID = this->ui.ListContact->count() != 0 ? this->ui.ListContact->count() +1: 1;

            NewItem->setData(2, query.value(1).toString());
            NewItem->setData(3, query.value(2).toString());
            NewItem->setData(4, query.value(3).toString());
            NewItem->setData(5, query.value(4).toString());
            NewItem->setData(6, ID);

            NewItem->setText(NewItem->data(2).toString());
            NewItem->setIcon(QIcon(NewItem->data(5).toString()));

            this->ui.ListContact->insertItem(Row, NewItem);
            Row++;
        }
    }
}

MainWindow::~MainWindow() {}

