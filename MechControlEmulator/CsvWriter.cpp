#include "CsvWriter.h"

CsvWriter::CsvWriter()
{
	file = new QFile(QCoreApplication::applicationDirPath() + "/log.csv");  // Путь к CSV-файлу
}

CsvWriter::~CsvWriter()
{
    delete file;
}

void CsvWriter::logTrackingSlot(QString s)
{
    //Открытие либо создание CSV-файла, если его нет
    if (file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(file);      // Привязка к текстовому потоку
        QString str{};              // Подготовка строки для записи в файл
        str = s + "\n";
        out << str;                 // Вставка в текстовый поток 
        out.flush();                // Сброс на устройство (в файл)
        file->close();              // Закрытие файла
    }

}