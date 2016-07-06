#include "pch.h"
#include "agent.h"
#include <string>

agent::agent()
{
}

std::string agent::Play(std::string state)
{
	last_state = state; // saves the state before it changes after the move
	last_action = nextMove(state); // save the action that it is going to do
	nextState = move(last_state, last_action); // determines what the agent thinks is the next best move
	reward = checkWinner(nextState); // determines what kind of reward the agent should get
	rewardAgent(last_state, last_action, reward); // rewards the agent for the move it has chosen
	return nextState; // fix to return a state
}

int agent::nextMove(std::string state)
{
	int bestMove = maxQ(state);// finds the best move and returns it
	if (bestMove != -1)
		return bestMove;
	std::string gameState = state; // if the best move is not found it will search the board for an available move
	for (int x = 0; x < gameState.size() ; x++)
		if (gameState.at(x) == '0')
			return x;
}

std::string agent::move(std::string state, int action)
{
	nextState = state;
	nextState[action] = (pID +48);
	return nextState;
}

int agent::rewardAgent(std::string state, int action, int reward)
{
	double oldQValue = findReward(state, action); // gets the reward/QValue from the state and action we did
	int newStateAction = maxQ(nextState); // gets the best action for the new state
	double QValue = oldQValue + alpha * (reward + lambda * findReward(nextState, newStateAction) - oldQValue); // calculates the qvalue that will be put into the table with the current state and action 
	for (int x = 0; x < QTable.size(); x++) // looks for the state and action to see if it has been done before if it has it will put the new qvalue in place
	{
		if (QTable[x].state == state && QTable[x].action == action)
		{
			QTable[x].reward = QValue;
			return 0;
		}
	}
	QTable.push_back(QTableComponent(state, action, QValue)); // if the loop above does not find the state and action it will add it to the vector with the new qvalue
	return 0;
}

void agent::winner(int rewardPoints)
{
	rewardAgent(last_state, rewardPoints, last_action);
}

int agent::maxQ(std::string state)
{
	int max = 0, bestAction = -1;
	for (int x = 0; x < QTable.size(); x++)
	{
		if (QTable[x].state == state) // checks if we are one the correct state
		{
			if (QTable[x].reward > max) // checks if the action made at that state is better than the others
			{
				max = QTable[x].reward;
				bestAction = QTable[x].action;
			}
		}
	}
	return bestAction; // returns the best action
}

int agent::findReward(std::string state, int action)
{
	for (int x = 0; x < QTable.size(); x++)
		if (state == QTable[x].state)
			if (action == QTable[x].action)
				return QTable[x].reward;
	return 0;
}

int agent::checkWinner(std::string state)
{
	std::string gameState = state; // this checks the board to see if there is winners, if there is it will return 10 else it will return 0
	for (int x = 0; x < 3; x++)
	{
		if (gameState.at(x * 3) == pID && gameState.at((x * 3) + 1) == pID && gameState.at((x * 3) + 2) == pID)
			return 10;
		if (gameState.at(x) == pID && gameState.at(x + 3) == pID && gameState.at(x + 6) == pID)
			return 10;
	}
	if (gameState.at(0) == pID && gameState.at(4) == pID && gameState.at(8) == pID)
		return 10;
	if (gameState.at(2) == pID && gameState.at(4) == pID && gameState.at(6) == pID)
		return 10;
	return 0;
}
