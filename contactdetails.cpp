#include "contactdetails.h"
#include "ui_contactdetails.h"

#include "mainwindow.h"

ContactDetails::ContactDetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ContactDetails)
{
    ui->setupUi(this);

    connect(ui->backPutton, &QPushButton::clicked, this, &ContactDetails::backTomainwindow);
}

ContactDetails::~ContactDetails() {
    delete ui;
}


void ContactDetails::backTomainwindow(){
    MainWindow* ScreenMainWindow = new MainWindow;
    ScreenMainWindow->show();
    close();
}
