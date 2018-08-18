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

////сделать класс для глобальных констант
static int flagShootPlaer = -1; // линия выстрела ракеты
static int* lineAttack = NULL;	// инфо о линии сталкновения
static bool play = true;		// флаг исполнения всех условий
static int score = 0;			// количество очков игрока

//блок кода 1
//описание ниже
void boom(Field&, mutex&);
//блок кода 2
//описание ниже
void rock(Key&, mutex&);

int main(void)
{
	//сделать unicode
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Key key;		//создание управления ракетой
	Field field;	//создание поля
	mutex m;		//объект синхронизации

	//запуск блоков кода на выполнение
	thread t1(boom, ref(field), ref(m));
	thread t2(rock, ref(key), ref(m));
	
	//привязки потоков к main
	if (t1.joinable())
		t1.join();
	if (t2.joinable())
		t2.join();

	return 0;
}

//1-ый блок кода
//часть кода обрабатывающаяся в потоке
//работает с полем игры
void boom(Field& obj1, mutex& m)
{
	/*int i = 1;*/
	int count = 0;
	int ast1 = 0;

	srand((unsigned int)time(0));
	
	//одновремнное (почти) выполнение перемещения астеройдов и
	// вывод поля на экран
	//имеет синхонизацию со 2-ым блоком
	while (play)
	{
		ast1 = rand() % H;	//рендомное появление астеройдов
		m.lock();
		system("cls");
		//перемещение
		obj1.down();
		// увеличиваем количество очков
		score += obj1.getScore();
		/*cout << score << endl;
		system("pause");*/
		//передаёт инфо о линии сталкновения
		lineAttack = obj1.getLineAttack();
		/*for (int i = 0; i < L; i++)
			cout << lineAttack[i] << " ";
		system("pause");*/
		//частота появления астеройдов
		if (!(count++ % 10))
			//появление астеройда
			obj1.pos(ast1);
		//вывод на экран
		obj1.show();
		//проверка флага нажатия игрока на пробел
		if (flagShootPlaer >= 0)
		{
			//отоброжение выстрела на поле в нужном месте
			obj1.insertArm(flagShootPlaer);
			//обнуление выстрела
			flagShootPlaer = -1;
		}
		m.unlock();
		//5 кадров в секунду
		Sleep(200);
	}
}

//2-ой блок
//часть кода обрабатывающаяся в потоке
//работает с перемещением рокеты и стрельбой
void rock(Key& r, mutex& m)
{
	while (play)
	{
		// проверка наличия жизней у игрока
		r.getRoc().hp.getHP() > 0 ? play = true : play = false;
		//не синхронизированная проверка нажатия клавишь
		flagShootPlaer = r.check();
		//синхронизированное отоброжение в консоли и проверка
		// на сталкновение ракеты с объектами
		m.lock();
		//есть ли инфо
		if (lineAttack)
			//проверка столкновения
			r.boomRocet(lineAttack);
		// вывод на экран
		r.show();
		m.unlock();
		//вывод состояния ракеты
		r.showR(score);
		//5 кадров в секунду
		Sleep(200);
	}
	//hp ракеты < 1
	cout << endl << "\t\tgame over" << endl;
	cout << "score: " << score << endl;
	system("pause");
}