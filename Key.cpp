#include "Key.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;


//пока просто заглушка
//отвечает за изменение стандартного набора клавишь управления
//может быть сбито врагом для реализации механики путанных клавишь
void Key::fixStandart()
{
}
//отслеживание нажатия клавишь
int Key::check()
{
	int tmp = 0;
	if (_kbhit())
	{
		tmp = _getch();
	}

	//возможные варианты нажатий
	switch ((char)tmp)
	{
	case (int)'A':	//перемещение влево
	case (int)'a':
	case (int)'4':
		if (posRoc == 0)	//если край поля, то стоит
			break;
		line[posRoc] = NULL;
		line[--posRoc] = &roc;
		break;
	case (int)'D':	//перемещение вправо
	case (int)'d':
	case (int)'6':
		if (posRoc == 30)	//если край поля, то стоит
			break;
		line[posRoc] = NULL;
		line[++posRoc] = &roc;
		break;
	case (int)' ':	//стрельба
		//если выстрелил, возвращает номер столбца
		if (roc.shoot())
			return posRoc;
		break;
	default:
		break;		
	}
	//если игрок не стрелял
	return -1;
}
//отоброжение на экран
void Key::show()
{
	//у каждого объекта есть поле face для его отоброжения на экран
	//для NULL облостей подразумевается пробел
	for (int i = 0; i < 31; i++)
	{
		if (line[i] == NULL)
			std::cout << " ";
		else
			std::cout << line[i]->getFace();
	}
}

//создаёт нижний ряд поля и устанавливает 
//ракету в его центр (14)
Key::Key()
{
	standart = 1;
	for (int i = 0; i < 31; i++)
	{
		line[i] = NULL;
	}
	line[14] = &roc;
	posRoc = 14;
}
Key::~Key()
{
}
