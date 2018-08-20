#include "HP.h"

// ��������� hp
void HP::downHP(int c)
{
	hp -= c;
}
// ����������� hp
void HP::upHP(int c)
{
	hp += c;
	if (hp > MAXHP)
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
	case 'O':
		hp = 3;
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
