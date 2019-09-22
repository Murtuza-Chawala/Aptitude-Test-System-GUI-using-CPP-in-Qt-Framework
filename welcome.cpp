 #include "welcome.h"
#include "ui_welcome.h"
#include "student_login.h"
#include "take_test.h"
#include "question.h"
#include "questionreasoning.h"
#include "questionverbal.h"
#include "cv_builder.h"
#include"contactus.h"
#include"login.h"
#include <QDate>
#include<QPixmap>
#include<QTime>
#include <QInputDialog>


Welcome::Welcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);

    QDate cd = QDate::currentDate();
       QTime ct = QTime::currentTime();
    ui->label_date->setText(cd.toString());
    ui->label_time->setText(ct.toString());

    QPixmap pix("C:/Users/SAMSUNG/Desktop/Placement Working/Placement_Cell/Img/placementc.jpg");
    ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix2("C:/Users/SAMSUNG/Desktop/Placement Working/Placement_Cell/Img/main.jpg");
    ui->label_main->setPixmap(pix2.scaled(1100,1150,Qt::KeepAspectRatio));


    QPixmap pix1("C:/Users/SAMSUNG/Desktop/Placement Working/Placement_Cell/Img/logo.jpg");
    ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));


}

Welcome::~Welcome()
{
    delete ui;
}


void Welcome::on_pushButton_Student_clicked()
{


    this->hide();
   Student_Login *stud= new Student_Login();
        stud->show();
}


void Welcome::on_pushButton_Admin_clicked()
{
    login *l=new login();
    this->hide();
    l->show();
}

void Welcome::on_pushButton_clicked()
{
    contactus *cs= new contactus();
    this->hide();
    cs->show();
}
