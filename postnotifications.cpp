#include "postnotifications.h"
#include "ui_postnotifications.h"
#include"login.h"
#include<QPixmap>
#include<QMessageBox>
#include "choosesection.h"
#include "studentsection.h"
#include "studentmain.h"
#include <QDate>

postnotifications::postnotifications(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::postnotifications)
{
    ui->setupUi(this);



    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");


    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));

}

postnotifications::~postnotifications()
{
    delete ui;
}

// For the Admin
   void postnotifications::putdataAdmin(int i){
ui->comboBox_from->addItem("Placement-In-Charge");
ui->comboBox_from->addItem("The Principal");
 ui->comboBox_from->addItem("Other Faculty");
  ui->comboBox_to->addItem("BBA");
   ui->comboBox_to->addItem("BBA(CA)");
    ui->comboBox_to->addItem("BBA(IB)");
     QDate cd = QDate::currentDate();
      d=cd.toString();
    this->user=i;
   }

   void postnotifications::putdataStud(QString fname, QString lname, QString course, QString rollno, QString id){
       this->fname=fname;
       this->lname=lname;
       this->course=course;
       this->rollno=rollno;
       this->idno=id;
       ui->comboBox_from->addItem(idno);
       ui->comboBox_to->addItem("Placement-In-Charge");
       ui->comboBox_to->addItem("The Principal");
       this->user=user;
       QDate cd = QDate::currentDate();
        d=cd.toString();

   }

void postnotifications::on_pushButton_submit_clicked()
{

    login conn;
    QString data,sender,too;
    data=ui->plainTextEdit_notice->toPlainText();
    sender=ui->comboBox_from->currentText();
    too=ui->comboBox_to->currentText();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed";
        return;
    }
    else
    {
    conn.connOpen();
    QSqlQuery qry;


    if(qry.exec("insert into notice(data,sender,too,datee) values('"+data+"','"+sender+"','"+too+"','"+d+"')"))
    {
      QMessageBox::information(this,tr("NOTICE"),tr(" SENT ! "));

    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
    conn.connClose();
    }



}

void postnotifications::on_pushButton_cancel_clicked()
{
    if(this->user==1){
    studentsection *s=new studentsection();
    s->show();
    this->hide();
    }
    else{
        StudentMain *s=new StudentMain();
        s->putData(fname,lname,course,rollno,idno);
        s->show();
        this->hide();
    }
}

void postnotifications::on_pushButton_gotohome_clicked()
{
    if(this->user==1){
    choosesection *c=new choosesection();
    c->show();
    this->hide();
    }
        else{
        StudentMain *s=new StudentMain();
        s->putData(fname,lname,course,rollno,idno);
        s->show();
        this->hide();
    }
}

void postnotifications::on_pushButton_clicked()
{
    login *l=new login();
    this->hide();
    l->show();
}
