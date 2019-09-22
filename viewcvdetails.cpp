#include "viewcvdetails.h"
#include "ui_viewcvdetails.h"
#include "login.h"
#include<QPixmap>
#include <QMessageBox>
#include "choosesection.h"
#include "studentsection.h"

viewcvdetails::viewcvdetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewcvdetails)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");


    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
}

viewcvdetails::~viewcvdetails()
{
    delete ui;
}

void viewcvdetails::on_comboBox_currentIndexChanged(const QString &arg1)
{

    QString idno=ui->comboBox->currentText();

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
    qry.prepare("select * from CV where idno='"+idno+"'");

    if(qry.exec())
    {
        while (qry.next())
        {
         ui-> lineEdit_10thmarks->setText(qry.value(0).toString());
         ui-> lineEdit_12thmarks->setText(qry.value(1).toString());
       //  ui-> lineEdit_fymarks->setText(qry.value(2).toString());
       //  ui-> lineEdit_symarks->setText(qry.value(3).toString());
         ui-> lineEdit_specialization->setText(qry.value(5).toString());
         ui-> lineEdit_internships->setText(qry.value(3).toString());
         ui-> lineEdit_certifications->setText(qry.value(6).toString());
         ui-> lineEdit_univ->setText(qry.value(2).toString());
         ui-> lineEdit_duration->setText(qry.value(4).toString());

        }
      conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
    }


}

void viewcvdetails::on_pushButton_loadtable_clicked()
{

    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);

    qry->prepare("select idno from CV");

    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
    //ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());


}

void viewcvdetails::on_pushButton_close_clicked()
{
    studentsection *s=new studentsection();
    s->show();
    this->hide();
}

void viewcvdetails::on_pushButton_gotohome_clicked()
{

    choosesection *c=new choosesection();
    c->show();
    this->hide();
}

void viewcvdetails::on_pushButton_clicked()
{
    login *l=new login();
    this->hide();
    l->show();
}
