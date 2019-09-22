#ifndef STUDENT_LOGIN_H
#define STUDENT_LOGIN_H

#include <QWidget>

namespace Ui {
class Student_Login;
}

class Student_Login : public QWidget
{
    Q_OBJECT
public: QString fname,lname,course,rno,idno;

public:
    explicit Student_Login(QWidget *parent = 0);
    ~Student_Login();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_NewUser_clicked();

    void on_pushButton_Submit_clicked();

    void on_pushButton_Home_clicked();

    void on_pushButton_Reset_clicked();

    void on_pushButton_fpwd_clicked();

    void on_pushButton_HOME_clicked();

public slots:
    void timerr();

private:
    Ui::Student_Login *ui;
    QTimer *timer;
       int x=0;
};

#endif // STUDENT_LOGIN_H
