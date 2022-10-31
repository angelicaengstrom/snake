#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    srand(time(nullptr));
    QApplication a(argc, argv);
    Window w;

    w.show();

    return QApplication::exec();
}
