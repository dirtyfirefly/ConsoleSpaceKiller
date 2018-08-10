//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// clss Roc(h) - является предстовлением ракеты ГГ    //
// данной игры                                        //
//----------------------------------------------------//
// alpha                                              //
//****************************************************//

#pragma once
#include "MechanicShoot.h"
#include "Arm.h"
#include "HP.h"

class Roc
{
private:
	MechanicShoot sh;
	Arm arm;
	HP hp;
	char face;

public:
	char getFace();
	bool shoot();

	Roc();
	~Roc();
};

