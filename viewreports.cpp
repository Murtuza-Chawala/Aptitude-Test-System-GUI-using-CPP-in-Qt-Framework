#include "viewreports.h"
#include "ui_viewreports.h"
#include<QPixmap>
#include"login.h"
#include "choosesection.h"
#include "studentsection.h"

viewreports::viewreports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewreports)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");


    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
}

viewreports::~viewreports()
{
    delete ui;
}

void viewreports::on_pushButton_close_clicked()
{
    studentsection *s=new studentsection();
    s->show();
    this->hide();
}

void viewreports::on_pushButton_gotohome_clicked()
{
    studentsection*c=new studentsection();
    c->show();
    this->hide();
}

void viewreports::on_pushButton_loadtablelist_clicked()
{

    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);


qry->prepare("select * from Student");
    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());

}

void viewreports::on_pushButton_loadTestReport_clicked()
{

    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);

 qry->prepare("select * from Report");
    qry->exec();
    modal->setQuery(*qry);

    ui->tableView_report->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void viewreports::on_pushButton_LoadCV_clicked()
{
    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);

 qry->prepare("select * from CV");
    qry->exec();
    modal->setQuery(*qry);

    ui->tableView_CV->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void viewreports::on_pushButton_LoadCompany_clicked()
{
    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);

 qry->prepare("select * from compinfo");
    qry->exec();
    modal->setQuery(*qry);

    ui->tableView_Company->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void viewreports::on_pushButton_clicked()
{
    login *l=new login();
    this->hide();
    l->show();
}
