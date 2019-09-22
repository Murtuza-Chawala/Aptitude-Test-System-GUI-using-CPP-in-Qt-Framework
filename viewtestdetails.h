#ifndef VIEWTESTDETAILS_H
#define VIEWTESTDETAILS_H

#include <QDialog>

namespace Ui {
class viewtestdetails;
}

class viewtestdetails : public QDialog
{
    Q_OBJECT

public:
    explicit viewtestdetails(QWidget *parent = 0);
    ~viewtestdetails();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_gotohome_clicked();

    void on_btn_load_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::viewtestdetails *ui;
};

#endif // VIEWTESTDETAILS_H
