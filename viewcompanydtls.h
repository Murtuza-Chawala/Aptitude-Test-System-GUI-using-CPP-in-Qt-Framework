#ifndef VIEWCOMPANYDTLS_H
#define VIEWCOMPANYDTLS_H

#include <QDialog>
#include "login.h"

namespace Ui {
class viewcompanydtls;
}

class viewcompanydtls : public QDialog
{
    Q_OBJECT

public:
    explicit viewcompanydtls(QWidget *parent = 0);
    ~viewcompanydtls();

private slots:
    void on_btn_loadtable_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_gotohome_clicked();

    void on_pushButton_gotohome_2_clicked();

    void on_pushButton_clicked();

public:  void putData(QString,QString,QString,QString,QString,int);
 public:       QString course,fname,rollno,lname,idno;
 public:       int flag=0;

private:
    Ui::viewcompanydtls *ui;
};

#endif // VIEWCOMPANYDTLS_H
