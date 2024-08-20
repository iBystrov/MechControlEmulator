#include "ComandHandler.h"

ComandHandler::ComandHandler()
{    
    setlocale(LC_ALL, "Russian");

    qout = new QTextStream(stdout, QIODevice::WriteOnly);   
    qin = new QTextStream(stdin, QIODevice::ReadOnly);        

    (*qout).setEncoding(QStringConverter::System);

    *qout << "Cистема управления механизмом приветствует вас! " << Qt::endl;
    *qout << "Команды управления: move x <val> | move y <val> | get position | exit " << Qt::endl;
    *qout << "Введите команду: " << Qt::flush;



}


void ComandHandler::run()
{
    QString comand;
    while ((*qin).readLineInto(&comand)) {
        //*qout << comand << Qt::endl;


        if (!(comand.compare("exit")))
        {
            break;
        }
    }

    //this->quit();
    this->exit(0); 
}

ComandHandler::~ComandHandler()
{
    delete qout;
    delete qin;
}