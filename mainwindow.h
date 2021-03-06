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
        // Screens
        void createContactScreen();
        void readContactScreen(QListWidgetItem *item);
        void updateContactScreen();
        void deleteContactScreen();

        // specific methods
        void searchName();
        void searchNameForLetter(QListWidgetItem *item);
        void backTomainwindow();
        void addImage();
        void saveContact();
        void updateContact();

        // database
        void refreshQListWidget();
        void addToDatabase();
        void readToDatabase(int id);
        void updateToDatabase(int id);
        void deleteToDatabase(int id);
};

#endif
