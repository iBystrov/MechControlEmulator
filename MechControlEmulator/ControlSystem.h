#pragma once
#include "Mechanism.h"

// Система управления механизмом
class ControlSystem
{
	Mechanism mech;
public:
	ControlSystem();
	~ControlSystem();
	quint64 moveX(const qint64 &x);			// Перемещает на x шагов. Возвращает последнее перемещение по X
	quint64 moveY(const qint64 &y);			// Перемещает на y шагов. Возвращает последнее перемещение по Y
	QPair<qint64, qint64> getPosition() const;  // Возвращает текущее положение по осям X и Y
};

