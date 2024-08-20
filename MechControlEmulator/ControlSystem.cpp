#include "ControlSystem.h"

ControlSystem::ControlSystem()
{
	//TODO: ��������� ��������� ��������� �� �����, ���� ��� �����, ��:
	mech.x = 0;
	mech.y = 0;
}

quint64 ControlSystem::moveX(const qint64& x)
{
	quint64 dist{0};	// ����������� �� � (����� �����)

	if (x < 0)				// ���������� ����� "� �����" �� X
	{
		if ((mech.x + x) >= minX)	// ���� ������� ���������� ������ ������ ������� �� X
		{
			dist = qAbs(x);			// ��������� ����� �����
			mech.x = mech.x + x;	// ���������� �� x
		}
		else {								// ����� 
			dist = qAbs(minX - mech.x);		// ����� ����� �� ������ �������
			mech.x = minX;					// ���������� �� ������ ������� �� X
		}
	}
	else if (x > 0)			// ����� ��� "� ����" �� ��� X
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
	else					// ����� ����� �� �����
		dist = 0;

	//TODO: ������ � ����
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

	//TODO: ������ � ����
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