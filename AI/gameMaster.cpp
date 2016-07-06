#include "pch.h"
#include "gameMaster.h"
#include <string>

gameMaster::gameMaster()
{
	p1 = new agent(1);
	p2 = new agent(2);
}

bool gameMaster::clearAgent()
{
	if (p1 != nullptr)
		delete p1;
	if (p2 != nullptr)
		delete p2;
	p1 = new agent(1);
	p2 = new agent(2);
	return true;
}

std::string gameMaster::playgame()
{
	std::string state = "000000000";
	while (true)
	{
		state = p1->Play(state);
		if (CheckWinner(state)) // checks if player one wins
			break;
		state = p2->Play(state);
		if (CheckWinner(state)) // checks if player one wins
			break;
	}
	gamesplayed++; 
	return state;
}

std::string  gameMaster::playMultiGames(int amountOfGames)
{
	for (int x = 0; x < amountOfGames-1; x++)
		playgame(); // plays the bulk of the games
	return playgame(); // returns the last games state
}

int gameMaster::humanVsPCMove(int state)
{
	return 0;
}


bool gameMaster::CheckWinner(std::string state)
{
	std::string gameState = state;
	for (int x = 0; x < 3; x++)
	{
		if (gameState.at(x*3) ==  gameState.at((x*3) + 1) && gameState.at((x*3) + 2) == gameState.at((x * 3) + 1) && gameState.at((x * 3) + 1) != '0')
			return true;
		if (gameState.at(x) == gameState.at(x+3)  && gameState.at(x+6) == gameState.at(x + 3) && gameState.at(x + 3) != '0')
			return true;
	}
	if (gameState.at(0) == gameState.at(4)  && gameState.at(8) == gameState.at(4) && gameState.at(4) != '0')
		return true;
	if (gameState.at(2) ==  gameState.at(4)  && gameState.at(6) == gameState.at(4) && gameState.at(4) != '0')
		return true;
	return false;
}
