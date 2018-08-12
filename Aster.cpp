#include "Aster.h"

//поднимает либо опускает флаг
void Aster::fixF()
{
	fStep == 1 ? fStep = false : fStep = true;
}

//гетеры
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

// выбирает иконку врагу, создаёт не снаряды
Aster::Aster(int i)
{
	face = faces[i];
	fStep = true;
	arm = false;
	hp.init(face);
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
