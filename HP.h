#pragma once
class HP
{
private:
	int hp;
public:
	void downHP();
	void upHP();
	int getHP();

	HP();
	HP(char);
	~HP();
};
