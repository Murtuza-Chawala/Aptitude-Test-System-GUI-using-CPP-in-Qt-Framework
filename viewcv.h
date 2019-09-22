#ifndef VIEWCV_H
#define VIEWCV_H

#include <QWidget>

namespace Ui {
class ViewCv;
}

class ViewCv : public QWidget
{
    Q_OBJECT

public:
    explicit ViewCv(QWidget *parent = 0);
    void putData(QString,QString,QString,QString,QString);
       QString course,fname,rollno,lname,idno;
    ~ViewCv();

private slots:
    void on_pushButton_Submit_clicked();

private:
    Ui::ViewCv *ui;
};

#endif // VIEWCV_H
