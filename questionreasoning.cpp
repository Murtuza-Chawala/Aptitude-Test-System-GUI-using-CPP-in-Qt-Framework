#include "questionreasoning.h"
#include "ui_questionreasoning.h"
#include "welcome.h"
#include "questionverbal.h"
#include <QMessageBox>
void QuestionReasoning::nextQuestion()
{

    // Database Code

    qno++;
    count++;
    if(count<7){

    // qDebug() <<"Database  Connected";

        QSqlQuery qry;
       numm=iterate();
       QString num=QString::number(numm);
          if(qry.exec("select * from QuestionR where no='"+num+"'")){
        /* */
while(qry.next())
{
    ui->lineEdit_qno->setText(QString::number(count));
           ui->plainTextEdit_question->setPlainText(qry.value(1).toString());
        ui->ropt1->setText(qry.value(2).toString());
        ui->ropt2->setText(qry.value(3).toString());
        ui->ropt3->setText(qry.value(4).toString());
        ui->ropt4->setText(qry.value(5).toString());
        ans=qry.value(6).toInt();
            // Converting the answer into
             //  main.connclose();
}
          }
            }
            else{
    QMessageBox::information(this,"2nd Block Over","The Logical Block is Over Now, The Verbal Round Begins");
    QuestionVerbal *r=new QuestionVerbal();
    r->putData(quantimarks,logicmarks);
    r->putDetail(fname,lname,course,rollno,idno,cname,jname);
    this->hide();
        r->show();
}
}

int QuestionReasoning::iterate(){
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
    for(i=0;i<it;i++){

        if(a[i]==numm){
        flag=1;
            break;
        }
            }



        if(flag==1){
             qDebug()<<"Same";
        iterate();
        }

        else if(flag==0){
             qDebug()<<"NOT- Same";
         a[it]=numm;
         it++;
        }
        return numm;
}


QuestionReasoning::QuestionReasoning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionReasoning)
{
    ui->setupUi(this);
    Welcome main;
    main.connOpen();
    this->nextQuestion();
}

QuestionReasoning::~QuestionReasoning()
{
    delete ui;
}

        // Accept Marks from Earlier Forms.
            void QuestionReasoning::putData(int marks){
                this->quantimarks=marks;
            }

            // When Submit Button Is Clicked.

            // Accept Student Details.

            void QuestionReasoning::putDetail(QString fname, QString lname, QString course, QString rno, QString idno, QString cname, QString jname)
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


void QuestionReasoning::on_pushButton_Submitans_clicked()
{
    if(userans==ans){
        QMessageBox::information(this,"Right","The Answer is Correct");
        right+=1;
        logicmarks+=2;
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





void QuestionReasoning::on_ropt1_clicked()
{
    userans=1;
}

void QuestionReasoning::on_ropt2_clicked()
{
    userans=2;
}

void QuestionReasoning::on_ropt3_clicked()
{
    userans=3;
}

void QuestionReasoning::on_ropt4_clicked()
{
    userans=4;
}


