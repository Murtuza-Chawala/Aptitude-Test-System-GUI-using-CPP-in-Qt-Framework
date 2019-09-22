#include "postvacancy.h"
#include "ui_postvacancy.h"
#include<QPixmap>
#include<QMessageBox>
#include "choosesection.h"
#include "companydetails.h"
#include"login.h"

postvacancy::postvacancy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::postvacancy)
{
    ui->setupUi(this);

    login conn;
       conn.connOpen();


       QRegExp rx2 ("[0-9]{2}");
       ui->lineEdit_eligibility->setValidator(new QRegExpValidator (rx2, this));

       QRegExp rx3 ("[A-Z a-z]{20}");
       ui->lineEdit_jobprofile->setValidator(new QRegExpValidator (rx3, this));

       QRegExp rx4 ("[0-9,]{20}");
       ui->lineEdit_salary->setValidator(new QRegExpValidator (rx4, this));

    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");

    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
}

postvacancy::~postvacancy()
{
    delete ui;
}



void postvacancy::on_pushButton_loadtable_clicked()
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

void postvacancy::on_pushButton_post_clicked()
{
    login conn;

    QString jobpro,sal,eligible,bond;
    jobpro=ui->lineEdit_jobprofile->text();
    sal=ui->lineEdit_salary->text();
    eligible=ui->lineEdit_eligibility->text();
    bond=ui->lineEdit_bond->text();
    QString company=ui->comboBox->currentText();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed";
        return;
    }
    else
    {
    conn.connOpen();
  //  QMessageBox::information(this,tr("POST"),tr("Posted"));
    QSqlQuery qry;

                    qry.prepare("insert into postvacancy (compname,jobpro,sal,eligible,bond) values ('"+company+"','"+jobpro+"','"+sal+"','"+eligible+"','"+bond+"')");
                    if(qry.exec())
                    {
                      QMessageBox::information(this,tr("POST"),tr("Posted"));
                      conn.connClose();
                    }
                    else
                    {
                        QMessageBox::critical(this,tr("Warning"),tr("Company Already exists"));
                    }
          }

  }

void postvacancy::on_pushButton_update_clicked()
{

    login conn;
    QString compname,jobpro,sal,eligible,bond;
    jobpro=ui->lineEdit_jobprofile->text();
    sal=ui->lineEdit_salary->text();
    eligible=ui->lineEdit_eligibility->text();
    bond=ui->lineEdit_bond->text();
    QString comp=ui->comboBox->currentText();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed";
        return;
    }
    else
    {
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Update postvacancy set jobpro='"+jobpro+"',sal='"+sal+"',eligible='"+eligible+"',bond='"+bond+"' where compname='"+comp+"'");

    if(qry.exec())
    {
      QMessageBox::information(this,tr("Edit"),tr("Updated"));
      conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
    }


}

void postvacancy::on_pushButton_delete_clicked()
{

    login conn;
    QString compname,jobpro,sal,eligible,bond;
    jobpro=ui->lineEdit_jobprofile->text();
    sal=ui->lineEdit_salary->text();
    eligible=ui->lineEdit_eligibility->text();
    bond=ui->lineEdit_bond->text();
    QString comp1=ui->comboBox->currentText();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed";
        return;
    }
    else
    {
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from postvacancy where compname='"+comp1+"'");

    if(qry.exec())
    {
      QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
      conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
    }


}

void postvacancy::on_pushButton_close_clicked()
{
    companydetails *c=new companydetails();
    c->show();
    this->hide();
}

void postvacancy::on_pushButton_gotohome_clicked()
{

    choosesection cs;
    cs.setModal(true);
    cs.exec();
    this->hide();
}

void postvacancy::on_check_clicked()
{
        ui->lineEdit_bond->setText("");
        ui->lineEdit_eligibility->setText("");
        ui->lineEdit_jobprofile->setText("");
        ui->lineEdit_salary->setText("");

    login conn;
    QString company=ui->comboBox->currentText();
    if(conn.connOpen())
    {
        QSqlQuery qry;
        if(qry.exec("select *  from postvacancy where compname='"+company+"'"))
        {
            while(qry.next())
            {
                ui->lineEdit_jobprofile->setText(qry.value(1).toString());
                ui->lineEdit_salary->setText(qry.value(2).toString());
                ui->lineEdit_eligibility->setText(qry.value(3).toString());
                ui->lineEdit_bond->setText(qry.value(4).toString());

            }
        }
    }
}

void postvacancy::on_pushButton_clicked()
{
    login *l=new login();
    this->hide();
    l->show();
}
