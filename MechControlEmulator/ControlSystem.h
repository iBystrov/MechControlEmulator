#pragma once
#include "Mechanism.h"
#include <QString>

// Система управления механизмом
class ControlSystem
{
	Mechanism mech;

	// Пределы перемещения по осям 
	static const qint64 maxX = 20000;
	static const qint64 maxY = 20000;
	static const qint64 minX = -20000;
	static const qint64 minY = -20000;
public:
	ControlSystem();
	~ControlSystem();
	quint64 moveX(const qint64 &x);				// Перемещает на x шагов. Возвращает последнее перемещение по X
	quint64 moveY(const qint64 &y);				// Перемещает на y шагов. Возвращает последнее перемещение по Y
	QString getPosition() const;  // Возвращает текущее положение по осям X и Y
};

