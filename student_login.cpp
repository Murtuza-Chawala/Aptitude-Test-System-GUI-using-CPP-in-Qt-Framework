#include "student_login.h"
#include "ui_student_login.h"
#include "welcome.h"
#include "student_registration.h"
#include "studentmain.h"
#include <QInputDialog>

Student_Login::Student_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Student_Login)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/placementc.jpg");


    //ui->label_placement->setPixmap(pix.scaled(650,650,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/Murtuz/Desktop/Placement Working/Placement_Cell/Picture/logo.jpg");


    //ui->label_logo->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));


    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(timerr()));
    Welcome main;
}

Student_Login::~Student_Login()
{
    delete ui;
}

void Student_Login::timerr()
{
    x+=50;
    ui->progressBar->setValue(x);
    if(x==100){
        QMessageBox::information(this,"Success","Log-In Successful");
        StudentMain *stud=new StudentMain();
        stud->putData(fname,lname,course,rno,idno);
        this->hide();
            stud->show();
    }
}

void Student_Login::on_pushButton_4_clicked()
{
    this->hide();
   Welcome *wlcm =new Welcome;
    wlcm->showMaximized();
}

void Student_Login::on_pushButton_NewUser_clicked()
{
    Student_Registration *rgster=new Student_Registration;
    this->hide();
    rgster->show();
}

void Student_Login::on_pushButton_Submit_clicked()
{
    Welcome main;
    int count=0;
        QString username,password;
       username=ui->lineEdit_username->text();
       password=ui->lineEdit_password->text();
    if(main.connOpen()){
        QSqlQuery qry;
 qry.exec("Select * from Student where username='"+username+"' and password='"+password+"'");
    while(qry.next()){
        count++;
        fname=qry.value(0).toString();
        lname=qry.value(1).toString();
        rno=qry.value(3).toString();
        course=qry.value(5).toString();
        idno=qry.value(7).toString();
         //    QMessageBox::information(this,"",fname);
    }

    if(count!=0){
        timer->start(400);
        ui->progressBar->setVisible(true);

    }
    else{
        qDebug() <<count;
        QMessageBox::information(this,"Failure","Invalid username Or password");
    }
    }


}





void Student_Login::on_pushButton_fpwd_clicked()
{
    Welcome main;
    // Generate Password.

    QString id,email;
    id = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Enter your College Id No:"), QLineEdit::Normal);

    email = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Enter your E-Mail Id:"), QLineEdit::Normal);

    if(!main.connOpen())
    {
        qDebug()<<"Failed to open database";
        return;
    }
    else
    {
    QSqlQuery qry;
    int flag=0;
    qry.prepare("select * from Student where idno='"+id+"' and password='"+email+"'");
    if(qry.exec())
    {

        while (qry.next())
        {
            flag=1;
            QString pwd=qry.value(9).toString();
            QMessageBox::information(this,"Password: ",pwd);
            }
    }
        if(flag==0)
        QMessageBox::information(this,"Incorrect","Please Re-Enter your Id and Password");
        }

}

void Student_Login::on_pushButton_Reset_clicked()
{
    ui->lineEdit_password->setText("");
    ui->lineEdit_username->setText("");
}

void Student_Login::on_pushButton_HOME_clicked()
{
    Welcome *w=new Welcome();
        w->show();
        this->hide();
}
