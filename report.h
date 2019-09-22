#ifndef REPORT_H
#define REPORT_H

#include <QWidget>

namespace Ui {
class Report;
}

class Report : public QWidget
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = 0);
    void putData(int,int,int,QString);
    void putDetail(QString,QString,QString,QString,QString,QString,QString);
      public: QString fname,lname,course,rollno,idno,cname,jname;

   public: int qgrade,lgrade,vgrade,fscore,qscore,lscore,vscore,eligible;
        QString qsc,lsc,vsc,tsc;
    QString status;
    void Insert();
    void mainData(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);

    // Data for the Stud Main Form
    void retData(QString,QString,QString,QString,QString);
    ~Report();

private slots:
    void on_pushButton_Submit_clicked();

private:
    Ui::Report *ui;
};

#endif // REPORT_H
