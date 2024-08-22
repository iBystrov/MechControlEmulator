#pragma once
#include <QThread>
#include <QTextStream>
#include <QIODevice>
#include <QtCore/QIODevice>
#include <locale>

// Класс потока обработки ввода пользователя
class ComandHandler : public QThread
{
    Q_OBJECT
    QTextStream *qout;          // Консольный вывод
    QTextStream *qin;           // Консольный ввод

    void printWrongComand();    // Сообщение при некорректном вводе

public:
    ComandHandler();
    ~ComandHandler();
    void run();                 // Цикл обработки команд
signals:
    void moveX(qint64);
    void moveY(qint64);
    void getPosition();
public slots:
    void printPosition(QString s);       // Вывод текущей позиции
    void printLastMoveX(quint64 x);
    void printLastMoveY(quint64 y);
};

