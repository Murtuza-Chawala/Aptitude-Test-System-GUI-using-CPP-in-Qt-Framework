#ifndef STUDENTMAIN_H
#define STUDENTMAIN_H

#include <QWidget>

namespace Ui {
class StudentMain;
}

class StudentMain : public QWidget
{
    Q_OBJECT

public:
    explicit StudentMain(QWidget *parent = 0);
    void putData(QString,QString,QString,QString,QString);
    QString course,fname,rollno,lname,idno;

    ~StudentMain();

private slots:
    void on_pushButton_test_clicked();

    void on_pushButton_cv_clicked();

    void on_pushButton_report_clicked();

    void on_pushButton_faq_clicked();

    void on_pushButton_home_clicked();

    void on_pushButton_profile_clicked();

    void on_pushButton_notice_clicked();

    void on_pushButton_Post_Notice_clicked();

private:
    Ui::StudentMain *ui;
};

#endif // STUDENTMAIN_H
