#ifndef VIEWREPORTS_H
#define VIEWREPORTS_H

#include <QDialog>

namespace Ui {
class viewreports;
}

class viewreports : public QDialog
{
    Q_OBJECT

public:
    explicit viewreports(QWidget *parent = 0);
    ~viewreports();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_gotohome_clicked();

    void on_pushButton_loadtablelist_clicked();

    void on_pushButton_loadTestReport_clicked();

    void on_pushButton_LoadCV_clicked();

    void on_pushButton_LoadCompany_clicked();

    void on_pushButton_clicked();

private:
    Ui::viewreports *ui;
};

#endif // VIEWREPORTS_H
