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

// выбирает иконку врагу, создаёт не снаряды
// устанавлевает колличество hp
// и score
Aster::Aster(int i)
{
	face = faces[i];
	fStep = true;
	arm = false;
	hp.init(face);
	score.init(face);
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
