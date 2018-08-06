#pragma once
#include<thread>
#include "Roc.h"

class Key
{
private:
	Roc* line[31];
	int standart;
	int posRoc;
	Roc roc;

public:
	/*int shootPos();*/
	int check();
	void show();
	void fixStandart();

	Key();
	~Key();
};

