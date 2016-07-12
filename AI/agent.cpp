#include "pch.h"
#include "agent.h"
#include <string>

agent::agent()
{
}

agent::agent(char p, char o)
{
	pID = p;
	OtherPID = o;
	for (int x = 0; x < 9; x++)
		defActionTable[x] = 10;
}

int agent::Play(std::string state)
{
	last_state = state; // saves the state before it changes after the move
	last_action = nextMove(state); // save the action that it is going to do
	return last_action; // fix to return a state
}

int agent::nextMove(std::string state)
{
	int max;
	int move;

	if (QTable[state].size() == 0)
	{
		QTable[state] = defActionTable;
		return 0;
	}

	for (int x = 1; x < QTable[state].size(); x++)
	{
		if (max < QTable[state][x])
		{
			max = QTable[state][x];
			move = x;
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

int agent::rewardAgent(std::string state, int reward)
{
	double oldQValue = QTable[last_state][last_action]; // gets the reward/QValue from the state and action we did
	double newQValue = maxQ(state);
	double QValue = oldQValue + alpha * (reward + lambda * (newQValue - oldQValue)); // calculates the qvalue that will be put into the table with the current state and action 
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
