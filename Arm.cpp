#include "Arm.h"

// ������������� �������� ��
// ������������� ���������� 
void Arm::regenAmt(bool flag)
{
	if (flag)
		amt = maxAmt;
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
