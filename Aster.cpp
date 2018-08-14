#include "Aster.h"

//поднимает либо опускает флаг
void Aster::fixF()
{
	fStep == true ? fStep = false : fStep = true;
}
void Aster::hpDown(Aster* ptr)
{
	 hp.downHP(ptr->getDamage());
}

//гетеры
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

// выбирает иконку врагу, создаёт не снаряды
Aster::Aster(int i)
{
	face = faces[i];
	fStep = true;
	arm = false;
	hp.init(face);
	damage = 1;
}
// зачем-то создаёт пустой неподвижный объект
Aster::Aster()
{
	face = ' ';
	fStep = false;
	arm = false;
}
Aster::~Aster()
{
}
