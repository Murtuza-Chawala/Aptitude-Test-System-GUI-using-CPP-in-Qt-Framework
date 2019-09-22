#ifndef STUDENT_REPORT_H
#define STUDENT_REPORT_H

#include <QWidget>

namespace Ui {
class Student_Report;
}

class Student_Report : public QWidget
{
    Q_OBJECT

public:
    explicit Student_Report(QWidget *parent = 0);
    ~Student_Report();

private:
    Ui::Student_Report *ui;
};

#endif // STUDENT_REPORT_H
