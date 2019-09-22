#ifndef STUDENT_REGISTRATION_H
#define STUDENT_REGISTRATION_H

#include <QWidget>

namespace Ui {
class Student_Registration;
}

class Student_Registration : public QWidget
{
    Q_OBJECT
      public: void accept();
public: int validate=0;
public:  QString password,passwordcheck,id,username,course,fname,rollno,lname,idno;

public:
    explicit Student_Registration(QWidget *parent = 0);
    ~Student_Registration();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_Submit_clicked();

    void on_pushButton_Validae_clicked();

    void on_pushButton_Validate_clicked();

    void on_pushButton_Validatepwd_clicked();

    void on_pushButton_Reset_clicked();

private:
    Ui::Student_Registration *ui;
};

#endif // STUDENT_REGISTRATION_H
