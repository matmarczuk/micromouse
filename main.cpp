#include <QApplication>
#include "logic/micromouse.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Micromouse micromouse;

    return a.exec();
}
