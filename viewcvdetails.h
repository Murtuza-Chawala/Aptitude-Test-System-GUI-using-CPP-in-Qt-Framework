#ifndef VIEWCVDETAILS_H
#define VIEWCVDETAILS_H

#include <QDialog>
#include "login.h"

namespace Ui {
class viewcvdetails;
}

class viewcvdetails : public QDialog
{
    Q_OBJECT

public:
    explicit viewcvdetails(QWidget *parent = 0);
    ~viewcvdetails();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_loadtable_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_gotohome_clicked();

    void on_pushButton_clicked();

private:
    Ui::viewcvdetails *ui;
};

#endif // VIEWCVDETAILS_H
