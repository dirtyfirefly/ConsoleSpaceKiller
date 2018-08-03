#include <iostream>
#include <Windows.h>
#include "Field.h"
#include "Key.h"
#include <thread>
#include <mutex>
#include <ctime>

using namespace std;

bool f = false;

void boom(Field& obj1, mutex& m)
{
	int i = 1;
	int count = 0;
	int ast1 = 0; // metod pos()

	srand((unsigned int)time(0));
	while (i < 31)
	{
		ast1 = rand() % 30;
		m.lock();
		system("cls");
		obj1.down();
		if (!(count++ % 5))
			obj1.pos(ast1);
		obj1.show();
		if (f)
		{
			/*obj1.boom(count + 1, 14);
			count = -1;*/
		}
		m.unlock();
		Sleep(200);
	}
}

void rock(Key& r, mutex& m)
{
	while (true)
	{
		r.check(f);
		m.lock();
		r.show();
		m.unlock();
		Sleep(200);
	}
}

int main(void)
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Key key;
	Field field;
	mutex m;
	thread t1(boom, ref(field), ref(m));
	thread t2(rock, ref(key), ref(m));
	if (t1.joinable())
		t1.join();
	if (t2.joinable())
		t2.join();

	return 0;
}
