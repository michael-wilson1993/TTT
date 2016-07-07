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
	//reward = checkWinner(nextState); // determines what kind of reward the agent should get
	rewardAgent(last_state, last_action, 0); // updates the qvalues in the table with a single move, if this move is a winning move, the game master object will reward and punish accordingly
	return nextState; // fix to return a state
}

int agent::nextMove(std::string state)
{
	int Move = bestMove(state);// finds the best move and returns it
	if (Move != -1)
		return Move;
	std::string gameState = state; // if the best move is not found it will search the board for an available move
		for (int x = 0; x < gameState.size(); x++)
			if (gameState.at(x) == '0')
				return x;
	
}

std::string agent::move(std::string state, int action)
{
	nextState = state;
	nextState[action] = pID;
	return nextState;
}

int agent::rewardAgent(std::string state, int action, int reward)
{
	double oldQValue = findReward(last_state, last_action); // gets the reward/QValue from the state and action we did
	int newStateAction = bestMove(nextState); // gets the best action for the new state
	double newQValue = findReward(nextState, newStateAction);
	double QValue = oldQValue + alpha * (reward + lambda * (newQValue - oldQValue)); // calculates the qvalue that will be put into the table with the current state and action 
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
	rewardAgent(last_state, last_action, 10);
}



double agent::maxQ(std::string state)
{
	double max = 0;
	if (QTable.size() != 0)
		max = QTable[0].reward;

	for (int x = 0; x < QTable.size(); x++)
	{
		if (QTable[x].state == state) // checks if we are one the correct state
		{
			if (QTable[x].reward > max) // checks if the action made at that state is better than the others
			{
				max = QTable[x].reward;
			}
		}
	}
	return max; // returns the best action
}

int agent::findReward(std::string state, int action)
{
	for (int x = 0; x < QTable.size(); x++)
		if (state == QTable[x].state)
			if (action == QTable[x].action)
				return QTable[x].reward;
	return 0.5;
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

void agent::punish()
{
	rewardAgent(last_state, last_action, -10); // punishes the agent -10 for losing
}

int agent::bestMove(std::string state)
{
	double max = -1;
	int action = -1;
	for (int x = 0; x < QTable.size(); x++)
	{
		if (QTable[x].state == state)
		{
			if (max == -1)
			{
				max = QTable[x].reward;
				action = QTable[x].action;
			}
			else
				if (max > QTable[x].reward)
				{
					max = QTable[x].reward;
					action = QTable[x].action;
				}
		}
	}
	return action;
}
