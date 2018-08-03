#pragma once
#include "Key.h"
#include "Aster.h"

class Field
{
private:
	Aster* arr[30][31];

public:
	void show();
	void down();
	void pos(int);
	/*void clearSt(int);*/

	Field();
	~Field();
};

