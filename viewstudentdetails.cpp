#include "viewstudentdetails.h"
#include "ui_viewstudentdetails.h"
#include<QPixmap>
#include "login.h"
#include <QMessageBox>
#include"choosesection.h"
#include "studentsection.h"

viewstudentdetails::viewstudentdetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewstudentdetails)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");


    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
}

viewstudentdetails::~viewstudentdetails()
{
    delete ui;
}



void viewstudentdetails::on_comboBox_currentIndexChanged(const QString &arg1)
{

    QString idno=ui->comboBox->currentText();

    login conn;

    if(!conn.connOpen())
    {
        qDebug()<<"Failed";
        return;
    }
    else
    {
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from Student where idno='"+idno+"'");

    if(qry.exec())
    {
        while (qry.next())
        {
         ui-> lineEdit_fname->setText(qry.value(0).toString());
         ui-> lineEdit_lname->setText(qry.value(1).toString());
         ui-> lineEdit_email->setText(qry.value(2).toString());
         ui-> lineEdit_rollno->setText(qry.value(3).toString());
         ui-> lineEdit_phone->setText(qry.value(4).toString());
         ui-> lineEdit_course->setText(qry.value(5).toString());
         ui-> lineEdit_dob->setText(qry.value(6).toString());
         ui-> lineEdit_username->setText(qry.value(8).toString());
         ui-> lineEdit_password->setText(qry.value(9).toString());
         //ui-> lineEdit_gender->setText(qry.value(9).toString());
         //ui-> lineEdit_studentaddr->setText(qry.value(7).toString());


        }
      conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
    }


}

void viewstudentdetails::on_pushButton_loadtable_clicked()
{
    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);

    qry->prepare("select idno from Student");

    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
    //ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
    //


}

void viewstudentdetails::on_pushButton_close_clicked()
{
    studentsection *s=new studentsection();
    s->show();
    this->hide();
}



/*void viewstudentdetails::on_pushButton_clicked()
{

   choosesection *s=new choosesection();
   s->show();
   this->hide();
}*/




void viewstudentdetails::on_pushButton_gotohome_clicked()
{
    studentsection *s=new studentsection();
    s->show();
    this->hide();
}

void viewstudentdetails::on_pushButton_clicked()
{
    login *l=new login();
    this->hide();
    l->show();
}
