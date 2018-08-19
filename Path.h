//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// clss Path(h) - отвечает за алгоритмы перемещений   //
// объектов по полю                                   //
//----------------------------------------------------//
// alpha                                              //
//****************************************************//

#pragma once
#include "Aster.h"
#include "BoomMechanic.h"
#include "globals.h"

class Path
{
private:
	BoomMechanic boomWO;
	int scoreTmp;

public:
	void downMoveStd(Aster* arr[][L]);	// сдвиг вниз на 1
	void upMoveStd(Aster* arr[][L]);	// сдвиг вверх на 1

	int getScore();	//

	Path();			//
	~Path();
};
