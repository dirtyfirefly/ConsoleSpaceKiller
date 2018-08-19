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
	case (int)'5':
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
	cout << "|";
	//у каждого объекта есть поле face для его отоброжения на экран
	//
	//для NULL облостей подразумевается пробел
	for (int i = 0; i < L; i++)
	{
		if (line[i] == NULL)
			std::cout << " ";
		else
			std::cout << line[i]->getFace();
	}
	cout << "|";
}
// проверяте сталкновение ракеты
void Key::boomRocet(int* lineAttack)
{
	for (int i = 0; i < L; i++)
	{
		//проверяем на сталкновение
		//уменьшаем жизни если да
		if (lineAttack[i] == 1 && i == posRoc)
			roc.hp.downHP(DMG[0]);
		if (lineAttack[i] == 2 && i == posRoc)
			roc.arm.regenAmt();
		if (lineAttack[i] == 3 && i == posRoc)
			roc.hp.upHP(1);
		lineAttack[i] = 0;
	}
}
//отоброжает состояние ракеты
void Key::showR(int score)
{
	cout << endl;
	for (int i = 0; i < L+2; i++)
		cout << "#";
	cout << endl << "| life: " << roc.hp.getHP() << "| \t "
		<< "     | arm: ";
	if (roc.arm.getAmt() > 0)
		cout << roc.arm.getAmt();
	else
		cout << "0";
	cout << " |" << endl
		<< "\t  | score: " << score << " |" << endl;
	for (int i = 0; i < L + 2; i++)
		cout << "#";

	cout << endl << " ! (+arm)" << endl << " + (+hp)" << endl;
}

//геттер
Roc Key::getRoc()
{
	return roc;
}

//создаёт нижний ряд поля и устанавливает 
//ракету в его центр (L / 2)
Key::Key()
{
	standart = 1;
	for (int i = 0; i < L; i++)
	{
		line[i] = NULL;
	}
	line[L / 2] = &roc;
	posRoc = L / 2;
}
Key::~Key()
{
}
