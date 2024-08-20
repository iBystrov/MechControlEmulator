#include "ControlSystem.h"

ControlSystem::ControlSystem()
{
	//TODO: ѕрочитать последнее положение из файла, если нет файла, то:
	mech.x = 0;
	mech.y = 0;
}

quint64 ControlSystem::moveX(const qint64& x)
{
	quint64 dist{0};	// перемещение по ’ (число шагов)

	if (x < 0)				// собираемс€ пойти "в минус" по X
	{
		if ((mech.x + x) >= minX)	// если целева€ координата больше нижней границы по X
		{
			dist = qAbs(x);			// сохран€ем число шагов
			mech.x = mech.x + x;	// перемещаем на x
		}
		else {								// иначе 
			dist = qAbs(minX - mech.x);		// число шагов до нижней границы
			mech.x = minX;					// перемещаем на нижнюю границу по X
		}
	}
	else if (x > 0)			// иначе идЄм "в плюс" по оси X
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

	//TODO: запись в файл
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

	//TODO: запись в файл
	return dist;
}

QPair<qint64, qint64> ControlSystem::getPosition() const
{
	QPair<qint64, qint64> pos{};
	pos.first = mech.x;
	pos.second = mech.y;
	return pos;
}

ControlSystem::~ControlSystem()
{

}