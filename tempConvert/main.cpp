#include "tempconvert.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tempConvert w;
    w.show();

    return a.exec();
}
