#include "questionverbal.h"
#include "ui_questionverbal.h"
#include "welcome.h"
#include "report.h"
#include <QMessageBox>
void QuestionVerbal::nextQuestion()
{

    // Database Code

    qno++;
    count++;
    if(count<7){


        QSqlQuery qry;
         numm=iterate();
         QString num=QString::number(numm);
 if(qry.exec("select * from QuestionV where no='"+num+"'"))
 {
while(qry.next())
{
    ui->lineEdit_qno->setText(QString::number(count));
          ui->plainTextEdit_question->setPlainText(qry.value(1).toString());
        ui->rop1->setText(qry.value(2).toString());
        ui->rop2->setText(qry.value(3).toString());
        ui->rop3->setText(qry.value(4).toString());
        ui->rop4->setText(qry.value(5).toString());
        ans=qry.value(6).toInt();
            // Converting the answer into
             //  main.connclose();
}
}
        }
    else{
        QMessageBox::information(this,"Done","Report Card !");
        Report *r=new Report();
        r->putData(quantimark,logicmark,verbmarks,cname);
      //

         r->putDetail(fname,lname,course,rollno,idno,cname,jname);
        this->hide();
            r->show();
             r->Insert();
    }
}

    /* A function which generates rnd questions and sees to it
    that the questions wont be repeated */


int QuestionVerbal::iterate(){
   flag=0;
   int low=10;
   int high=14;


           int number = qrand() % ((high + 1) - low) + low;
             qDebug()<<number;
              numm = qrand() % number;
              if(it==0){

               a[it]=numm;
               it++;
               return numm;
              }

             if(numm==0){ iterate(); }

             // Check if number is present in the array or not.
    for(i=0;i<it;i++){

        if(a[i]==numm){
             qDebug()<<" Same";
        flag=1;
            break;
        }
            }



        if(flag==1){
        iterate();
        }

        else if(flag==0){
             qDebug()<<"NOT- Same";
         a[it]=numm;
         it++;
        }
        return numm;
}



QuestionVerbal::QuestionVerbal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionVerbal)
{
    ui->setupUi(this);
    Welcome main;
    main.connOpen();
    this->nextQuestion();
}

QuestionVerbal::~QuestionVerbal()
{
    delete ui;
}


// Accept Marks from Earlier Forms.
    void QuestionVerbal::putData(int qmark, int lmark)
    {
         this->quantimark=qmark;
        this->logicmark=lmark;
    }

// When Submit Button Is Clicked.

        // Accept Student Data

    void QuestionVerbal::putDetail(QString fname, QString lname, QString course, QString rno, QString idno, QString cname, QString jname)
    {
        this->fname=fname;
            this->lname=lname;
            this->course=course;
            this->rollno=rno;
            this->idno=idno;
            this->cname=cname;
         ui->label_cname->setText(cname);
            this->jname=jname;
    }




    void QuestionVerbal::on_pushButton_Submitans_clicked()
{
        if(userans==ans){
            QMessageBox::information(this,"Right","The Answer is Correct");
            right+=1;
                verbmarks+=2;
           ui->label_right->setText(QString::number(right));
          this->nextQuestion();
        }
            else{
            wrong+=1;
                 QMessageBox::information(this,"Wrong","The Answer Not Correct ");
               ui->label_wrong->setText(QString::number(wrong));
              this->nextQuestion();
        }
}



    // When Radio Buttons Are Selected





void QuestionVerbal::on_rop1_clicked()
{
    userans=1;
}

void QuestionVerbal::on_rop2_clicked()
{
    userans=2;
}

void QuestionVerbal::on_rop3_clicked()
{
    userans=3;
}

void QuestionVerbal::on_rop4_clicked()
{
    userans=4;
}




