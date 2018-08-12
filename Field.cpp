#include "Field.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//вывод на экран
void Field::show()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			//у объектов есть поле face 
			//содержащее символ для отоброжения
			//для NULL подразумевается пробел
			if(arr[i][j] == NULL)
				std::cout << " ";
			else
			{
				std::cout << arr[i][j]->getFace();
			}
		}
		std::cout << std::endl;
	}
}
//перемещение объектов на поле
void Field::down()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			//проверка наличия объекта и его перемещений (флаг)
			//перемещение вниз
			if (arr[i][j] && i < 29 && arr[i][j]->getF())
			{
				arr[i + 1][j] = arr[i][j];
				arr[i + 1][j]->fixF();
				arr[i][j] = NULL;
			}
			//проверка наличия объекта и его пренадлежности к снарядам (флаг)
			//перемещение вверх
			if (arr[i][j] && arr[i][j]->getArm())
			{
				arr[i - 1][j] = arr[i][j];
				arr[i - 1][j]->fixF();
				arr[i][j] = NULL;
			}
		}
	}
	//возвращает флаг перемещения каждого объекта 
	//в состояние готовности к новому перемещению
	//удаляет объекты подошедшие к границе
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (arr[i][j])
				arr[i][j]->fixF();
			//удаляет астеройд
			if (i == 29 && arr[i][j])
			{
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
			//удаляет снаярд
			if (arr[i][j] && arr[i][j]->getArm() && i == 0)
			{
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
		}
	}
}
//рендомное появление астеройда
void Field::pos(int pos)
{
	int i = rand() % 5;
	arr[0][pos] = new Aster(i);
}
//появление снаряда
void Field::insertArm(int posArm)
{
	arr[29][posArm] = new BlastArm();
}

//создаёт пустое поле
Field::Field()	
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			arr[i][j] = NULL;
		}
	}
}
Field::~Field()
{
}
