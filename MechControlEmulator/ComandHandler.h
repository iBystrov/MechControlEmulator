#pragma once
#include <QThread>
#include <QTextStream>
#include <QIODevice>
#include <QtCore/QIODevice>
#include <locale>

#include <QCoreApplication>
#include "ControlSystem.h"

// Класс потока обработки ввода пользователя
class ComandHandler : public QThread
{
    Q_OBJECT
    QTextStream *qout;          // Консольный вывод
    QTextStream *qin;           // Консольный ввод

    ControlSystem cs;           // Система управления механизмом

    void printPosition();       // Вывод текущей позиции
    void printWrongCommand();   // Сообщение при некорректном вводе
signals:
    void logTracking(QString s);         // Запись в CSV-файл
public:
    ComandHandler();
    ~ComandHandler();

    void run();                 // Цикл обработки команд
};

