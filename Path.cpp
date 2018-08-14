#include "Path.h"
#include <iostream>

//����� ���� �� 1 �������
void Path::downMoveStd(Aster* arr[][L])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//�������� ������� ������� � ��� ����������� (����)
			//����������� ����
			if (arr[i][j] && arr[i][j]->getF() && !arr[i][j]->getArm())
			{
				//�������� ������� �� ����
				if (boomWO.boomWithArm(arr[i + 1][j]) && 
					arr[i + 1][j]->getArm())
				{
					//�������� ������ �������
					arr[i + 1][j]->hpDown(arr[i][j]);
					//�������� ������ �������
					arr[i][j]->hpDown(arr[i + 1][j]);
					//���� ������� hp <= 0 �������
					if (arr[i + 1][j]->getHP() <= 0)
					{
						Aster* tmp = arr[i + 1][j];
						arr[i + 1][j] = NULL;
						delete tmp;
						/*std::cout << "del aster1" << std::endl;*/
						/*continue;*/
					}
					//���� ������� hp <= 0 �������
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
					//���������� ���� ���� ���
					arr[i + 1][j] = arr[i][j];
					arr[i + 1][j]->fixF();
					arr[i][j] = NULL;
				}
			}
		}
	}
}
//����� ����� �� 1 �������
void Path::upMoveStd(Aster* arr[][L])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//�������� ������� ������� � ��� �������������� � �������� (����)
			//����������� �����
			if (arr[i][j] && arr[i][j]->getArm())
			{
				//�������� ������� �� ���� � �������������� � �� ��������
				if (boomWO.boomWithArm(arr[i - 1][j]) &&
					!arr[i - 1][j]->getArm())
				{
					//�������� ������ �������
					arr[i - 1][j]->hpDown(arr[i][j]);
					//�������� ������ �������
					arr[i][j]->hpDown(arr[i - 1][j]);
					//���� ������� hp <= 0 �������
					if (arr[i - 1][j]->getHP() <= 0)
					{
						Aster* tmp = arr[i - 1][j];
						arr[i - 1][j] = NULL;
						delete tmp;
						/*std::cout << "del aster" << std::endl;*/
						/*continue;*/
					}
					//���� ������� hp <= 0 �������
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
					//���������� ���� ���� ���
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
