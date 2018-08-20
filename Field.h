//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// clss Field(h) - поле в котором перемещаются        //
// снаряды и астеройды                                //
//----------------------------------------------------//
// alpha                                              //
//****************************************************//

#pragma once
#include "Key.h"
#include "Aster.h"
#include "BlastArm.h"
#include "globals.h"
#include "Path.h" 

class Field
{
private:
	Aster* arr[H][L];		//области поля
	Path path;				//алгоритмы передвижения
							//объектов по полю
	int lineAttack[L];		//линия сталкновения с ракетой

public:
	void insertArm(int);	//появление снаряда
	void show();			//вывод на экран
	void down();			//перемещение объектов на поле
	void pos(int);			//рендомное появление астеройда
	
	int* getLineAttack();	//
	int getScore();			//

	Field();				//создаёт пустое поле
	~Field();
};
