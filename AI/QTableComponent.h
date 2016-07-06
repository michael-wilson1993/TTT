#pragma once
#include <string>

struct QTableComponent 
{
	QTableComponent(std::string CState = "000000000", int CAction = 133333333, double CReward = 0) : state(CState), action(CAction), reward(CReward) {};
	int  action;
	double reward;
	std::string state;

};

