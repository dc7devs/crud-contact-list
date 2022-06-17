#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "main.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

     private:
        Ui::MainWindow ui;

    private slots:
        void createContact();//                             C
        void readContact(QListWidgetItem *item);//        R
        void updateContact(tContactData contact);//                             U
        void deleteContact(tContactData contact);//                             D

        void backTomainwindow();
        void saveContact();
};

#endif
