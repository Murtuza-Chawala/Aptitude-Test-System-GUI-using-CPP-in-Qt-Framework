#include "viewtestdetails.h"
#include "ui_viewtestdetails.h"
#include<QPixmap>
#include"choosesection.h"
#include "login.h"
#include "QMessageBox"
#include "studentsection.h"

viewtestdetails::viewtestdetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewtestdetails)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");


    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
}

viewtestdetails::~viewtestdetails()
{
    delete ui;
}

void viewtestdetails::on_pushButton_close_clicked()
{
    studentsection *c=new studentsection();
    c->show();
   this->hide();
}

void viewtestdetails::on_pushButton_gotohome_clicked()
{
    studentsection *c=new studentsection();
    c->show();
   this->hide();
}

void viewtestdetails::on_btn_load_clicked()
{
    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);

    qry->prepare("select idno from Report");

    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
    //ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());

}

void viewtestdetails::on_comboBox_currentIndexChanged(const QString &arg1)
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
    qry.prepare("select * from Report where idno='"+idno+"'");

    if(qry.exec())
    {
        while (qry.next())
        {
         ui->lineEdit_name->setText(qry.value(0).toString());
         ui->lineEdit_lname->setText(qry.value(1).toString());
         ui->lineEdit_score->setText(qry.value(6).toString());
         int correct,wrong;
         correct=ui->lineEdit_score->text().toInt();
         correct=correct/2;
         wrong=21-correct;
         ui->lineEdit_correct->setText(QString::number(correct));
         ui->lineEdit_wrong->setText(QString::number(wrong));
         ui->lineEdit_company->setText(qry.value(7).toString());
         ui->lineEdit_job->setText(qry.value(8).toString());
         ui->lineEdit_status->setText(qry.value(9).toString());

        }

      conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
    }
}

void viewtestdetails::on_pushButton_clicked()
{
    login *l=new login();
    this->hide();
    l->show();
}
