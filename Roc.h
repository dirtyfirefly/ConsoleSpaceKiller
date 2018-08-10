//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// clss Roc(h) - �������� �������������� ������ ��    //
// ������ ����                                        //
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

