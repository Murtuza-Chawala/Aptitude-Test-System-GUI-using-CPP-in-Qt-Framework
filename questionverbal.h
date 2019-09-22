#ifndef QUESTIONVERBAL_H
#define QUESTIONVERBAL_H

#include <QWidget>

namespace Ui {
class QuestionVerbal;
}

class QuestionVerbal : public QWidget
{
    Q_OBJECT
public: void nextQuestion();
 public: int flag=0,qno=0,userans=0,ans=0;
 public: int right=0,wrong=0;
       public:     int quantimark,logicmark=0;
  public:  int verbmarks=0;
public: void putData(int,int);
        void putDetail(QString,QString,QString,QString,QString,QString,QString);
      public: QString fname,lname,course,rollno,idno,cname,jname;
        int iterate();
public: int numm,count=0;
        public: int a[8];
        int it=0;
        int i=0;
public:
    explicit QuestionVerbal(QWidget *parent = 0);
    ~QuestionVerbal();

private slots:
    void on_pushButton_Submitans_clicked();

    void on_rop1_clicked();

    void on_rop2_clicked();

    void on_rop3_clicked();

    void on_rop4_clicked();

    void on_pushButton_Skip_clicked();

private:
    Ui::QuestionVerbal *ui;
};

#endif // QUESTIONVERBAL_H
