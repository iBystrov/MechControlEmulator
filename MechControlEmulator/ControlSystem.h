#pragma once
#include "Mechanism.h"

// ������� ���������� ����������
class ControlSystem
{
	Mechanism mech;
public:
	ControlSystem();
	~ControlSystem();
	quint64 moveX(const qint64 &x);			// ���������� �� x �����. ���������� ��������� ����������� �� X
	quint64 moveY(const qint64 &y);			// ���������� �� y �����. ���������� ��������� ����������� �� Y
	QPair<qint64, qint64> getPosition() const;  // ���������� ������� ��������� �� ���� X � Y
};

