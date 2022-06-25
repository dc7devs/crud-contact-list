#include "main.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->ui.setupUi(this);
    this->ui.DetailsScreen->setVisible(false);
    this->ui.ButtonAddImage->setStyleSheet(STYLE_IMAGE_DEFAULT);

    QSqlDatabase DB=QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("/home/dcdevs/Desktop/www/QTs/crud-contact-list/contactlist");

    if(!DB.open()) {
        qDebug() << "Não foi possivel abrir";
    } else {
        qDebug() << "Banco aberto com sucesso";
    }

    connect(this->ui.AddNewContact, &QPushButton::clicked, this, &MainWindow::createContact);
    connect(this->ui.ListContact, &QListWidget::itemClicked, this, &MainWindow::readContact);

    connect(this->ui.SearchNameImput, &QLineEdit::textChanged, this, &MainWindow::searchName);
    connect(this->ui.backPutton, &QPushButton::clicked, this, &MainWindow::backTomainwindow);

    connect(this->ui.ButtonAddImage, SIGNAL(clicked()), this, SLOT(AddImage()));

    connect(this->ui.ButtonSave, &QPushButton::clicked, this, &MainWindow::saveContact);
}

// CRIAR CONTATO
void MainWindow::createContact() {
    this->ui.ButtonSave->setVisible(true);
    this->ui.ButtonEdit->setVisible(false);
    this->ui.ButtonDelete->setVisible(false);

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
// LER CONTATO
void MainWindow::readContact(QListWidgetItem *item) {
    this->ui.ButtonSave->setVisible(false);
    this->ui.ButtonEdit->setVisible(true);
    this->ui.ButtonDelete->setVisible(true);

    this->ui.titleSection->setText("Detalhes do Contato");

    *pathImage = item->data(5).toString();
    this->ui.ButtonAddImage->setStyleSheet(STYLE_IMAGE);
    this->ui.ButtonAddImage->setDisabled(true);
    this->ui.lineEditName->setDisabled(true);
    this->ui.comboBoxDay->setDisabled(true);
    this->ui.comboBoxMonth->setDisabled(true);

    this->ui.DetailsScreen->setVisible(true);

    this->ui.lineEditName->setText(item->data(2).toString());
    this->ui.comboBoxDay->setCurrentText(item->data(3).toString());
    this->ui.comboBoxMonth->setCurrentText(item->data(4).toString());
}
// ATUALIZAR CONTATO
void MainWindow::updateContact() {

}
// REMOVER CONTATO
void  MainWindow::deleteContact() {
}
void MainWindow::AddImage() {
    QFileDialog dialog(this);

    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);

    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));

    *pathImage = fileName != "" ? fileName : ":/images/assets/person-circle.png";
     this->ui.ButtonAddImage->setStyleSheet(STYLE_IMAGE);
}
void MainWindow::searchName(const QString &arg1) {
    // QRegularExpression QRegularExpression(arg1, Qt::CaseSensitive);
    //this->ui.ListContact->findItems(arg1, Qt::MatchContains);

    // pesquisar no banco de dados

    qDebug() << this->ui.SearchNameImput->text();
}
void MainWindow::backTomainwindow(){
    this->ui.DetailsScreen->setVisible(false);
}
void MainWindow::saveContact() {
    srand(time(NULL));
    int id = 1000 + rand() % 9999;

    // Estrutura de dados
    pontToContactList = {
        id,
        this->ui.lineEditName->text(),
        this->ui.comboBoxDay->currentText().toInt(),
        this->ui.comboBoxMonth->currentText().toInt(),
        *pathImage
    };

    // Adicionar contato ao banco

    // Fazer um refresh do banco na lista de contato, trazendo as informações que foram adicionadas ao baco
    if (pontToContactList.name != "" && pontToContactList.birthdayDay != 0 && pontToContactList.birthdayMonth != 0) {
        QListWidgetItem *NewItem = new QListWidgetItem;

        NewItem->setData(1, pontToContactList.id);
        NewItem->setData(2, pontToContactList.name);
        NewItem->setData(3, pontToContactList.birthdayDay);
        NewItem->setData(4, pontToContactList.birthdayMonth);
        NewItem->setData(5, pontToContactList.pathImage);


        NewItem->setText(NewItem->data(2).toString());
        NewItem->setIcon(QIcon(NewItem->data(5).toString()));

        // for (int i=0; i<this->ui.ListContact->count(); ++i) {
        // Inserir contato de forma ordenada no banco de dados

             qDebug() << pontToContactList.id;
             qDebug() << pontToContactList.name;
             qDebug() << pontToContactList.birthdayDay;
             qDebug() << pontToContactList.birthdayMonth;
             qDebug() << pontToContactList.pathImage;


            this->ui.ListContact->insertItem(this->ui.ListContact->count(), NewItem);
        // }
        this->ui.DetailsScreen->setVisible(false);
    }
}

MainWindow::~MainWindow() {}

//it = contactList.begin();
//for (;it != contactList.end(); it++);
//contactList.insert(it, pontToContactList);
