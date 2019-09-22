#include "report.h"
#include "ui_report.h"
#include "welcome.h"
#include "studentmain.h"

Report::Report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
}

Report::~Report()
{
    delete ui;
}
    // The Function Which takes in marks and puts grade,score in Form.
    void Report::putData(int qscore, int lscore, int vscore,QString cname){
        // First Function to be exec from student main.
        ui->label_quanscore->setText(QString::number(qscore));
        ui->label_logicscore->setText(QString::number(lscore));
        ui->label_verbscore->setText(QString::number(vscore));
        this->cname=cname;

     //   QMessageBox::information(this,"",cname);

        this->qscore=qscore;
        this->lscore=lscore;
        this->vscore=vscore;
        qgrade=(qscore/2);
        lgrade=(lscore/2);
        vgrade=(vscore/2);
            ui->label_qcorrect->setText(QString::number(qgrade));
            ui->label_lcorrect->setText(QString::number(lgrade));
            ui->label_vcorrect->setText(QString::number(vgrade));
            fscore=(qscore+lscore+vscore);

            // Converting int values to string
            qsc=QString::number(qscore);
            lsc=QString::number(lscore);
            vsc=QString::number(vscore);
            tsc=QString::number(fscore);

                ui->label_finalscore->setText(QString::number(fscore));
            Welcome main;
            main.connOpen();
                QSqlQuery qry;
                qry.prepare("Select * from postvacancy where compname='"+cname+"'");

                 if(qry.exec()){
            //         QMessageBox::information(this,"True","Database is Open");
                     while(qry.next()){
            //             QMessageBox::information(this,"Te","qry next runs");
                         eligible=qry.value(3).toInt();
                         QMessageBox::information(this,"Company Cutoff =",QString::number(eligible));
                 }
                 }


                if(fscore>=eligible){ this->status="PASS";
                QMessageBox::information(this,"Congratulations","Pass");}
                    else { this->status="FAIL";
                QMessageBox::information(this,"Work Harder","Fail");}
            ui->label_status->setText(status);



    }


    void Report::putDetail(QString fname, QString lname, QString course, QString rno, QString idno, QString cname, QString jname)
    {



        this->fname=fname;
            this->lname=lname;
            this->course=course;
            this->rollno=rno;
            this->idno=idno;
            this->cname=cname;
            this->jname=jname;

        ui->label_name->setText(fname);
        ui->label_lname->setText(lname);
        ui->label_course->setText(course);
        ui->label_rno->setText(idno);
        ui->label_cname->setText(cname);
        ui->label_jname->setText(jname);

    }

         void Report::Insert(){
             // Insert Data into Report DataBase.
          Welcome  main;
          main.connOpen();
          QSqlQuery qry;




  qry.prepare("insert into Report(fname,lname,idno,qscore,lscore,vscore,tscore,company,job,status) values('"+fname+"','"+lname+"','"+idno+"','"+qsc+"','"+lsc+"','"+vsc+"','"+tsc+"','"+cname+"','"+jname+"','"+status+"')");

 if(qry.exec()){
             QMessageBox::information(this,"Success","Report Details Successfully Added");
         }
         else{
          QMessageBox::information(this,"ERROR","Retry");
         }
         }

         // From the Student Main Page.

     void Report::mainData(QString fname, QString lname, QString id, QString qsc, QString lsc, QString vsc, QString tsc, QString cmp, QString job, QString status){
    ui->label_name->setText(fname);
     ui->label_lname->setText(lname);
     ui->label_rno->setText(id);
     ui->label_quanscore->setText(qsc);
     ui->label_logicscore->setText(lsc);
     ui->label_verbscore->setText(vsc);
     ui->label_finalscore->setText(tsc);
     ui->label_cname->setText(cmp);
      ui->label_jname->setText(job);
       ui->label_status->setText(status);
     }

void Report::on_pushButton_Submit_clicked()
{
    StudentMain *m=new StudentMain();
        this->hide();
        m->putData(fname,lname,course,rollno,idno);
        m->show();
}

 void Report::retData(QString fname, QString lname, QString course, QString rollno, QString id)
 {
     this->fname=fname;
     this->lname=lname;
     this->course=course;
     this->rollno=rollno;
     this->idno=id;
 }
