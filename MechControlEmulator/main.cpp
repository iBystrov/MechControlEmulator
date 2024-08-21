#include <QtCore/QCoreApplication>
#include <QObject>
#include "ComandHandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ComandHandler ch;                           // Поток обработки ввода пользователя 

    QObject::connect(&ch, SIGNAL(finished()),   // Сигнал завершения потока ввода команд 
                      &a, SLOT(quit()));        // завершит работу программы

    ch.start();                                 // Старт потока ввода команд (запускает ComandHandler::run())

    return a.exec();
}
