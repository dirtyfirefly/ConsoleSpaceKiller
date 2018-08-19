#include "Field.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//����� �� �����
void Field::show()
{
	for (int i = 0; i < H; i++)
	{
		cout << "|";
		for (int j = 0; j < L; j++)
		{
			//� �������� ���� ���� face 
			//���������� ������ ��� �����������
			//
			//��� NULL ��������������� ������
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
//����������� �������� �� ����
void Field::down()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//������� ������ ���� ������� �� ���� ����
			if (arr[i][j] && arr[i][j]->getArm() && i == 0)
			{
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
		}
	}
	//����������� �������� ����� �� 1 �������
	path.upMoveStd(arr);
	//������� ������� ���������� � �������
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			/*if (arr[i][j])
				arr[i][j]->fixF();*/
			//������� ��������
			if (i == H - 1 && arr[i][j])
			{
				//��������� ���� � ����� ������������ (29)
				if (arr[i][j] && !arr[i][j]->getArm())
				{
					//������ ����, �� �� ������
					lineAttack[j] = 1;
					//������ �������������� ���
					if (arr[i][j]->getHelper() &&
						arr[i][j]->getFace() == '!')	
						lineAttack[j] = 2;
					//������ �������������� hp
					if (arr[i][j]->getHelper() &&
						arr[i][j]->getFace() == '+')
						lineAttack[j] = 3;
				}
				else
					//������� �����
					lineAttack[j] = 0;
				//�������
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
		}
	}
	//����������� �������� ���� �� 1 �������
	path.downMoveStd(arr);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			//���������� ���� ����������� ������� ������� 
			//� ��������� ���������� � ������ �����������
			if (arr[i][j])
				arr[i][j]->fixF();
		}
	}
}
//��������� ��������� ���������
void Field::pos(int pos)
{
	int i = rand() % FACE;
	arr[0][pos] = new Aster(i);
}
//��������� �������
void Field::insertArm(int posArm)
{
	arr[H - 1][posArm] = new BlastArm();
}

//�������
int* Field::getLineAttack()
{
	return lineAttack;
}
int Field::getScore()
{
	return path.getScore();
}

//������ ������ ����
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
