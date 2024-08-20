#include <QtCore/QCoreApplication>
#include <QObject>
#include "ComandHandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ComandHandler ch;
    QObject::connect(&ch, SIGNAL(finished()), &a, SLOT(quit()));
    ch.start();

    return a.exec();
}
