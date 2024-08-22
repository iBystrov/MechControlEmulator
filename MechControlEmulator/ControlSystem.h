#pragma once
#include "Mechanism.h"
#include <QString>
#include <QObject>

// Система управления механизмом
class ControlSystem : public QObject
{
	Q_OBJECT
	Mechanism mech;

	// Пределы перемещения по осям 
	static const qint64 maxX = 20000;
	static const qint64 maxY = 20000;
	static const qint64 minX = -20000;
	static const qint64 minY = -20000;

	QString pos;
	void updatePos();
public:
	ControlSystem();
	~ControlSystem();
signals:
	void printPosition(QString);       // Вывод текущей позиции
	void printLastMoveX(quint64);
	void printLastMoveY(quint64);

	void logTracking(QString);         // Запись в CSV-файл
public slots:
	void moveX(qint64 x);
	void moveY(qint64 y);
	void getPosition();
};

