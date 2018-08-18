//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// clss Field(h) - ���� � ������� ������������        //
// ������� � ���������                                //
//----------------------------------------------------//
// alpha                                              //
//****************************************************//

#pragma once
#include "Key.h"
#include "Aster.h"
#include "BlastArm.h"
#include "globals.h"
#include "Path.h" 

class Field
{
private:
	Aster* arr[H][L];		//������� ����
	Path path;				//��������� ������������
							//�������� �� ����
	bool lineAttack[L];		//����� ������������ � �������

public:
	void insertArm(int);	//��������� �������
	void show();			//����� �� �����
	void down();			//����������� �������� �� ����
	void pos(int);			//��������� ��������� ���������
	
	bool* getLineAttack();	//
	int getScore();			//

	Field();				//������ ������ ����
	~Field();
};
