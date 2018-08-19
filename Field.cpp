#include "Field.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//вывод на экран
void Field::show()
{
	for (int i = 0; i < H; i++)
	{
		cout << "|";
		for (int j = 0; j < L; j++)
		{
			//у объектов есть поле face 
			//содержащее символ для отоброжения
			//
			//для NULL подразумевается пробел
			if(arr[i][j] == NULL)
				std::cout << " ";
			else
			{
				std::cout << arr[i][j]->getFace();
			}
		}
		std::cout << "|" << std::endl;
	}
}
//перемещение объектов на поле
void Field::down()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//удаляет снаярд если долетел до края поля
			if (arr[i][j] && arr[i][j]->getArm() && i == 0)
			{
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
		}
	}
	//перемещение снарядов вверх на 1 область
	path.upMoveStd(arr);
	//удаляет объекты подошедшие к границе
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			/*if (arr[i][j])
				arr[i][j]->fixF();*/
			//удаляет астеройд
			if (i == H - 1 && arr[i][j])
			{
				//заполняет инфо о линии сталкновения (29)
				if (arr[i][j] && !arr[i][j]->getArm())
				{
					//объект есть, он не снаряд
					lineAttack[j] = 1;
					//объект востанавливает арм
					if (arr[i][j]->getHelper() &&
						arr[i][j]->getFace() == '!')	
						lineAttack[j] = 2;
					//объетк востанавливает hp
					if (arr[i][j]->getHelper() &&
						arr[i][j]->getFace() == '+')
						lineAttack[j] = 3;
				}
				else
					//область пуста
					lineAttack[j] = 0;
				//удаляет
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
		}
	}
	//перемещение объектов вниз на 1 область
	path.downMoveStd(arr);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//возвращает флаг перемещения каждого объекта 
			//в состояние готовности к новому перемещению
			if (arr[i][j])
				arr[i][j]->fixF();
		}
	}
}
//рендомное появление астеройда
void Field::pos(int pos)
{
	int i = rand() % FACE;
	arr[0][pos] = new Aster(i);
}
//появление снаряда
void Field::insertArm(int posArm)
{
	arr[H - 1][posArm] = new BlastArm();
}

//геттеры
int* Field::getLineAttack()
{
	return lineAttack;
}
int Field::getScore()
{
	return path.getScore();
}

//создаёт пустое поле
Field::Field()	
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			arr[i][j] = NULL;
		}
	}
	for (int i = 0; i < L; i++)
	{
		lineAttack[i] = false;
	}
}
Field::~Field()
{
}
