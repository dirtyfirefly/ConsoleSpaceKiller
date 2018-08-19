//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// clss Aster(h) - начальный класс врагов             //
//----------------------------------------------------//
// alpha                                              //
//****************************************************//

#pragma once
#include "HP.h"
#include "globals.h"
#include "Score.h"

class Aster
{
private:
	char faces[FACE] = { '*', 'T', 'I', 'V', 'O', '!', '+' };// типы врагов

protected:
	Score score;	// очки
	HP hp;			// жизни
	bool arm;		// принадлежность снаряду
	char face;		// иконка
	bool fStep;		// было ли перемещение 
					// в определённый момент времени
	int damage;		// урон
	bool helper;	// при сталкновении восполняет arm

public:
	void hpDown(Aster*);	// отвечает за подение hp
	void fixF();			//(fStep) поднимает либо опускает флаг

	int getHP();	// возвращает hp		
	int getDamage();// возвращает урон
	bool getF();	//(fStep)
	char getFace();	//
	bool getArm();	//
	int getScore();	//
	bool getHelper();//

	Aster(int);		// выбирает иконку врагу, создаёт не снаряды
	Aster();		// зачем-то создаёт пустой неподвижный объект
	virtual~Aster();
};
