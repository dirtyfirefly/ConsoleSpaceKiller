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

class Aster
{
private:
	char faces[5] = { '*', 'T', 'I', 'V', 'O' };// ���� ������

protected:
	HP hp;
	bool arm;		// �������������� �������
	char face;		// ������
	bool fStep;		// ���� �� ����������� 
					// � ����������� ������ �������

public:
	bool getF();	//(fStep) 
	void fixF();	//(fStep) ��������� ���� �������� ����
	char getFace();	//
	bool getArm();	//

	Aster(int);		// �������� ������ �����, ������ �� �������
	Aster();		// �����-�� ������ ������ ����������� ������
	virtual~Aster();
};
