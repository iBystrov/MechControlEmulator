#pragma once
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>

class CsvWriter : public QObject
{
    Q_OBJECT
    QFile* file;                // Для вывода в CSV-файл
public:
    CsvWriter();
    ~CsvWriter();
public slots:
    void logTrackingSlot(QString s);
};

