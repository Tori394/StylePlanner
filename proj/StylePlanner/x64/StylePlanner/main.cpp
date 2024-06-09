#include "StylePlanner.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StylePlanner w;
    w.show();
    return a.exec();
}
