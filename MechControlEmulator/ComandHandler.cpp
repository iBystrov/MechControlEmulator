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
                printWrongComand();                     // то ввод был некорректен   
                continue;                               // дальше не идём, продолжаем со следующей итерации
            }
//            *qout << "Положение до перемещения(X, Y): " << Qt::flush;
//            printPosition();
//            *qout << "Перемещено на " 
//                  << cs.moveX(x)                        // Перемещение по X
//                  << " шагов по Х и 0 шагов по Y" << Qt::endl;
//            *qout << "Положение после перемещения(X, Y): " << Qt::flush;
//            emit logTracking(cs.getPosition());
//            printPosition();               
// 
            emit moveX(x);
            //emit getPosition();
            //wait(100);
        }
        else if (comand.startsWith("move y "))
        {
            comand = comand.sliced(7);                  
            bool ok;
            qint64 y = trunc(comand.toDouble(&ok));     
            if (!ok) {                                  
                printWrongComand();                    
                continue;                               
            }
//            *qout << "Положение до перемещения(X, Y): " << Qt::flush;
//            printPosition();
//            *qout << "Перемещено на 0 шагов по X и " 
//                  << cs.moveY(y)                        // Перемещение по Y
//                  << " шагов по Y" << Qt::endl;
//            *qout << "Положение после перемещения(X, Y): " << Qt::flush;
//            emit logTracking(cs.getPosition());
//            printPosition();

            emit moveY(y);

        }
        else if (!(comand.compare("get position")))
        {
            emit getPosition();
 //           printPosition();
        }
        else if (!(comand.compare("exit")))
        {
            break;
        }
        else {
            printWrongComand();
        }
        //*qout << ">: ";// << Qt::flush;
    }

    //this->quit();
    this->exit(0); 
}

void ComandHandler::printPosition(QString s)
{
    //*qout << cs.getPosition() << Qt::endl;
    *qout << "Текущее положение: " << s << Qt::endl;
}

void ComandHandler::printLastMoveX(quint64 x)
{
    *qout << "Перемещено на " << QString::number(x) << " шагов по X и 0 шагов по Y" << Qt::endl;
}

void ComandHandler::printLastMoveY(quint64 y)
{
    *qout << "Перемещено на 0 шагов по X и " << QString::number(y) << " шагов по Y" << Qt::endl;
}

void ComandHandler::printWrongComand()
{
    *qout << "Команда некорректна - попробуйте ещё раз" << Qt::endl;
}

ComandHandler::~ComandHandler()
{
    delete qout;
    delete qin;
}
