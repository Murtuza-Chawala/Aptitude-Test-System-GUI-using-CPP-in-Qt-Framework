#include "take_test.h"
#include "ui_take_test.h"
#include "question.h"
#include "login.h"
#include <qmessagebox.h>
Take_Test::Take_Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Take_Test)
{
    ui->setupUi(this);

}

Take_Test::~Take_Test()
{
    delete ui;
}

   void Take_Test::putData(QString fname,QString lname,QString course,QString rno,QString idno)
   {
    //ui->label_rno_idno->setText(idno);
    this->fname=fname;
    this->lname=lname;
    this->course=course;
    this->rollno=rno;
    this->idno=idno;
        // Adding companies data according to course

}







void Take_Test::on_pushButton_Submit_clicked()
{
    cname=ui->comboBox_cname->currentText();
    jname=ui->comboBox_jname->currentText();

    if(ui->checkBox_chk->isChecked()){
        Question *q=new Question();
        q->putData(fname,lname,course,rollno,idno,cname,jname);
            this->hide();
            q->show();
    }
        else{
        QMessageBox::information(this,"Alert","Please Agree to the Terms and Conditions First");
    }
}

void Take_Test::on_pushButton_Generate_clicked()
{
    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();


    //

    QSqlQuery * qry=new QSqlQuery(conn.company);

    qry->prepare("select compname from postvacancy");

    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_cname->setModel(modal);




    conn.connClose();


}

void Take_Test::on_comboBox_cname_currentIndexChanged(const QString &arg1)
{
    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();
     QSqlQuery * qry=new QSqlQuery(conn.company);

    QString cname=ui->comboBox_cname->currentText();
    // setting JobProfile Data according to compname




    qry->prepare("select jobpro from postvacancy where compname='"+cname+"'");

    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_jname->setModel(modal);

}
