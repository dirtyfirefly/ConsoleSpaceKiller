#pragma once
class Aster
{
private:
	char faces[5] = { '*', 'T', 'I', 'V', 'O' };
	char face;
	bool fStep;

public:
	bool getF();
	void fixF();
	char getFace();

	Aster(int);
	Aster();
	~Aster();
};
