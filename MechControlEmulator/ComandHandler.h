#pragma once
#include <QThread>
#include <QTextStream>
#include <QIODevice>
#include <locale>

// Класс потока обработки ввода пользователя
class ComandHandler : public QThread
{
    Q_OBJECT
    QTextStream *qout;                  // Консольный вывод
    QTextStream *qin;                   // Консольный ввод

    void printWrongComand();            // Сообщение при некорректном вводе
public:
    ComandHandler();
    ~ComandHandler();
    void run();                         // Цикл обработки команд
signals:
    void moveX(qint64);                 // Команда перемещения по X
    void moveY(qint64);                 // Команда перемещения по Y
    void getPosition();                 // Запрос текущей позиции
public slots:
    void printPosition(QString s);      // Печать текущей позиции
    void printLastMoveX(quint64 x);     // Печать текущей перемещения по X в консоль
    void printLastMoveY(quint64 y);     // Печать текущей перемещения по Y в консоль
};

