#include "pch.h"
#include "gameMaster.h"


gameMaster::gameMaster()
{
	p1 = new agent;
	p2 = new agent;
}

bool gameMaster::clearAgent()
{
	if (p1 != nullptr)
		delete p1;
	if (p2 != nullptr)
		delete p2;
	p1 = new agent;
	p2 = new agent;
	return true;
}

int gameMaster::playgame()
{
	int state = 333333333, winningReward = 10;
	while (true)
	{
		state = p1->Play(state);
		if (CheckWinner(state, 1) == 1) // checks if player one wins
		{
			p1->winner(winningReward);
			break;
		}
		state = p2->Play(state);
		if (CheckWinner(state, 2) == 2) // checks if player one wins
		{
			p2->winner(winningReward);
			break;
		}
	}

	return 0;
}

int gameMaster::playMultiGames(int amountOfGames)
{
	for (int x = 0; x < amountOfGames-1; x++)
		playgame(); // plays the bulk of the games
	return playgame(); // returns the last games state
}

int gameMaster::humanVsPCMove(int state)
{
	return 0;
}


int gameMaster::CheckWinner(int state, int pID)
{
	std::string gameState = std::to_string(state);
	for (int x = 0; x < 3; x++)
	{
		if (gameState.at(x*3) == pID && gameState.at((x*3) + 1) == pID && gameState.at((x*3) + 2) == pID)
			return pID;
		if (gameState.at(x) == pID && gameState.at(x+3) == pID && gameState.at(x+6) == pID)
			return pID;
	}
	if (gameState.at(0) == pID && gameState.at(4) == pID && gameState.at(8) == pID)
		return pID;
	if (gameState.at(2) == pID && gameState.at(4) == pID && gameState.at(6) == pID)
		return pID;
	return 0;
}
