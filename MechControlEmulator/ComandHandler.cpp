#include "ComandHandler.h"

ComandHandler::ComandHandler()
{    
    setlocale(LC_ALL, "Russian");

    qout = new QTextStream(stdout, QIODevice::WriteOnly);   
    qin = new QTextStream(stdin, QIODevice::ReadOnly);        

    (*qout).setEncoding(QStringConverter::System);

    *qout << "Cистема управления механизмом приветствует вас! " << Qt::endl;
    *qout << "Команды управления: move x <val> | move y <val> | get position | exit " << Qt::endl;
}

void ComandHandler::run()
{
    QString comand{};
    *qout << "Введите команду>: " << Qt::flush;

    while ((*qin).readLineInto(&comand)) {              // Чтение строки из консоли

        if (comand.startsWith("move x "))               // Если начинается с "move x "
        {
            comand = comand.sliced(7);                  // отбрасываем "move x "
            bool ok;
            qint64 x = trunc(comand.toDouble(&ok));     // Преобразуем в double и отбрасываем дробь
            if (!ok) {                                  // Если преобразование не удалось
                printWrongCommand();                    // то ввод был некорректен   
                continue;                               // дальше не идём, продолжаем со следующей итерации
            }
            *qout << "Положение до перемещения(X, Y): " << Qt::flush;
            printPosition();
            *qout << "Перемещено на " 
                  << cs.moveX(x)                        // Перемещение по X
                  << " шагов по Х и 0 шагов по Y" << Qt::endl;
            *qout << "Положение после перемещения(X, Y): " << Qt::flush;
            emit logTracking(cs.getPosition());
            printPosition();                
        }
        else if (comand.startsWith("move y "))
        {
            comand = comand.sliced(7);                  
            bool ok;
            qint64 y = trunc(comand.toDouble(&ok));     
            if (!ok) {                                  
                printWrongCommand();                    
                continue;                               
            }
            *qout << "Положение до перемещения(X, Y): " << Qt::flush;
            printPosition();
            *qout << "Перемещено на 0 шагов по X и " 
                  << cs.moveY(y)                        // Перемещение по Y
                  << " шагов по Y" << Qt::endl;
            *qout << "Положение после перемещения(X, Y): " << Qt::flush;
            emit logTracking(cs.getPosition());
            printPosition();
        }
        else if (!(comand.compare("get position")))
        {
            printPosition();
        }
        else if (!(comand.compare("exit")))
        {
            break;
        }
        else {
            printWrongCommand();
        }
        *qout << ">: " << Qt::flush;
    }

    //this->quit();
    this->exit(0); 
}

void ComandHandler::printPosition()
{
    *qout << cs.getPosition() << Qt::endl;
}

void ComandHandler::printWrongCommand()
{
    *qout << "Команда некорректна - попробуйте ещё раз" << Qt::endl;
}

ComandHandler::~ComandHandler()
{
    delete qout;
    delete qin;
}
