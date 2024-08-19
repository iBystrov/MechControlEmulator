#include "ControlSystem.h"

ControlSystem::ControlSystem()
{
	//TODO: Прочитать последнее положение из файла, если нет файла, то:
	mech.x = 0;
	mech.y = 0;
}

quint64 ControlSystem::moveX(const qint64& x)
{
	quint64 distX{0};
/*
	if (x < 0)				// идём влево по оси X
	{
		if ((mech.x + x) >= minX)
		{
			distX = qAbs(x);
			mech.x = mech.x - qAbs(x);//?
		}
		else {
			distX = Abs(minX) - mech.x;
			mech.x = minX;
		}		
	}
*/


	if (x < 0)				// собираемся пойти в минус по X
	{
		if ((mech.x + x) >= minX)
		{
			distX = qAbs(x);
			mech.x = mech.x + x;
		}
		else {
			distX = qAbs(minX - mech.x);
			mech.x = minX;		
		}
	}


	else if (x > 0)			// иначе идём вправо по оси X
	{
		if((mech.x + x) <= maxX)
		{
			distX = x;
			mech.x = mech.x + x;
		}
		else {
			distX = maxX - mech.x;
			mech.x = maxX;			
		}		
	}
	else					// иначе стоим на месте
		distX = 0;

	//TODO: запись в файл
	return distX;
}

quint64 ControlSystem::moveY(const qint64& y)
{
	quint64 distY{ 0 };

	return distY;
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