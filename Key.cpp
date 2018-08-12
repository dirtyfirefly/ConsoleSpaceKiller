#include "Key.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;


//���� ������ ��������
//�������� �� ��������� ������������ ������ ������� ����������
//����� ���� ����� ������ ��� ���������� �������� �������� �������
void Key::fixStandart()
{
}
//������������ ������� �������
int Key::check()
{
	int tmp = 0;
	if (_kbhit())
	{
		tmp = _getch();
	}

	//��������� �������� �������
	switch ((char)tmp)
	{
	case (int)'A':	//����������� �����
	case (int)'a':
	case (int)'4':
		if (posRoc == 0)	//���� ���� ����, �� �����
			break;
		line[posRoc] = NULL;
		line[--posRoc] = &roc;
		break;
	case (int)'D':	//����������� ������
	case (int)'d':
	case (int)'6':
		if (posRoc == 30)	//���� ���� ����, �� �����
			break;
		line[posRoc] = NULL;
		line[++posRoc] = &roc;
		break;
	case (int)' ':	//��������
		//���� ���������, ���������� ����� �������
		if (roc.shoot())
			return posRoc;
		break;
	default:
		break;		
	}
	//���� ����� �� �������
	return -1;
}
//����������� �� �����
void Key::show()
{
	//� ������� ������� ���� ���� face ��� ��� ����������� �� �����
	//��� NULL �������� ��������������� ������
	for (int i = 0; i < 31; i++)
	{
		if (line[i] == NULL)
			std::cout << " ";
		else
			std::cout << line[i]->getFace();
	}
}

//������ ������ ��� ���� � ������������� 
//������ � ��� ����� (14)
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
