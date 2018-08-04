#pragma once
class Arm
{
private:
	int amt;
	int maxAmt;

public:
	int getAmt();
	void regenAmt(bool);

	Arm();
	~Arm();
};

