#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
        void updateContact();//                             U
        void deleteContact();//                             D

        void backTomainwindow();
        void AddImage();
        void saveContact();
};

#endif
