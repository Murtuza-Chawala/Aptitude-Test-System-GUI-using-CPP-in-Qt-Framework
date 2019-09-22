#include "viewcompanydtls.h"
#include "ui_viewcompanydtls.h"
#include<QPixmap>
#include<QMessageBox>
#include "choosesection.h"
#include "login.h"
#include "companydetails.h"
#include "studentmain.h"

viewcompanydtls::viewcompanydtls(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewcompanydtls)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");


    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));

}

viewcompanydtls::~viewcompanydtls()
{
    delete ui;
}

void viewcompanydtls::putData(QString fname, QString lname, QString course, QString rollno, QString id,int flag)
{
    this->fname=fname;
    this->lname=lname;
    this->course=course;
    this->rollno=rollno;
    this->idno=id;
    this->flag=flag;
}


void viewcompanydtls::on_btn_loadtable_clicked()
{
    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);

    qry->prepare("select compname from compinfo");

    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);

    conn.connClose();
    qDebug()<<(modal->rowCount());

}

void viewcompanydtls::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString compname=ui->comboBox->currentText();

    login conn;

    if(!conn.connOpen())
    {
        qDebug()<<"Failed";
        return;
    }
    else
    {
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select* from compinfo where compname='"+compname+"'");

    if(qry.exec())
    {
        while (qry.next())
        {
         ui->lineEdit_cid->setText(qry.value(0).toString());
         ui->lineEdit_caddr->setText(qry.value(2).toString());
         ui-> lineEdit_contactno->setText(qry.value(3).toString());
         ui->lineEdit_email->setText(qry.value(4).toString());
         ui->lineEdit_website->setText(qry.value(5).toString());

        }

        // This is for post Vacany data.
        QSqlQuery qry;
        qry.prepare("select * from postvacancy where compname='"+compname+"'");

        if(qry.exec())
        {
            while (qry.next())
            {
             ui->lineEdit_job->setText(qry.value(1).toString());
             ui->lineEdit_ctc->setText(qry.value(2).toString());
             ui-> lineEdit_elegi->setText(qry.value(3).toString());
             ui->lineEdit_bond->setText(qry.value(4).toString());
            }
        }




      conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
    }

}

void viewcompanydtls::on_pushButton_2_clicked()
{
    if(this->flag==1){
        /* Student is viewing company details hence go back to student
        page with all his details*/
        StudentMain *s=new StudentMain();
           s->putData(fname,lname,course,rollno,idno);
        s->show();
        this->hide();
    }
    else{
    companydetails *c=new companydetails();
    c->show();
    this->hide();
}
}



void viewcompanydtls::on_pushButton_gotohome_2_clicked()
{
   /* hide();
    choosesection cs;
    cs.setModal(true);
    cs.exec();*/
}

void viewcompanydtls::on_pushButton_gotohome_clicked()
{
    if(this->flag==1){
        /* Student is viewing company details hence go back to student
        page with all his details*/
        StudentMain *s=new StudentMain();
         s->putData(fname,lname,course,rollno,idno);
        s->show();
        this->hide();
    }
    else{
    choosesection *c=new choosesection();
    c->show();
    this->hide();
}
}

void viewcompanydtls::on_pushButton_clicked()
{
    login *l=new login();
    this->hide();
    l->show();
}
