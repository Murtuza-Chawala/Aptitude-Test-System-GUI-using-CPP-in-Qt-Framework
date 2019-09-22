#include "studentsection.h"
#include "ui_studentsection.h"
#include"viewstudentdetails.h"
#include"postnotifications.h"
#include"viewcvdetails.h"
#include"viewtestdetails.h"
#include"postmeritlist.h"
#include"viewreports.h"
#include<QPixmap>
#include "choosesection.h"
#include "student_notice.h"
#include "login.h"

studentsection::studentsection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentsection)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");


    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
}

studentsection::~studentsection()
{
    delete ui;
}

void studentsection::on_pushButton_viewstudentdetails_clicked()
{

    viewstudentdetails *c=new viewstudentdetails();
    c->show();
    this->hide();

}

void studentsection::on_pushButton_postnotifications_clicked()
{

    postnotifications *c=new postnotifications();
    c->putdataAdmin(1);
    c->show();
    this->hide();

}

void studentsection::on_pushButton_viewcvdetails_clicked()
{

   viewcvdetails *c=new viewcvdetails();
    c->show();
    this->hide();

}

void studentsection::on_pushButton_viewtestdetails_clicked()
{

    viewtestdetails *c=new viewtestdetails();
    c->show();
    this->hide();

}

void studentsection::on_pushButton_postmeritlists_clicked()
{

    postmeritlist *c=new postmeritlist();
    c->show();
    this->hide();

}

void studentsection::on_pushButton_viewreports_clicked()
{

    viewreports *c=new viewreports();
    c->show();
    this->hide();

}

void studentsection::on_pushButton_gotohome_clicked()
{
    choosesection *c=new choosesection();
    c->show();
    this->hide();
}

void studentsection::on_pushButton_viewnotice_clicked()
{
    Student_Notice *s=new Student_Notice();
    s->putDataAdmin();
    s->show();
    this->hide();
}

void studentsection::on_pushButton_clicked()
{
    login *c=new login();
    c->show();
    this->hide();
}
