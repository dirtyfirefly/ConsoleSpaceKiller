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
	case (int)'5':
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
	//
	//��� NULL �������� ��������������� ������
	for (int i = 0; i < L; i++)
	{
		if (line[i] == NULL)
			std::cout << " ";
		else
			std::cout << line[i]->getFace();
	}
}
// ��������� ������������ ������
void Key::boomRocet(bool* lineAttack)
{
	for (int i = 0; i < L; i++)
	{
		//��������� �� ������������
		//��������� ����� ���� ��
		if (lineAttack[i] && i == posRoc)
			roc.hp.downHP(DMG[0]);
		lineAttack[i] = false;
	}
}
//���������� ��������� ������
void Key::showR(int score)
{
	cout << endl << "| life: " << roc.hp.getHP() << "|\t"
		<< "| arm: -- |" << endl
		<< "\t| score: " << score << "|" << endl;
}

//������
Roc Key::getRoc()
{
	return roc;
}

//������ ������ ��� ���� � ������������� 
//������ � ��� ����� (L / 2)
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
