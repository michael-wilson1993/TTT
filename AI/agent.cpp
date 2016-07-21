#include "pch.h"
#include "agent.h"
#include <string>
#include <ctime>
#include <random>

agent::agent()
{
}

agent::agent(char p, char o)
{
	pID = p;
	OtherPID = o;
	for (int x = 0; x < 9; x++)
		defActionTable[x] = 10;
	srand(time(NULL));
}

int agent::Play(std::string state)
{
	last_state = state; // saves the state before it changes after the move
	last_action = nextMove(state); // save the action that it is going to do
	return last_action; // fix to return a state
}

int agent::nextMove(std::string state)
{
	double MaxQValue = 0;
	int move = 0;
	int size = QTable[state].size();
	if ( size == 1)
	{
		QTable[state] = defActionTable;
		return 0;
	}

	int randNumber = rand() % 100;
	if (randNumber > 85)
	{
		move = rand()%9;
		
	}
	else
	{
		MaxQValue = QTable[state][0];
		for (int x = 1; x < QTable[state].size(); x++)
		{
			if (MaxQValue < QTable[state][x])
			{
				MaxQValue = QTable[state][x];
				move = x;
			}
		}
	}
	return move;
}

std::string agent::move(std::string state, int action)
{
	nextState = state;
	nextState[action] = pID;
	return nextState;
}

int agent::rewardAgent(std::string state, int rew)
{
	//updateStatePrime(state);
	//reward = rew;
	//double oldQValue = QTable[last_state][last_action]; // gets the reward/QValue from the state and action we did
	//double newQValue = maxQ(state);
	//double QValue = oldQValue + alpha * (reward + lambda * (newQValue - oldQValue)); // calculates the qvalue that will be put into the table with the current state and action 
	//QTable[last_state][last_action] = QValue;
	//return 0;
	updateStatePrime(state);
	reward = rew;
	double oldQValue = QTable[last_state][last_action]; // gets the reward/QValue from the state and action we did
	double newQValue = maxQ(state);

	int p = 0;
	std::string temp = "";
	std::vector < std::string > table;
	std::map < std::string, int >::iterator it = Ttable[last_state][last_action].begin();
	for (int x = 0; x < Ttable[last_state][last_action].size(); x++)
	{
		table.push_back(it->first);
	}

	for (int x = 0; x < table.size(); x++)
	{
		p += Ttable[last_state][last_action][table[x]];
	}

	double QValue = (Ttable[last_state][last_action][state] + c)/p*(Rtable[last_state][last_action][state] + newQValue);
	QTable[last_state][last_action] = QValue;
	return 0;
}





double agent::maxQ(std::string state)
{
	double max = QTable[state][0];

	for (int x = 1; x < QTable[state].size(); x++)
	{
		if (max < QTable[state][x])
			max = QTable[state][x];
	}
	return max;
}

int agent::checkWinner(std::string state)
{
	std::string gameState = state; // this checks the board to see if there is winners, if there is it will return 10 else it will return 0
	char winnersID = 'x';
	for (int x = 0; x < 3; x++)
	{
		if (gameState.at(x * 3) ==  gameState.at((x * 3) + 1) && gameState.at((x * 3) + 2) == gameState.at((x * 3) + 1) && gameState.at((x * 3) + 1) != '0') // check colums
			winnersID = gameState.at(x * 3);
		if (gameState.at(x) ==  gameState.at(x + 3)  && gameState.at(x + 6) == gameState.at(x + 3) && gameState.at(x + 3) != '0') // checks rows
			winnersID = gameState.at(x);
	}
	if (gameState.at(0) ==  gameState.at(4)  && gameState.at(8) == gameState.at(4) && gameState.at(4) != '0') // checks diagonal
		winnersID = gameState.at(0);
	if (gameState.at(2) ==  gameState.at(4)  && gameState.at(6) == gameState.at(4) && gameState.at(4) != '0') // checks diagonal
		winnersID = gameState.at(0);
	return 0;
}

void agent::updateStatePrime(std::string state)
{
	int Rtab = Rtable[last_state][last_action][state];
	Ttable[last_state][last_action][state]++;
	Rtable[last_state][last_action][state] = Rtab + (QTable[last_state][last_action] - Rtab) / Ttable[last_state][last_action][state];
}
