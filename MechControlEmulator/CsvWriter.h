#pragma once
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>

// Класс для записи в CSV-файл
class CsvWriter : public QObject
{
    Q_OBJECT
    QFile* file;                        // Для вывода в CSV-файл
public:
    CsvWriter();
    ~CsvWriter();
public slots:
    void logTrackingSlot(QString s);    // Слот записи в CSV-файл
};

