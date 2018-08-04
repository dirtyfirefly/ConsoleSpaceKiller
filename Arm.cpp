#include "Arm.h"

void Arm::regenAmt(bool flag)
{
	if (flag)
		amt = maxAmt;
}

int Arm::getAmt()
{
	return amt;
}

Arm::Arm()
{
	maxAmt = 10;
	amt = maxAmt;
}
Arm::~Arm()
{
}
