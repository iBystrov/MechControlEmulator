#pragma once
#include <QThread>
#include <QTextStream>
#include <QIODevice>
#include <QtCore/QIODevice>
//#include <QtCore/QLocale>
#include <locale>
#include <QDebug>

#include "ControlSystem.h"

class ComandHandler :
    public QThread
{
    Q_OBJECT
    QTextStream *qout;       // Консольный вывод
    QTextStream *qin;        // Консольный ввод

    ControlSystem cs;
public:
    ComandHandler();
    ~ComandHandler();

    void run();

};

