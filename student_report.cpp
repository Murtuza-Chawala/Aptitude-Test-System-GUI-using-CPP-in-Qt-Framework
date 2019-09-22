#include "student_report.h"
#include "ui_student_report.h"

Student_Report::Student_Report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Student_Report)
{
    ui->setupUi(this);
}

Student_Report::~Student_Report()
{
    delete ui;
}
