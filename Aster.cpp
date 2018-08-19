#include "Aster.h"

//��������� ���� �������� ����
void Aster::fixF()
{
	fStep == true ? fStep = false : fStep = true;
}
void Aster::hpDown(Aster* ptr)
{
	 hp.downHP(ptr->getDamage());
}

//������
int Aster::getDamage()
{
	return damage;
}
bool Aster::getF()
{
	return fStep;
}
char Aster::getFace()
{
	return face;
}
bool Aster::getArm()
{
	return arm;
}
int Aster::getHP()
{
	return hp.getHP();
}
int Aster::getScore()
{
	return score.getScore();
}
bool Aster::getHelper()
{
	return helper;
}

// �������� ������ �����, ������ �� �������
// ������������� ����������� hp
// � score � damage � helper
Aster::Aster(int i)
{
	face = faces[i];
	fStep = true;
	arm = false;
	hp.init(face);
	score.init(face);
	damage = 1;
	if (face == faces[5] || face == faces[6])
	{
		helper = true;
		damage = 0;
	}
	else
		helper = false;
}
// �����-�� ������ ������ ����������� ������
Aster::Aster()
{
	face = ' ';
	fStep = false;
	arm = false;
}
Aster::~Aster()
{
}
