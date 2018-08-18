//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// main + blocks_code                                 //
//----------------------------------------------------//
// alpha                                              //
//****************************************************//

#include <iostream>
#include <Windows.h>
#include "Field.h"
#include "Key.h"
#include <thread>
#include <mutex>
#include <ctime>
#include "globals.h"

using namespace std;

////������� ����� ��� ���������� ��������
static int flagShootPlaer = -1; // ����� �������� ������
static int* lineAttack = NULL;	// ���� � ����� ������������
static bool play = true;		// ���� ���������� ���� �������
static int score = 0;			// ���������� ����� ������

//���� ���� 1
//�������� ����
void boom(Field&, mutex&);
//���� ���� 2
//�������� ����
void rock(Key&, mutex&);

int main(void)
{
	//������� unicode
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Key key;		//�������� ���������� �������
	Field field;	//�������� ����
	mutex m;		//������ �������������

	//������ ������ ���� �� ����������
	thread t1(boom, ref(field), ref(m));
	thread t2(rock, ref(key), ref(m));
	
	//�������� ������� � main
	if (t1.joinable())
		t1.join();
	if (t2.joinable())
		t2.join();

	return 0;
}

//1-�� ���� ����
//����� ���� ���������������� � ������
//�������� � ����� ����
void boom(Field& obj1, mutex& m)
{
	/*int i = 1;*/
	int count = 0;
	int ast1 = 0;

	srand((unsigned int)time(0));
	
	//������������ (�����) ���������� ����������� ���������� �
	// ����� ���� �� �����
	//����� ������������ �� 2-�� ������
	while (play)
	{
		ast1 = rand() % H;	//��������� ��������� ����������
		m.lock();
		system("cls");
		//�����������
		obj1.down();
		// ����������� ���������� �����
		score += obj1.getScore();
		/*cout << score << endl;
		system("pause");*/
		//������� ���� � ����� ������������
		lineAttack = obj1.getLineAttack();
		/*for (int i = 0; i < L; i++)
			cout << lineAttack[i] << " ";
		system("pause");*/
		//������� ��������� ����������
		if (!(count++ % 10))
			//��������� ���������
			obj1.pos(ast1);
		//����� �� �����
		obj1.show();
		//�������� ����� ������� ������ �� ������
		if (flagShootPlaer >= 0)
		{
			//����������� �������� �� ���� � ������ �����
			obj1.insertArm(flagShootPlaer);
			//��������� ��������
			flagShootPlaer = -1;
		}
		m.unlock();
		//5 ������ � �������
		Sleep(200);
	}
}

//2-�� ����
//����� ���� ���������������� � ������
//�������� � ������������ ������ � ���������
void rock(Key& r, mutex& m)
{
	while (play)
	{
		// �������� ������� ������ � ������
		r.getRoc().hp.getHP() > 0 ? play = true : play = false;
		//�� ������������������ �������� ������� �������
		flagShootPlaer = r.check();
		//������������������ ����������� � ������� � ��������
		// �� ������������ ������ � ���������
		m.lock();
		//���� �� ����
		if (lineAttack)
			//�������� ������������
			r.boomRocet(lineAttack);
		// ����� �� �����
		r.show();
		m.unlock();
		//����� ��������� ������
		r.showR(score);
		//5 ������ � �������
		Sleep(200);
	}
	//hp ������ < 1
	cout << endl << "\t\tgame over" << endl;
	cout << "score: " << score << endl;
	system("pause");
}