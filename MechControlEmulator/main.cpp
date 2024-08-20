#include <QtCore/QCoreApplication>
#include <QtCore/QIODevice>
#include <QtCore/QLocale>

#include <locale>

#include "ControlSystem.h"

QTextStream qout(stdout, QIODevice::WriteOnly);     // Консольный вывод
QTextStream qin(stdin, QIODevice::ReadOnly);        // Консольный ввод

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setlocale(LC_ALL, "Russian");
    qout.setEncoding(QStringConverter::System);

    ControlSystem cs;

    qout << "Cистема управления механизмом приветствует вас! " << Qt::endl;
    qout << "Команды управления: move x <val> | move y <val> | get position | exit " << Qt::endl;
    qout << "Введите команду: " << Qt::flush;
    

/*  

    QString comand;
    while (qin.readLineInto(&comand)) {
        qout << comand << Qt::endl;

        if (!comand.compare("exit"))
        {
            a.quit();

        }

    }

*/  




    return a.exec();
}
