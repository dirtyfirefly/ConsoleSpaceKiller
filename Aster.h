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
#include "Score.h"

class Aster
{
private:
	char faces[FACE] = { '*', 'T', 'I', 'V', 'O', '!', '+' };// ���� ������

protected:
	Score score;	// ����
	HP hp;			// �����
	bool arm;		// �������������� �������
	char face;		// ������
	bool fStep;		// ���� �� ����������� 
					// � ����������� ������ �������
	int damage;		// ����
	bool helper;	// ��� ������������ ���������� arm

public:
	void hpDown(Aster*);	// �������� �� ������� hp
	void fixF();			//(fStep) ��������� ���� �������� ����

	int getHP();	// ���������� hp		
	int getDamage();// ���������� ����
	bool getF();	//(fStep)
	char getFace();	//
	bool getArm();	//
	int getScore();	//
	bool getHelper();//

	Aster(int);		// �������� ������ �����, ������ �� �������
	Aster();		// �����-�� ������ ������ ����������� ������
	virtual~Aster();
};
