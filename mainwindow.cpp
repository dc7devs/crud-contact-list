 #include "main.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->ui.setupUi(this);
    connect(this->ui.AddNewContact, &QPushButton::clicked, this, &MainWindow::createContact);
    connect(this->ui.ListContact, &QListWidget::itemClicked, this, &MainWindow::contactDetails);
}

MainWindow::~MainWindow() {}

void MainWindow::createContact() {
    ContactDetails* ScreenContactDetails = new ContactDetails;
    ScreenContactDetails->show();
    close();
}

void MainWindow::contactDetails(QListWidgetItem *item) {
    ContactDetails* ScreenContactDetails = new ContactDetails;
    ScreenContactDetails->show();
    close();
}
