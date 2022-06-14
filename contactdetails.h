#ifndef CONTACTDETAILS_H
#define CONTACTDETAILS_H

#include <QMainWindow>
#include "ui_contactdetails.h"
#include "main.h"

class ContactDetails : public QMainWindow {
    Q_OBJECT

public:
    explicit ContactDetails(QWidget *parent = nullptr);
    ~ContactDetails();

private:
    Ui::ContactDetails ui;

private slots:
    void backTomainwindow();

    void saveContactToDataList();
    bool comparator(tContactData CurrentData, tContactData NewData);
};

#endif
