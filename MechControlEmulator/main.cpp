#include <QtCore/QCoreApplication>
#include <QObject>
#include "ComandHandler.h"
#include "CsvWriter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ComandHandler ch; 
    CsvWriter cw;
                          // Поток обработки ввода пользователя 

    QObject::connect(&ch, SIGNAL(finished()),   // Сигнал завершения потока ввода команд 
                      &a, SLOT(quit()));        // завершит работу программы

    QObject::connect(&ch, SIGNAL(logTracking(QString)),   // Сигнал завершения потока ввода команд 
        &cw, SLOT(logTrackingSlot(QString)));        // завершит работу программы


    ch.start();                                 // Старт потока ввода команд (запускает ComandHandler::run())

    return a.exec();
}
