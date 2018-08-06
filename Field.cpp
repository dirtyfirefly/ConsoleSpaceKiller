#include "Field.h"
#include <iostream>
#include <Windows.h>

void Field::show()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 31; j++)
		{
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
void Field::down()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (arr[i][j] && i < 29 && arr[i][j]->getF())
			{
				arr[i + 1][j] = arr[i][j];
				arr[i + 1][j]->fixF();
				arr[i][j] = NULL;
			}
			if (arr[i][j] && arr[i][j]->getArm())
			{
				arr[i - 1][j] = arr[i][j];
				arr[i - 1][j]->fixF();
				arr[i][j] = NULL;
			}
		}
	}
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (arr[i][j])
				arr[i][j]->fixF();
			if (i == 29 && arr[i][j])
			{
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
			if (arr[i][j] && arr[i][j]->getArm() && i == 0)
			{
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
		}
	}
}
void Field::pos(int pos)
{
	int i = rand() % 5;
	arr[0][pos] = new Aster(i);
}
void Field::insertArm(int posArm)
{
	arr[29][posArm] = new BlastArm();
}

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
