#include "Roc.h"

bool Roc::shoot()
{
	return sh.shoot(arm.getAmt());
}
char Roc::getFace()
{
	return face;
}

Roc::Roc()
{
	face = '^';
}
Roc::~Roc()
{
}
