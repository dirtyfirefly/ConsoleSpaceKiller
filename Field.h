#pragma once
#include "Key.h"
#include "Aster.h"
#include "BlastArm.h"

class Field
{
private:
	Aster* arr[30][31];

public:
	void insertArm(int);
	void show();
	void down();
	void pos(int);
	/*void clearSt(int);*/

	Field();
	~Field();
};
