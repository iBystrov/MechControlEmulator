#include <QtCore/QCoreApplication>
#include <QObject>
#include "ComandHandler.h"
#include "CsvWriter.h"
#include "ControlSystem.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ControlSystem cs;       // Система управления механизмом
    ComandHandler ch;       // Поток обработки ввода пользователя 
    CsvWriter cw;           // Для записи в CSV-файл
                          
    // Сигнал завершения потока ввода команд завершит работу программы
    QObject::connect(&ch, SIGNAL(finished()), &a, SLOT(quit()));

    // Сигнал записи в CSV-файл текущей позиции механизма
    QObject::connect(&cs, SIGNAL(logTracking(QString)), &cw, SLOT(logTrackingSlot(QString)));             

    // Связывание сигналов-команд от ComandHandler со слотами-обработчиками ControlSystem
    QObject::connect(&ch, SIGNAL(moveX(qint64)), &cs, SLOT(moveX(qint64)));
    QObject::connect(&ch, SIGNAL(moveY(qint64)), &cs, SLOT(moveY(qint64)));
    QObject::connect(&ch, SIGNAL(getPosition()), &cs, SLOT(getPosition()));

    // Связывание сигналов от ControlSystem со слотами ComandHandler для печати в консоль
    QObject::connect(&cs, SIGNAL(printLastMoveX(quint64)), &ch, SLOT(printLastMoveX(quint64)));
    QObject::connect(&cs, SIGNAL(printLastMoveY(quint64)), &ch, SLOT(printLastMoveY(quint64)));
    QObject::connect(&cs, SIGNAL(printPosition(QString)), &ch, SLOT(printPosition(QString)));

    ch.start();      // Старт потока ввода команд (запускает ComandHandler::run())

    return a.exec();
}
