#ifndef QUESTION_H
#define QUESTION_H

#include <QWidget>
#include "welcome.h"
namespace Ui {
class Question;
}

class Question : public QWidget
{
    Q_OBJECT
public: int flag=0,qno=0,userans=0,ans=0;
private: void nextQuestion();
public: int right=0,wrong=0;
        int marks=0;
       public: int a[8];
    public: QString fname,lname,course,rollno,idno,cname,jname;
        int iterate();
        void generate();
        QString num;
public: int numm,count=0,n=0;
        int i=0;
public:
    explicit Question(QWidget *parent = 0);
  public:  void putData(QString,QString,QString,QString,QString,QString,QString);
    public: int it=0,check=0;
    ~Question();

private slots:
    void on_pushButton_Submitans_clicked();

    void on_pushButton_clicked();

    void on_pushButton_Skip_clicked();

    void on_ropt1_clicked();

    void on_ropt2_clicked();

    void on_ropt3_clicked();

    void on_ropt4_clicked();

private:
    Ui::Question *ui;
};

#endif // QUESTION_H
