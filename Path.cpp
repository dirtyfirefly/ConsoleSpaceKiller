#include "Path.h"
#include <iostream>

//сдвиг вниз на 1 область
void Path::downMoveStd(Aster* arr[][L])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//проверка наличия объекта и его перемещений (флаг)
			//перемещение вниз
			if (arr[i][j] && arr[i][j]->getF() && !arr[i][j]->getArm())
			{
				//проверка объекта на пути
				if (boomWO.boomWithArm(arr[i + 1][j]) && 
					arr[i + 1][j]->getArm())
				{
					//снижение жизней объекта
					arr[i + 1][j]->hpDown(arr[i][j]);
					//снижение жизней снаряда
					arr[i][j]->hpDown(arr[i + 1][j]);
					//если уровень hp <= 0 удаляем
					if (arr[i + 1][j]->getHP() <= 0)
					{
						Aster* tmp = arr[i + 1][j];
						arr[i + 1][j] = NULL;
						delete tmp;
						/*std::cout << "del aster1" << std::endl;*/
						/*continue;*/
					}
					//если уровень hp <= 0 удаляем
					if (arr[i][j]->getHP() <= 0)
					{
						Aster* tmp = arr[i][j];
						arr[i][j] = NULL;
						delete tmp;
						/*std::cout << "del aster2" << std::endl;*/
						/*continue;*/
					}
				}
				if (arr[i][j])
				{
					//перемещаем если есть что
					arr[i + 1][j] = arr[i][j];
					arr[i + 1][j]->fixF();
					arr[i][j] = NULL;
				}
			}
		}
	}
}
//сдвиг вверх на 1 область
void Path::upMoveStd(Aster* arr[][L])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//проверка наличия объекта и его пренадлежности к снарядам (флаг)
			//перемещение вверх
			if (arr[i][j] && arr[i][j]->getArm())
			{
				//проверка объекта на пути и принодлежность к не снарядам
				if (boomWO.boomWithArm(arr[i - 1][j]) &&
					!arr[i - 1][j]->getArm())
				{
					//снижение жизней объекта
					arr[i - 1][j]->hpDown(arr[i][j]);
					//снижение жизней снаряда
					arr[i][j]->hpDown(arr[i - 1][j]);
					//если уровень hp <= 0 удаляем
					if (arr[i - 1][j]->getHP() <= 0)
					{
						Aster* tmp = arr[i - 1][j];
						arr[i - 1][j] = NULL;
						delete tmp;
						/*std::cout << "del aster" << std::endl;*/
						/*continue;*/
					}
					//если уровень hp <= 0 удаляем
					if (arr[i][j]->getHP() <= 0)
					{
						Aster* tmp = arr[i][j];
						arr[i][j] = NULL;
						delete tmp;
						/*std::cout << "del blast" << std::endl;*/
						/*continue;*/
					}
				}
				if (arr[i][j])
				{
					//перемещаем если есть что
					arr[i - 1][j] = arr[i][j];
					arr[i - 1][j]->fixF();
					arr[i][j] = NULL;
				}
			}
		}
	}
}

//
Path::Path()
{
}
Path::~Path()
{
}
