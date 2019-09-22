#ifndef POSTVACANCY_H
#define POSTVACANCY_H

#include <QDialog>
#include"login.h"

namespace Ui {
class postvacancy;
}

class postvacancy : public QDialog
{
    Q_OBJECT

public:
    explicit postvacancy(QWidget *parent = 0);
    ~postvacancy();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_loadtable_clicked();

    void on_pushButton_post_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_gotohome_clicked();

    void on_check_clicked();

    void on_pushButton_clicked();

private:
    Ui::postvacancy *ui;
};

#endif // POSTVACANCY_H
