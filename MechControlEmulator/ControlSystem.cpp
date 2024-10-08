﻿#include "ControlSystem.h"

ControlSystem::ControlSystem()
{
	mech.x = 0;
	mech.y = 0;
	pos = "0,0";
}

void ControlSystem::moveX(qint64 x)
{
	quint64 dist{0};	// перемещение по Х (число шагов)

	if (x < 0)				// собираемся пойти "в минус" по X
	{
		if ((mech.x + x) >= minX)	// если целевая координата больше нижней границы по X
		{
			dist = qAbs(x);			// сохраняем число шагов
			mech.x = mech.x + x;	// перемещаем на x
		}
		else {								// иначе 
			dist = qAbs(minX - mech.x);		// число шагов до нижней границы
			mech.x = minX;					// перемещаем на нижнюю границу по X
		}
	}
	else if (x > 0)			// иначе идём "в плюс" по оси X
	{
		if ((mech.x + x) <= maxX)
		{
			dist = x;
			mech.x = mech.x + x;
		}
		else {
			dist = maxX - mech.x;
			mech.x = maxX;			
		}		
	}
	else					// иначе стоим на месте
		dist = 0;

	emit printLastMoveX(dist);		// Отправляем последнее перемещение в консоль
	updatePos();					// Обновляем текущую позицию
	emit logTracking(pos);			// Отправляем текущую позицию на запись в CSV-файл
	emit printPosition(pos);		// Отправляем текущую позицию на печать в консоль
}

void ControlSystem::moveY(qint64 y)
{
	quint64 dist{0};	

	if (y < 0)			
	{
		if ((mech.y + y) >= minY)	
		{
			dist = qAbs(y);		
			mech.y = mech.y + y;	
		}
		else {								
			dist = qAbs(minY - mech.y);	
			mech.y = minY;					
		}
	}
	else if (y > 0)			
	{
		if ((mech.y + y) <= maxY)
		{
			dist = y;
			mech.y = mech.y + y;
		}
		else {
			dist = maxY - mech.y;
			mech.y = maxY;
		}
	}
	else					
		dist = 0;

	emit printLastMoveY(dist);
	updatePos();
	emit logTracking(pos);
	emit printPosition(pos);
}

void ControlSystem::updatePos()
{
	pos = QString::number(mech.x) + "," + QString::number(mech.y);
}

void ControlSystem::getPosition()
{	
	emit printPosition(pos);		// Отправка текущей позиции в консоль
}

ControlSystem::~ControlSystem()
{

}

