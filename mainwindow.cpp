// #include "main.h"
#include <iostream>
#include "mainwindow.h"
#include "contactdetails.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->ui.setupUi(this);
    connect(this->ui.AddNewContact, &QPushButton::clicked, this, &MainWindow::changeToScreenContactDetails);
}

MainWindow::~MainWindow() {}

void MainWindow::changeToScreenContactDetails() {
    ContactDetails* ScreenContactDetails = new ContactDetails;
    ScreenContactDetails->show();
    close();
}
