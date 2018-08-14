//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// clss Key(h) - ���������� ������� � ���������       //
//����� ����                                          //
//----------------------------------------------------//
// alpha                                              //
//****************************************************//

#pragma once
#include<thread>
#include "Roc.h"
#include "globals.h"

class Key
{
private:
	Roc* line[L];	// ������ ��������� ��� ������
	int standart;	// ����� ��� ������� 
					// ������� ���������� ����������
	int posRoc;		// ������� ������ � ������ ������
	Roc roc;		// ������ ������

public:
	int check();		//������������ ������� �������
	void show();		//����������� �� �����
	void fixStandart();	//�������� �� ��������� ������������ 
						//������ ������� ����������

	Key();			//������ ������ ��� ���� � ������������� 
					//������ � ��� ����� (14)
	~Key();
};
