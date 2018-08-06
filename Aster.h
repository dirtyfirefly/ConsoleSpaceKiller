#pragma once
class Aster
{
private:
	char faces[5] = { '*', 'T', 'I', 'V', 'O' };

protected:
	bool arm;
	char face;
	bool fStep;

public:
	bool getF();
	void fixF();
	char getFace();
	bool getArm();

	Aster(int);
	Aster();
	virtual~Aster();
};
