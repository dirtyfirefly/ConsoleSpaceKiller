#include "Key.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;


void Key::fixStandart()
{
}
void Key::check(bool& i)
{
	int tmp = 0;
	if (_kbhit())
	{
		tmp = _getch();
	}

	switch ((char)tmp)
	{
	case (int)'4':
		line[rocet] = ' ';
		line[--rocet] = '^';
		break;
	case (int)'6':
		line[rocet] = ' ';
		line[++rocet] = '^';
		break;
	case (int)' ':
		i = 1;
		break;
	default:
		break;	
	}
}
void Key::show()
{
	for (int i = 0; i < 31; i++)
	{
		std::cout << line[i];
	}
}

Key::Key()
{
	standart = 1;
	for (int i = 0; i < 31; i++)
	{
		line[i] = ' ';
	}
	line[14] = '^';
	rocet = 14;
}
Key::~Key()
{
}

