#ifndef POSTNOTIFICATIONS_H
#define POSTNOTIFICATIONS_H

#include <QDialog>
#include"login.h"

namespace Ui {
class postnotifications;
}

class postnotifications : public QDialog
{
    Q_OBJECT

public:
    explicit postnotifications(QWidget *parent = 0);
    void putdataAdmin(int);
    void putdataStud(QString,QString,QString,QString,QString);
    QString course,fname,rollno,lname,idno;
    QString d;
    int user=0;
    ~postnotifications();

private slots:
    void on_pushButton_submit_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_gotohome_clicked();

    void on_pushButton_clicked();

private:
    Ui::postnotifications *ui;
};

#endif // POSTNOTIFICATIONS_H
