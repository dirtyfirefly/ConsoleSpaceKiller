//****************************************************//
// dirty_firefly                                      //
//****************************************************//
// SpaceKiller                                        //
//                                                    //
// clss Path(h) - �������� �� ��������� �����������   //
// �������� �� ����                                   //
//----------------------------------------------------//
// alpha                                              //
//****************************************************//

#pragma once
#include "Aster.h"
#include "BoomMechanic.h"
#include "globals.h"

class Path
{
private:
	BoomMechanic boomWO;

public:
	void downMoveStd(Aster* arr[][L]);	// ����� ���� �� 1
	void upMoveStd(Aster* arr[][L]);	// ����� ����� �� 1

	Path();			//
	~Path();
};
