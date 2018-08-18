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

// �������� ������ �����, ������ �� �������
// ������������� ����������� hp
// � score
Aster::Aster(int i)
{
	face = faces[i];
	fStep = true;
	arm = false;
	hp.init(face);
	score.init(face);
	damage = 1;
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
