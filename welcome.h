#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class Welcome;
}

class Welcome : public QMainWindow
{
    Q_OBJECT
public: QSqlDatabase db;
public: QString data;

 public: bool connOpen()
 {
    db=QSqlDatabase::addDatabase("QSQLITE");
   // db.setDatabaseName("C:/Users/Murtuz/Desktop/Widgets/myData.db");
    db.setDatabaseName("C:/Users/Murtuz/Desktop/Placement Final/Placement_Cell/company.db");
    // C:\Users\Murtuz\Desktop\Placement_Cell\myData.db

    if(!db.open())
    {
        QMessageBox::information(this,"failure","Database Connection Failed");
        return false;
    }
    else
    {
      //  QMessageBox::information(this,"Success","Database Connection is Successfull");
        return true;

    }

 }

 public: void connclose()
    {
    db.close();
    QMessageBox::information(this,"Removed","Database Connection Successfully Unlinked");
    db.removeDatabase(QSqlDatabase::defaultConnection);

    }



public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();

private slots:

    void on_pushButton_Student_clicked();

    void on_pushButton_Admin_clicked();

    void on_pushButton_clicked();

private:
    Ui::Welcome *ui;
};

#endif // WELCOME_H
