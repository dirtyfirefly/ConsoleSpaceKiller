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
	cout << "|";
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
	cout << "|";
}
// ��������� ������������ ������
void Key::boomRocet(int* lineAttack)
{
	for (int i = 0; i < L; i++)
	{
		//��������� �� ������������
		//��������� ����� ���� ��
		if (lineAttack[i] == 1 && i == posRoc)
			roc.hp.downHP(DMG[0]);
		if (lineAttack[i] == 2 && i == posRoc)
			roc.arm.regenAmt();
		if (lineAttack[i] == 3 && i == posRoc)
			roc.hp.upHP(1);
		lineAttack[i] = 0;
	}
}
//���������� ��������� ������
void Key::showR(int score)
{
	cout << endl;
	for (int i = 0; i < L+2; i++)
		cout << "#";
	cout << endl << "| life: " << roc.hp.getHP() << "| \t "
		<< "     | arm: ";
	if (roc.arm.getAmt() > 0)
		cout << roc.arm.getAmt();
	else
		cout << "0";
	cout << " |" << endl
		<< "\t  | score: " << score << " |" << endl;
	for (int i = 0; i < L + 2; i++)
		cout << "#";

	cout << endl << " ! (+arm)" << endl << " + (+hp)" << endl;
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
