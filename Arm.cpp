#include "Arm.h"

// востановление патронов до
// максимального количества 
void Arm::regenAmt()
{
		amt = maxAmt;
}
// отнимает 1 снаряд
void Arm::shoot()
{
	--amt;
}

//гетер
int Arm::getAmt()
{
	return amt;
}

// изначально устанавливает 10 патронов
Arm::Arm()
{
	maxAmt = AMU[0];
	amt = maxAmt;
}
Arm::~Arm()
{
}
