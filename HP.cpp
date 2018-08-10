#include "HP.h"

void HP::downHP()
{
	--hp;
}
void HP::upHP()
{
	++hp;
}
int HP::getHP()
{
	return hp;
}

HP::HP() : hp(1)
{
}
HP::HP(char ch)
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
HP::~HP()
{
}
