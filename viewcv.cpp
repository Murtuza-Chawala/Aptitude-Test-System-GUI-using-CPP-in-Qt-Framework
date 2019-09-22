#include "viewcv.h"
#include "ui_viewcv.h"
#include "welcome.h"
#include "studentmain.h"

ViewCv::ViewCv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewCv)
{
    ui->setupUi(this);
}

ViewCv::~ViewCv()
{
    delete ui;
}

void ViewCv::putData(QString fname, QString lname, QString course, QString rollno, QString id){
    ui->label_fname->setText(fname);
    ui->label_lname->setText(lname);
    ui->label_course->setText(course);
    ui->label_rno->setText(rollno);
    ui->label_id->setText(id);
            // Accept CV values. using idno as foreign key
    QString ten,twel,univ,intern,dur,spec,cert;
    this->fname=fname;
    this->lname=lname;
    this->course=course;
    this->rollno=rollno;
    this->idno=id;
    Welcome main;
if(main.connOpen()){
    QSqlQuery qry;
 if(qry.exec("Select * from CV where idno='"+id+"'")){
while(qry.next()){
    ten=qry.value(0).toString();
    twel=qry.value(1).toString();
    univ=qry.value(2).toString();
    intern=qry.value(3).toString();
    dur=qry.value(4).toString();
    spec=qry.value(5).toString();
    cert=qry.value(6).toString();
        // QMessageBox::information(this,"","Success");
}
}
 else{
     qDebug() <<"Error";
 }

}
    // Adding Cv details to the labels.
            ui->label_ten->setText(ten);
             ui->label_twelve->setText(twel);
              ui->label_univ->setText(univ);
               ui->label_intern->setText(intern);
                ui->label_dur->setText(dur);
                ui->label_spec->setText(spec);
                 ui->label_cert->setText(cert);
}

void ViewCv::on_pushButton_Submit_clicked()
{
    StudentMain *m=new StudentMain();
    m->putData(fname,lname,course,rollno,idno);
        this->hide();
        m->show();
}
