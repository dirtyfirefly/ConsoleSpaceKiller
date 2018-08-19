#include "Roc.h"


// стрельба
bool Roc::shoot()
{
	if(arm.getAmt() >= 0)
		arm.shoot();
	return sh.shoot(arm.getAmt());
}

// отоброжение на экране
char Roc::getFace()
{
	return face;
}

//задаёт face  и hp
Roc::Roc()
{
	face = '^';
	hp.init(face);
}
Roc::~Roc()
{
}
