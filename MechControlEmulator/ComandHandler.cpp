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

    while ((*qin).readLineInto(&comand)) {

        if (comand.startsWith("move x "))
        {
            comand = comand.sliced(7);
            bool ok;
            qint64 x = trunc(comand.toDouble(&ok));
            if (!ok) {
                *qout << "Команда некорректна - попробуйте ещё раз" << Qt::endl;
                continue;
            }
            *qout << "Положение до перемещения(X, Y): " << cs.getPosition().first << ", " << cs.getPosition().second << Qt::endl;
            *qout << "Перемещено на " << cs.moveX(x) << " шагов по Х и 0 шагов по Y" << Qt::endl;
            *qout << "Положение после перемещения(X, Y): " << cs.getPosition().first << ", " << cs.getPosition().second << Qt::endl;
        }
        else if (comand.startsWith("move y "))
        {
            ;
        }
        else if (!(comand.compare("get position")))
        {
            *qout << cs.getPosition().first << ", " << cs.getPosition().second << Qt::endl;
            
        }
        else if (!(comand.compare("exit")))
        {
            break;
        }
        else {
            *qout << "Команда некорректна - попробуйте ещё раз" << Qt::endl;
        }
        *qout << ">: " << Qt::flush;
    }

    //this->quit();
    this->exit(0); 
}

ComandHandler::~ComandHandler()
{
    delete qout;
    delete qin;
}