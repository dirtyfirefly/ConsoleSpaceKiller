#include "BlastArm.h"


// ������������� ���� arm
// ������������� face ��� |
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
