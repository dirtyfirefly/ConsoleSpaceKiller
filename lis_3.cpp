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

using namespace std;

//������� ������������ ���� ��� ���������� ���������� � ��������
int f = -1;

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
	while (true /*i < 31*/) //����� i ���������� ��� ��� 
							//��������� �� ����
							//���������������� - �����
							//�� �����-�� ��� ����
	{
		ast1 = rand() % 30;
		m.lock();
		system("cls");
		//�����������
		obj1.down();
		//������� ��������� ����������
		if (!(count++ % 5))
			//��������� ���������
			obj1.pos(ast1);
		//����� �� �����
		obj1.show();
		//�������� ������� ������ �� ������
		if (f >= 0)
		{
			//����������� �������� �� ���� � ������ �����
			obj1.insertArm(f);
			//��������� ��������
			f = -1;
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
	while (true)
	{
		//�� ������������������ �������� ������� �������
		f = r.check();
		//������������������ ����������� � �������
		m.lock();
		r.show();
		m.unlock();
		//5 ������ � �������
		Sleep(200);
	}
}

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
