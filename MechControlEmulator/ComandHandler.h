#pragma once
#include <QThread>
#include <QTextStream>
#include <QIODevice>
#include <QtCore/QIODevice>
//#include <QtCore/QLocale>
#include <locale>
#include <QFile>
#include <QCoreApplication>

#include "ControlSystem.h"

// Класс потока обработки ввода пользователя
class ComandHandler : public QThread
{
    Q_OBJECT
    QTextStream *qout;          // Консольный вывод
    QTextStream *qin;           // Консольный ввод

    QFile* file;                // Для вывода в CSV-файл

    ControlSystem cs;           // Система управления механизмом

    void printPosition();       // Вывод текущей позиции
    void printWrongCommand();   // Сообщение при некорректном вводе

    void logTracking();         // Запись в CSV-файл
public:
    ComandHandler();
    ~ComandHandler();

    void run();                 // Цикл обработки команд
};

