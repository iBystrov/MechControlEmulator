#include "ControlSystem.h"

ControlSystem::ControlSystem()
{
	mech.x = 0;
	mech.y = 0;
}

quint64 ControlSystem::moveX(const qint64& x)
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

	return dist;	
}

quint64 ControlSystem::moveY(const qint64& y)
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

	return dist;
}

QString ControlSystem::getPosition() const
{
	QString str = QString::number(mech.x) + "," + QString::number(mech.y);
	return str;
}

ControlSystem::~ControlSystem()
{

}