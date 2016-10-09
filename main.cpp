#pragma execution_character_set("utf-8")

#include "widget.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    a.setWindowIcon(QIcon("qt.ico"));
    w.show();
    w.setWindowTitle("Black and White v1.1");

    return a.exec();
}
