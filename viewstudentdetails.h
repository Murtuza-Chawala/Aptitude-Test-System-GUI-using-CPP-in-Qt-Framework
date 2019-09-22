#ifndef VIEWSTUDENTDETAILS_H
#define VIEWSTUDENTDETAILS_H

#include <QDialog>
#include "login.h"
namespace Ui {
class viewstudentdetails;
}

class viewstudentdetails : public QDialog
{
    Q_OBJECT

public:
    explicit viewstudentdetails(QWidget *parent = 0);
    ~viewstudentdetails();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_loadtable_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_gotohome_clicked();

    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::viewstudentdetails *ui;
};

#endif // VIEWSTUDENTDETAILS_H
