#pragma once
#include<thread>
class Key
{
private:
	char line[31];
	int standart;
	int rocet;

public:
	void check(bool&);
	void show();
	void fixStandart();

	Key();
	~Key();
};

