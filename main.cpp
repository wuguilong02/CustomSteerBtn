#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    libgcc_s_seh-1.dll
//    libstdc++-6.dll
    return a.exec();
}
