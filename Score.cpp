#include "Score.h"

//������������� ����������� ���������� �����
//� ����������� �� �������
void Score::init(char face)
{
	switch(face)
	{
	case (int)'O':
		score = SCR[4];
		break;
	case (int)'T':
		score = SCR[2];
		break;
	default:
		score = SCR[0];
		break;
	}
}

//
int Score::getScore()
{
	return score;
}

//������������� score � 100
Score::Score() : score(SCR[0])
{
}
Score::~Score()
{
}
