#include "Aster.h"

void Aster::fixF()
{
	fStep == 1 ? fStep = false : fStep = true;
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

Aster::Aster(int i)
{
	face = faces[i];
	fStep = true;
	arm = false;
}
Aster::Aster()
{
	face = ' ';
	fStep = false;
	arm = false;
}
Aster::~Aster()
{
}
