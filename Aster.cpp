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
int Aster::getScore()
{
	return score.getScore();
}
bool Aster::getHelper()
{
	return helper;
}

// выбирает иконку врагу, создаёт не снаряды
// устанавлевает колличество hp
// и score и damage и helper
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
