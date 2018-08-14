#include "Field.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//����� �� �����
void Field::show()
{
	for (int i = 0; i < H; i++)
	{
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
		std::cout << std::endl;
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
			if (i == 29 && arr[i][j])
			{
				Aster* del = arr[i][j];
				arr[i][j] = NULL;
				delete del;
			}
			////������� ������
			//if (arr[i][j] && arr[i][j]->getArm() && i == 0)
			//{
			//	Aster* del = arr[i][j];
			//	arr[i][j] = NULL;
			//	delete del;
			//}
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
}
Field::~Field()
{
}
