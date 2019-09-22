#include "postmeritlist.h"
#include "ui_postmeritlist.h"
#include<QPixmap>
#include<QMessageBox>
#include "choosesection.h"
#include "studentsection.h"
#include"login.h"

postmeritlist::postmeritlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::postmeritlist)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");


    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
}

postmeritlist::~postmeritlist()
{
    delete ui;
}

void postmeritlist::on_btn_close_clicked()
{
    studentsection *c=new studentsection();
    c->show();
    this->hide();
}

void postmeritlist::on_pushButton_gotohome_2_clicked()
{
    choosesection *c=new choosesection();
    c->show();
    this->hide();
}

void postmeritlist::on_btn_meritlist_clicked()
{
    login conn;
        // Enter Company Names into Combo-Box.
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);



    qry->prepare("select compname from postvacancy");

    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_cname->setModel(modal);


    QMessageBox::information(this,tr("Post"),tr("Posted"));
}

void postmeritlist::on_comboBox_cname_currentIndexChanged(const QString &arg1)
{

        QString cname=ui->comboBox_cname->currentText();
    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);

    qry->prepare("Select * from Report where company='"+cname+"' order by tscore");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView_company->setModel(modal);
    conn.connClose();
}

void postmeritlist::on_pushButton_clicked()
{
    login *l=new login();
    this->hide();
    l->show();
}
