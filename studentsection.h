#ifndef STUDENTSECTION_H
#define STUDENTSECTION_H

#include <QDialog>

namespace Ui {
class studentsection;
}

class studentsection : public QDialog
{
    Q_OBJECT

public:
    explicit studentsection(QWidget *parent = 0);
    ~studentsection();

private slots:
    void on_pushButton_viewstudentdetails_clicked();

    void on_pushButton_postnotifications_clicked();

    void on_pushButton_viewcvdetails_clicked();

    void on_pushButton_viewtestdetails_clicked();

    void on_pushButton_postmeritlists_clicked();

    void on_pushButton_viewreports_clicked();

    void on_pushButton_gotohome_clicked();

    void on_pushButton_viewnotice_clicked();

    void on_pushButton_clicked();

private:
    Ui::studentsection *ui;
};

#endif // STUDENTSECTION_H
