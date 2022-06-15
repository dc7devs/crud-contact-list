#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "main.h"
#include "ui_mainwindow.h"
#include "ui_contactdetails.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

     private:
        Ui::MainWindow ui;

    private slots:
        void createContact();
        void contactDetails(QListWidgetItem *item);
};

class ContactDetails : public QMainWindow {
    Q_OBJECT

    public:
        explicit ContactDetails(QWidget *parent = nullptr);
        ~ContactDetails();

    private:
        Ui::ContactDetails ui;

    private slots:
        void backTomainwindow();

        void saveContact();
        bool comparator(tContactData CurrentData, tContactData NewData);
};

#endif
