#include "ComandHandler.h"

ComandHandler::ComandHandler()
{    
    // Привязка текстовых потоков Qt к стандартным потокам ввода и вывода
    qout = new QTextStream(stdout, QIODevice::WriteOnly);   
    qin = new QTextStream(stdin, QIODevice::ReadOnly);        

    // Настройка консоли и потока вывода Qt для работы с кириллицей
    setlocale(LC_ALL, "Russian");
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
            emit moveX(x);                              // Отправка сигнала перемещения по Х 
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
            emit moveY(y);                              // Отправка сигнала перемещения по Y
        }
        else if (!(comand.compare("get position")))
        {
            emit getPosition();                         // Отправка сигнала запроса текущей позиции 
        }
        else if (!(comand.compare("exit")))
        {
            break;                                      // Выход из цикла ввода команд
        }
        else {
            printWrongComand();
        }
    }
    this->exit(0);                                      // Завершение потока
}

void ComandHandler::printPosition(QString s)
{
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
