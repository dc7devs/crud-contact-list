#ifndef CONTACTDETAILS_H
#define CONTACTDETAILS_H

#include <QMainWindow>

namespace Ui {
class ContactDetails;
}

class ContactDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContactDetails(QWidget *parent = nullptr);
    ~ContactDetails();

private:
    Ui::ContactDetails *ui;

private slots:
    void backTomainwindow();

};

#endif // CONTACTDETAILS_H
