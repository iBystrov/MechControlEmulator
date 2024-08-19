#include <QtCore/QCoreApplication>
#include <QtCore/QIODevice>
#include <QtCore/QLocale>

#include <locale>

#include "ControlSystem.h"

QTextStream qout(stdout, QIODevice::WriteOnly);
QTextStream qin(stdin, QIODevice::ReadOnly);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setlocale(LC_ALL, "Russian");
    qout.setEncoding(QStringConverter::System);

    ControlSystem cs;

    qout << "Cистема управления механизмом приветствует вас! " << Qt::endl;
//    qout << "Текущее положение: " << Qt::endl;
    qout << "Команды управления: move x <val> | move y <val> | get position | exit " << Qt::endl;
    qout << "Введите команду: " << Qt::flush;
    


    /*
    QString comand;
    while (qin.readLineInto(&comand)) {
        qout << comand << Qt::endl;
    }
*/


   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(100);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(-101);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(-20000);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(-20202);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(50000);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(-10000);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(0);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(200);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(300);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;
   cs.moveX(-100);
   qout << cs.getPosition().first << " " << cs.getPosition().second << Qt::endl;



    return a.exec();
}
