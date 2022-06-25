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
        void createContact();
        void readContact(QListWidgetItem *item);
        void updateContact();
        void deleteContact();

        void searchName(const QString &arg1);
        void backTomainwindow();
        void AddImage();
        void saveContact();
};

#endif
