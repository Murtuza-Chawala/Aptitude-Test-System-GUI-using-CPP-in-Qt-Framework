#include "welcome.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Welcome *t=new Welcome();
    t->show();

    return a.exec();
}
