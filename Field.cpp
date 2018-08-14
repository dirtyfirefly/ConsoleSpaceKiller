#include "Field.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//вывод на экран
void Field::show()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//у объектов есть поле face 
			//содержащее символ дл€ отоброжени€
			//
			//дл€ NULL подразумеваетс€ пробел
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
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//удал€ет сна€рд если долетел до кра€ пол€
			if (arr[i][j] && arr[i][j]->getArm() && i == 0)
			{
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
		}
	}
	//перемещение снар€дов вверх на 1 область
	path.upMoveStd(arr);
	//удал€ет объекты подошедшие к границе
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			/*if (arr[i][j])
				arr[i][j]->fixF();*/
			//удал€ет астеройд
			if (i == 29 && arr[i][j])
			{
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
			////удал€ет сна€рд
			//if (arr[i][j] && arr[i][j]->getArm() && i == 0)
			//{
			//	Aster* del = arr[i][j];
			//	arr[i][j] = NULL;
			//	delete del;
			//}
		}
	}
	//перемещение объектов вниз на 1 область
	path.downMoveStd(arr);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//возвращает флаг перемещени€ каждого объекта 
			//в состо€ние готовности к новому перемещению
			if (arr[i][j])
				arr[i][j]->fixF();
		}
	}
}
//рендомное по€вление астеройда
void Field::pos(int pos)
{
	int i = rand() % FACE;
	arr[0][pos] = new Aster(i);
}
//по€вление снар€да
void Field::insertArm(int posArm)
{
	arr[H - 1][posArm] = new BlastArm();
}

//создаЄт пустое поле
Field::Field()	
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			arr[i][j] = NULL;
		}
	}
}
Field::~Field()
{
}
