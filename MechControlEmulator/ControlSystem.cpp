#include "ControlSystem.h"

ControlSystem::ControlSystem()
{
	//TODO: ��������� ��������� ��������� �� �����, ���� ��� �����, ��:
	mech.x = 0;
	mech.y = 0;
}

quint64 ControlSystem::moveX(const qint64& x)
{
	quint64 distX{0};
/*
	if (x < 0)				// ��� ����� �� ��� X
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


	if (x < 0)				// ���������� ����� � ����� �� X
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


	else if (x > 0)			// ����� ��� ������ �� ��� X
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
	else					// ����� ����� �� �����
		distX = 0;

	//TODO: ������ � ����
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