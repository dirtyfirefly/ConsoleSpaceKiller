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

Aster::Aster(int i)
{
	face = faces[i];
	fStep = true;
}
Aster::Aster()
{
	face = ' ';
	fStep = false;
}
Aster::~Aster()
{
}
