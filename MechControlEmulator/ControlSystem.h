#pragma once
#include "Mechanism.h"

// ������� ���������� ����������
class ControlSystem
{
	Mechanism mech;

	// ������� ����������� �� ���� 
	static const qint64 maxX = 20000;
	static const qint64 maxY = 20000;
	static const qint64 minX = -20000;
	static const qint64 minY = -20000;
public:
	ControlSystem();
	~ControlSystem();
	quint64 moveX(const qint64 &x);				// ���������� �� x �����. ���������� ��������� ����������� �� X
	quint64 moveY(const qint64 &y);				// ���������� �� y �����. ���������� ��������� ����������� �� Y
	QPair<qint64, qint64> getPosition() const;  // ���������� ������� ��������� �� ���� X � Y
};

