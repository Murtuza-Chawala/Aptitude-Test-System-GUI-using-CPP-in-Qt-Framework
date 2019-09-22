#ifndef TAKE_TEST_H
#define TAKE_TEST_H

#include <QWidget>

namespace Ui {
class Take_Test;
}

class Take_Test : public QWidget
{
    Q_OBJECT
   public: QString coursename;

public:
    explicit Take_Test(QWidget *parent = 0);
    void putData(QString,QString,QString,QString,QString);
     QString course,fname,rollno,lname,idno;
     QString cname,jname;
    ~Take_Test();

private slots:
    void on_pushButton_2_clicked();

    void on_radioButtonc1_clicked();

    void on_radioButtonc2_clicked();

    void on_pushButton_Submit_clicked();

    void on_pushButton_Generate_clicked();

    void on_comboBox_cname_currentIndexChanged(const QString &arg1);

private:
    Ui::Take_Test *ui;
};

#endif // TAKE_TEST_H
