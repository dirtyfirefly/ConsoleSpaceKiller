#include "HP.h"

// ��������� hp
bool HP::downHP(int c)
{
	hp -= c;
	if (hp <= 0)
		return true;
	return false;
}
// ����������� hp
void HP::upHP(int c)
{
	hp += c;
	if (hp > 10)
		hp = 10;
}
// ������������� ���������� hp
// � ����������� �� face �������
void HP::init(char ch)
{
	switch (ch)
	{
	case '^':
		hp = 3;
		break;
	case '*':
		hp = 1;
		break;
	case 'T':
		hp = 2;
		break;
	default:
		hp = 1;
		break;
	}
}
//�����
int HP::getHP()
{
	return hp;
}

//hp == 1
HP::HP() : hp(1)
{
}
HP::~HP()
{
}
