#include "Arm.h"

// востановление патронов до
// максимального количества 
void Arm::regenAmt(bool flag)
{
	if (flag)
		amt = maxAmt;
}

//гетер
int Arm::getAmt()
{
	return amt;
}

// изначально устанавливает 10 патронов
Arm::Arm()
{
	maxAmt = 10;
	amt = maxAmt;
}
Arm::~Arm()
{
}
