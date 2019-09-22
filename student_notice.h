#ifndef STUDENT_NOTICE_H
#define STUDENT_NOTICE_H

#include <QWidget>

namespace Ui {
class Student_Notice;
}

class Student_Notice : public QWidget
{
    Q_OBJECT

public:
    explicit Student_Notice(QWidget *parent = 0);
    ~Student_Notice();

private slots:
    void on_pushButton_load_clicked();

    void on_pushButton_home_clicked();

    void on_tableView_activated(const QModelIndex &index);

public:  void putData(QString,QString,QString,QString,QString);
       QString course,fname,rollno,lname,idno;

       void putDataAdmin();
       int user=0;

private:
    Ui::Student_Notice *ui;
};

#endif // STUDENT_NOTICE_H
