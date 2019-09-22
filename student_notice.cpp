#include "student_notice.h"
#include "ui_student_notice.h"
#include "login.h"
#include "studentmain.h"
#include "studentsection.h"
#include "welcome.h"

Student_Notice::Student_Notice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Student_Notice)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
    ui->radioButton_placement->setVisible(false);
    ui->radioButton_princi->setVisible(false);
}

Student_Notice::~Student_Notice()
{
    delete ui;
}

void Student_Notice::putData(QString fname, QString lname, QString course, QString rollno, QString id)
{
    this->fname=fname;
    this->lname=lname;
    this->course=course;
    this->rollno=rollno;
    this->idno=id;
}

void Student_Notice::putDataAdmin(){
    ui->radioButton_placement->setVisible(true);
    ui->radioButton_princi->setVisible(true);
     this->user=1;
}

void Student_Notice::on_pushButton_load_clicked()
{

    if(user!=1){
        // Student View
    login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.company);


qry->prepare("select * from Notice where too='"+course+"'");
    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    conn.connClose();
}
    else{
        // Admin View.

            QString sender;
           if(ui->radioButton_placement->isChecked())
           {
               sender=ui->radioButton_placement->text();
           }
          else if(ui->radioButton_princi->isChecked()){
                sender=ui->radioButton_princi->text();
           }

           login conn;
           QSqlQueryModel *modal=new QSqlQueryModel();

           conn.connOpen();
           QSqlQuery * qry=new QSqlQuery(conn.company);


       qry->prepare("select * from Notice where too='"+sender+"'");
           qry->exec();
           modal->setQuery(*qry);

           ui->tableView->setModel(modal);
           conn.connClose();


    }
}


void Student_Notice::on_pushButton_home_clicked()
{
    if(user!=1){
    StudentMain *s=new StudentMain();
    s->putData(fname,lname,course,rollno,idno);
    s->show();
    this->hide();
    }
    else{
        studentsection *s=new studentsection();
        s->show();
        this->hide();
    }
}

void Student_Notice::on_tableView_activated(const QModelIndex &index)
{
    /*int rowidx = ui->tblView->selectionModel()->currentIndex().row();
    qDebug() << rowidx;*/


   Welcome main;
    QString val=ui->tableView->model()->data(index).toString();
    qDebug() <<val;
    if(main.connOpen()){
        QSqlQuery qry;
 qry.exec("Select * from notice where data='"+val+"' or sender='"+val+"' or too='"+val+"' or datee='"+val+"'");

    while(qry.next()){

        QString q=qry.value(0).toString();
        qDebug() << q;

}
    }
}
