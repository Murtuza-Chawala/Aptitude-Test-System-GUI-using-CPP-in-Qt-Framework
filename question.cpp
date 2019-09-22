#include "question.h"
#include "ui_question.h"
#include "welcome.h"
#include "questionreasoning.h"
#include <QMessageBox>
#include "QtGlobal"
#include <QInputDialog>

void Question::nextQuestion()
{
    // Database Code
    qno++;

         count++;
        if(count<7){


    // qDebug() <<"Database  Connected";

        QSqlQuery qry;

        numm=iterate();
   // qDebug()<<numm;
         QString num=QString::number(numm);
          if(qry.exec("select * from Question where no='"+num+"'")){

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
            // Logical Reasoning.
            else{
    QMessageBox::information(this,"1st Block Over","The Quantitative  Block is Over Now, The Logical Reasoning Round Begins");
    QuestionReasoning *r=new QuestionReasoning();
    r->putData(marks);
    r->putDetail(fname,lname,course,rollno,idno,cname,jname);

    this->hide();
        r->show();
}

}


int Question::iterate(){
    flag=0;



               numm = qrand() % n;

               // First Iteration Will Execute
               if(it==0){

                a[it]=numm;
                it++;
                return numm;
               }

               // If Random Number comes out to be zero.
              if(numm==0){ iterate(); }

              // Checking all elements in the existing array.


     for(i=0;i<it;i++){

         if(a[i]==numm){
             qDebug()<<"Same";
         flag=1;
             break;
         }
             }

         // Checking whether to iterate again or Not

         if(flag==1){
             // Same Number has been Generated Again.
             // Hence we use recursion
             qDebug()<<"Iterate";
         iterate();
         }

         else if(flag==0){
             //  Different Number has been Generated.
             qDebug()<<"NOT- Same";
          a[it]=numm;
          it++;
         }
         return numm;
}



void Question::putData(QString fname, QString lname, QString course, QString rno, QString idno, QString cname, QString jname)
{
    ui->label_cname->setText(cname);
    this->fname=fname;
        this->lname=lname;
        this->course=course;
        this->rollno=rno;
        this->idno=idno;
        this->cname=cname;
        this->jname=jname;

}


void Question::generate(){


    // Accepting a Number from User
do{
  num = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                           tr("Enter a Number greater than '7 and less than 22 ':"), QLineEdit::Normal);

     n=num.toInt();
    if(n>7 && n<22){
        check=1;
    }
   }while(check==0);
  //  QMessageBox::information(this,"",num);
}



Question::Question(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Question)
{
    ui->setupUi(this);
    Welcome main;
    main.connOpen();
    this->generate();
    this->nextQuestion();
}

Question::~Question()
{
    delete ui;
}

void Question::on_pushButton_Submitans_clicked()
{

                if(userans==ans){
                    QMessageBox::information(this,"Right","The Answer is Correct");
//                   // right+=1;
                    marks+=2;
                    right=(marks/2);
                   ui->label_right->setText(QString::number(right));
                  this->nextQuestion();
                }
                    else if(userans!=ans){
                         QMessageBox::information(this,"Wrong","The Answer Not Correct ");
                       ui->label_right->setText(QString::number(marks));
                       wrong= (count-right);
                       ui->label_wrong->setText(QString::number(wrong));
                      this->nextQuestion();
                }
                  }





void Question::on_ropt1_clicked()
{
    userans=1;
}

void Question::on_ropt2_clicked()
{
    userans=2;
}

void Question::on_ropt3_clicked()
{
    userans=3;
}

void Question::on_ropt4_clicked()
{
    userans=4;
}

