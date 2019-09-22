#ifndef QUESTIONREASONING_H
#define QUESTIONREASONING_H

#include <QWidget>

namespace Ui {
class QuestionReasoning;
}

class QuestionReasoning : public QWidget
{
    Q_OBJECT
public: void nextQuestion();
 public: int flag=0,qno=0,userans=0,ans=0,mark=0;
 public: int right=0,wrong=0;
    int quantimarks,logicmarks=0;
        public: void putData(int);
            void putDetail(QString,QString,QString,QString,QString,QString,QString);
  public: QString fname,lname,course,rollno,idno,cname,jname;
            int iterate();
            int it=0;
            int i=0;
            int numm=0;
    public: int count=0;
            public: int a[8];
public:
    explicit QuestionReasoning(QWidget *parent = 0);

    ~QuestionReasoning();

private slots:
    void on_pushButton_Submitans_clicked();

    void on_ropt1_clicked();

    void on_ropt2_clicked();

    void on_ropt3_clicked();

    void on_ropt4_clicked();

    void on_pushButton_Skip_clicked();

    void on_pushButton_clicked();

private:
    Ui::QuestionReasoning *ui;
};

#endif // QUESTIONREASONING_H
