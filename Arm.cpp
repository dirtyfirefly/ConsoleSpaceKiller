#include "Arm.h"

// ������������� �������� ��
// ������������� ���������� 
void Arm::regenAmt()
{
		amt = maxAmt;
}
// �������� 1 ������
void Arm::shoot()
{
	--amt;
}

//�����
int Arm::getAmt()
{
	return amt;
}

// ���������� ������������� 10 ��������
Arm::Arm()
{
	maxAmt = AMU[0];
	amt = maxAmt;
}
Arm::~Arm()
{
}
