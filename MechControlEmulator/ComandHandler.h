#pragma once
#include <QThread>
#include <QTextStream>
#include <QIODevice>
#include <QtCore/QIODevice>
//#include <QtCore/QLocale>
#include <locale>
#include <QDebug>
#include <QRegularExpression>


#include "ControlSystem.h"

class ComandHandler :
    public QThread
{
    Q_OBJECT
    QTextStream *qout;       // Консольный вывод
    QTextStream *qin;        // Консольный ввод

    ControlSystem cs;        // система управления механизмом

public:
    ComandHandler();
    ~ComandHandler();

    void run();              // Цикл обработки команд

};

