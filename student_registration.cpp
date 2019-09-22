    // Original Project
    #include "student_registration.h"
    #include "ui_student_registration.h"
    #include "welcome.h"
    #include "cv_builder.h"
    Student_Registration::Student_Registration(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Student_Registration)
    {
        ui->setupUi(this);
        // Validator Code
        QRegExp rx ("[A-Za-z]{12}");
        ui->lineEdit_fname->setValidator(new QRegExpValidator (rx, this));
         ui->lineEdit_lname->setValidator(new QRegExpValidator (rx, this));

         QRegExp rx1 ("[0-9/]{10}");
      ui->lineEdit_dob->setValidator(new QRegExpValidator (rx1, this));

       QRegExp   rx2 ("[0-9]{4}");
      ui->lineEdit_IdCard->setValidator(new QRegExpValidator (rx2, this));

        QRegExp rx3 ("[A-Za-z0-9@.]{30}");
      ui->lineEdit_email->setValidator(new QRegExpValidator (rx3, this));

        ui->lineEdit_newuname->setValidator(new QRegExpValidator (rx3, this));

      QRegExp   rx4 ("[0-9]{10}");
        ui->lineEdit_number->setValidator(new QRegExpValidator (rx4, this));

       QRegExp  rx5 ("[A-Za-z0-9_]{9}");
        ui->lineEdit_newpwd->setValidator(new QRegExpValidator (rx5, this));
         ui->lineEdit_repwd->setValidator(new QRegExpValidator (rx5, this));

         QRegExp  rx6 ("[0-9]{2}");
         ui->lineEdit_rno->setValidator(new QRegExpValidator (rx6, this));



        ui->comboBox_course->addItem("BBA(CA)");
        ui->comboBox_course->addItem("BBA(IB)");
        ui->comboBox_course->addItem("BBA");
        ui->lineEdit_dob->setPlaceholderText("dd/mm/yy");
        ui->lineEdit_number->setPlaceholderText("Ph_Num");
        ui->lineEdit_fname->setPlaceholderText("first name");
        ui->lineEdit_lname->setPlaceholderText("last name");
        ui->lineEdit_email->setPlaceholderText("Email-id");
        ui->lineEdit_rno->setPlaceholderText("Roll_No");
       // ui->lineEdit_lname->setValidator(QRegExp rx("[a-z]"));
        //ui->lineEdit_lname->setValidator("a-z");
    }

    Student_Registration::~Student_Registration()
    {
        delete ui;
    }

    void Student_Registration::on_pushButton_4_clicked()
    {
        Welcome *w =new Welcome();
        this->hide();
            w->show();
    }


    void Student_Registration::on_pushButton_Submit_clicked()
    {
        Welcome main;
       /*     QSqlQuery qry;
                  fname=ui->lineEdit_fname->text();
            if(main.connOpen()){
    // qry.prepare("insert into Student(fname,lname,email,rollno,phno,course,dob,id,username,password) values('"+fname+"','"+lname+"','"+email+"','"+rollno+"','"+phno+"','"+course+"','"+dob+"','"+id+"','"+username+"','"+password+"')");
        qry.("insert into Student(fname) values('"+fname+"')");

                            if(qry.exec()){
                                QMessageBox::information(this,"Success","Details Successfully added to the Database");
                                CV_Builder *c=new CV_Builder();
                                c->putdata(fname,course,rollno);
                                c->show();
                                    this->hide();}
                          else{
                               QMessageBox::information(this,"","Error");
                                }
    }*/
        if(validate==1){

        // Fetching form data into Strings
           QString dob,phno,email;
           fname=ui->lineEdit_fname->text();
          lname=ui->lineEdit_lname->text();
          dob=ui->lineEdit_dob->text();
         rollno=ui->lineEdit_rno->text();
         course=ui->comboBox_course->currentText();
         phno=ui->lineEdit_number->text();
         email=ui->lineEdit_email->text();

            if(fname==""){
          QMessageBox::information(this,"Note","All Details are Not Filled ,Please Fill the Form");
    }

            // Registering the data into the Database
            if(!main.connOpen()){
                qDebug() <<"Database Not Connected";
            }

            else{
             QSqlQuery qry;
     qry.prepare("insert into Student(fname,lname,email,rollno,phno,course,dob,idno,username,password) values('"+fname+"','"+lname+"','"+email+"','"+rollno+"','"+phno+"','"+course+"','"+dob+"','"+id+"','"+username+"','"+password+"')");
        //    qry.prepare("insert into Student(fname,lname,email,rollno,phno) values('"+fname+"','"+lname+"','"+email+"','"+rollno+"','"+phno+"')");
                // new  ******************************* fname,lname,email,rollno,phno,course,dob,idno,username,password)
                if(qry.exec()){
                    QMessageBox::information(this,"Success","Details Successfully added to the Database");
                    CV_Builder *c=new CV_Builder();
                    c->putData(fname,lname,course,rollno,id);
                    c->show();
                        this->hide();
                }
                else{
                     QMessageBox::information(this,"Error","Details Not added to the Database");
                }

        }
        }
                // if Username , Pwd Not Checked
                else{
                    QMessageBox::information(this,"Validate","First Enter and Validate username and password");
                    }
    }



    void Student_Registration::on_pushButton_Validae_clicked()
    {
        // Getting Login Data
             int count=0;
            id=ui->lineEdit_IdCard->text();
            username=ui->lineEdit_newuname->text();
            password=ui->lineEdit_newpwd->text();
            passwordcheck=ui->lineEdit_repwd->text();
            // Checks if Pwd matches in Round 2



          if(password!=passwordcheck){
              QMessageBox::warning(this,"Pwd Match","The Password re-entered does not match with the original password");
          }

          else{
              QMessageBox::information(this,"Pwd Match","The Password matches with the original password");



          // Check if the Sign-Up Credentials Already exist in the System
          Welcome main;
          int userchk,idchk=0;
          if(main.connOpen()){
              QSqlQuery qry;
           //  qry.prepare("Select * from Student where idno='"+id+"',username='"+username+"' and password='"+password+"'");
            if(qry.exec("Select * from Student where idno='"+id+"'")){
                while(qry.next()){
                    count++;
                }
                if(count!=0){
                    QMessageBox::information(this,"InValid","This Id is already Registered");
                }
                else{ idchk=1; }

               }

                count=0;
              if(qry.exec("Select * from Student where username='"+username+"'")){

                           while(qry.next()){count++;}
                          if(count!=0){QMessageBox::information(this,"InValid","This UserName is already Registered");
                          }
                          else{ userchk=1; }
              }
                count=0;
            if(qry.exec("Select * from Student where password='"+password+"'"))
                    {
                        while(qry.next()){count++;}
                       if(count!=0){QMessageBox::information(this,"InValid","This Password is already Registered");
                       } }

               if(count==0 && idchk==1 && userchk==1){
                    QMessageBox::information(this,"Success","This Id-Username-Password combination is unique and can be used");
                    validate=1;
                }
                   }
                }
          }

                // Extra dummy Func
              /*  void Student_Registration::on_pushButtonValidate_clicked(){}
                void Student_Registration::on_pushButtonValidatepwd_clicked(){}*/




void Student_Registration::on_pushButton_Reset_clicked()
{
    ui->lineEdit_dob->setText(" ");
     ui->lineEdit_email->setText(" ");
      ui->lineEdit_fname->setText(" ");
       ui->lineEdit_IdCard->setText(" ");
        ui->lineEdit_lname->setText(" ");
         ui->lineEdit_newpwd->setText(" ");
          ui->lineEdit_newuname->setText(" ");
           ui->lineEdit_number->setText(" ");
             ui->lineEdit_repwd->setText(" ");
               ui->lineEdit_rno->setText(" ");
}
