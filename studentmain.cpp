#include "studentmain.h"
#include "ui_studentmain.h"
#include "welcome.h"
#include "take_test.h"
#include "viewcv.h"
#include "report.h"
#include "faq1.h"
#include"viewcompanydtls.h"
#include "student_notice.h"
#include "postnotifications.h"

StudentMain::StudentMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentMain)
{
    ui->setupUi(this);
}

StudentMain::~StudentMain()
{
    delete ui;
}

void StudentMain::putData(QString fname, QString lname, QString course,QString rno,QString id)
{
        ui->label_course->setText(course);
        ui->label_lname->setText(lname);
        ui->label_name->setText(fname);
        ui->label_rno->setText(rno);
        ui->label_idno->setText(id);
        // Assigning values.
        this->fname=fname;
        this->lname=lname;
        this->course=course;
        this->rollno=rno;
        this->idno=id;
}

void StudentMain::on_pushButton_test_clicked()
{
   Take_Test *t=new Take_Test();
   t->putData(fname,lname,course,rollno,idno);
    this->hide();
    t->show();
}


void StudentMain::on_pushButton_cv_clicked()
{

   ViewCv *v=new ViewCv();
   v->putData(fname,lname,course,rollno,idno);
    v->show();
        this->hide();
}

void StudentMain::on_pushButton_report_clicked()
{
        // Fetch Values From Report DB.
        QString qscore,lscore,vscore,tscore,cmp,job,status;
        Welcome main;
            QSqlQuery qry;
     if(qry.exec("Select * from Report where idno='"+idno+"'")){
        while(qry.next()){
            fname=qry.value(0).toString();
            lname=qry.value(1).toString();
            idno=qry.value(2).toString();
            qscore=qry.value(3).toString();
            lscore=qry.value(4).toString();
            vscore=qry.value(5).toString();
            tscore=qry.value(6).toString();
            cmp=qry.value(7).toString();
            job=qry.value(8).toString();
            status=qry.value(9).toString();

             //    QMessageBox::information(this,"",fname);
        }
       }
            else{
         QMessageBox::information(this,"Eror","Error");
     }
    Report *r=new Report();
   r->mainData(fname,lname,idno,qscore,lscore,vscore,tscore,cmp,job,status);
   r->retData(fname,lname,course,rollno,idno);
        r->show();
            this->hide();
}

void StudentMain::on_pushButton_faq_clicked()
{
    FAQ1 *f=new FAQ1();
      f->putData(fname,lname,course,rollno,idno);
        f->show();
            this->hide();
}

void StudentMain::on_pushButton_home_clicked()
{
    Welcome *w=new Welcome();
        this->hide();
        w->show();
}



void StudentMain::on_pushButton_profile_clicked()
{
    int flag=1;
    viewcompanydtls *c=new viewcompanydtls();
    c->putData(fname,lname,course,rollno,idno,flag);
    this->hide();
    c->show();
}

void StudentMain::on_pushButton_notice_clicked()
{
    Student_Notice *s=new Student_Notice();
    s->putData(fname,lname,course,rollno,idno);
    s->show();
    this->hide();
}

void StudentMain::on_pushButton_Post_Notice_clicked()
{
    postnotifications *p=new postnotifications();
    p->putdataStud(fname,lname,course,rollno,idno);
    p->show();
    this->hide();
}
