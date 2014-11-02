#include "cameral_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cameral_window w;
    w.show();

    return a.exec();
}
