#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "contactdetails.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->AddNewContact, &QPushButton::clicked, this, &MainWindow::changeToScreenContactDetails);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::changeToScreenContactDetails() {
    ContactDetails* ScreenContactDetails = new ContactDetails;
    ScreenContactDetails->show();
    close();
}

