#include "Roc.h"


// ��������
bool Roc::shoot()
{
	if(arm.getAmt() >= 0)
		arm.shoot();
	return sh.shoot(arm.getAmt());
}

// ����������� �� ������
char Roc::getFace()
{
	return face;
}

//����� face  � hp
Roc::Roc()
{
	face = '^';
	hp.init(face);
}
Roc::~Roc()
{
}
