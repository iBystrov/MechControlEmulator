#pragma once
#include "Mechanism.h"
#include <QString>
#include <QObject>

// Система управления механизмом
class ControlSystem : public QObject
{
	Q_OBJECT
	Mechanism mech;						// Состояние механизма

	// Пределы перемещения по осям 
	static const qint64 maxX = 20000;
	static const qint64 maxY = 20000;
	static const qint64 minX = -20000;
	static const qint64 minY = -20000;

	QString pos;					   // Строковое представление позиции
	void updatePos();				   // Обновляет pos после перемещения
public:
	ControlSystem();
	~ControlSystem();
signals:
	void printPosition(QString);       // Для передачи позиции в консоль
	void printLastMoveX(quint64);	   // Для передачи перемещения по X в консоль
	void printLastMoveY(quint64);	   // Для передачи перемещения по Y в консоль

	void logTracking(QString);         // Запись позиции в CSV-файл
public slots:
	void moveX(qint64 x);			   // Обработка команды перемещения по X
	void moveY(qint64 y);			   // Обработка команды перемещения по Y
	void getPosition();                // Обработка запроса текущей позиции
};

