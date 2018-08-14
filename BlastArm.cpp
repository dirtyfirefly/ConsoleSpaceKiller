#include "BlastArm.h"


// устанавливает флаг arm
// устанавливает face как |
BlastArm::BlastArm()
{
	arm = true;
	face = '|';
	hp.init(face);
	damage = 1;
}
BlastArm::~BlastArm()
{
}
