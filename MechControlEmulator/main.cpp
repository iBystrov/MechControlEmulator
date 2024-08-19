#include <QtCore/QCoreApplication>
#include <QtCore/QIODevice>
#include <QtCore/QLocale>

#include <locale>

QTextStream qout(stdout, QIODevice::WriteOnly);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setlocale(LC_ALL, "Russian");
    qout.setEncoding(QStringConverter::System);


    qout << "Cистема управления механизмом приветствует вас! " << Qt::endl;
//    qout << "Текущее положение: " << Qt::endl;
    qout << "Команды управления: move x <val> | move y <val> | get position | exit " << Qt::endl;
    qout << "Введите команду: " << Qt::endl;





    return a.exec();
}
