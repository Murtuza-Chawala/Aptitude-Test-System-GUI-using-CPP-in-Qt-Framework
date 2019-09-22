#ifndef POSTMERITLIST_H
#define POSTMERITLIST_H

#include <QDialog>

namespace Ui {
class postmeritlist;
}

class postmeritlist : public QDialog
{
    Q_OBJECT

public:
    explicit postmeritlist(QWidget *parent = 0);
    ~postmeritlist();

private slots:
    void on_btn_close_clicked();

    void on_pushButton_gotohome_2_clicked();

    void on_btn_meritlist_clicked();

    void on_comboBox_cname_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::postmeritlist *ui;
};

#endif // POSTMERITLIST_H
