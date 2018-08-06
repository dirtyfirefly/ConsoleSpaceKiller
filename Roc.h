#pragma once
#include "MechanicShoot.h"
#include "Arm.h"

class Roc
{
private:
	MechanicShoot sh;
	Arm arm;
	char face;

public:
	char getFace();
	bool shoot();

	Roc();
	~Roc();
};

