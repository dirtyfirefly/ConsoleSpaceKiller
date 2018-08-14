//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// clss Aster(h) - ��������� ����� ������             //
//----------------------------------------------------//
// alpha                                              //
//****************************************************//

#pragma once
#include "HP.h"
#include "globals.h"

class Aster
{
private:
	char faces[FACE] = { '*', 'T', 'I', 'V', 'O' };// ���� ������

protected:
	HP hp;
	bool arm;		// �������������� �������
	char face;		// ������
	bool fStep;		// ���� �� ����������� 
					// � ����������� ������ �������
	int damage;		// ����

public:
	void hpDown(Aster*);	// �������� �� ������� hp
	void fixF();			//(fStep) ��������� ���� �������� ����

	int getHP();	// ���������� hp		
	int getDamage();// ���������� ����
	bool getF();	//(fStep)
	char getFace();	//
	bool getArm();	//

	Aster(int);		// �������� ������ �����, ������ �� �������
	Aster();		// �����-�� ������ ������ ����������� ������
	virtual~Aster();
};
