#include "pch.h"
#include "gameMaster.h"
#include <string>

gameMaster::gameMaster()
{
	p1 = new agent('1', '2');
	p2 = new agent('2','1');
}

bool gameMaster::clearAgent()
{
	if (p1 != nullptr)
		delete p1;
	if (p2 != nullptr)
		delete p2;
	p1 = new agent('1', '2');
	p2 = new agent('2', '1');
	gamesplayed = 0;

	return true;
}

bool ifValidMove(std::string state, int move)
{
	if (state[move] == 0)
		return true;
	return false;
}

std::string gameMaster::playgame()
{
	state = "000000000";
	int move, counter = 0;
	int winnerId = 0;
	while (counter != 8)
	{
		if (!counter)
			p1->rewardAgent(state, 0);
		move = p1->Play(state);
		while (!ifValidMove(state, move))
		{
			p1->rewardAgent(state, -1000);
			move = p1->Play(state);
		}
		
		if (CheckWinner(state)) // checks if player one wins
		{
			winnerId = 1;
			break;
		}
		if (counter == 8)
			break;
		if(!counter)
			p2->rewardAgent(state, 0);
		move = p2->Play(state);
		while (!ifValidMove(state, move))
		{
			p2->rewardAgent(state, -1000);
			move = p2->Play(state);
		}
		
		if (CheckWinner(state)) // checks if player one wins
		{
			winnerId = 2;
			break;
		}
		counter += 2;
	}
	if (winnerId == 1)
	{
		p1->rewardAgent(state, 10);
		p2->rewardAgent(state, -10);
	}
	else if (winnerId == 2)
	{
		p2->rewardAgent(state, 10);
		p1->rewardAgent(state, -10);
	}
	else
	{
		p2->rewardAgent(state, 1);
		p1->rewardAgent(state, 1);
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
	char winnersID = 'x';
	std::string gameState = state;

	for (int x = 0; x < 3; x++)
	{
		if (gameState.at(x * 3) == gameState.at((x * 3) + 1) && gameState.at((x * 3) + 2) == gameState.at((x * 3) + 1) && gameState.at((x * 3) + 1) != '0') // check colums
			return true;
		if (gameState.at(x) == gameState.at(x + 3) && gameState.at(x + 6) == gameState.at(x + 3) && gameState.at(x + 3) != '0') // checks rows
			return true;
	}
	if (gameState.at(0) == gameState.at(4) && gameState.at(8) == gameState.at(4) && gameState.at(4) != '0') // checks diagonal
		return true;
	if (gameState.at(2) == gameState.at(4) && gameState.at(6) == gameState.at(4) && gameState.at(4) != '0') // checks diagonal
		return true;

	return false;
}

std::string gameMaster::getPos(int x)
{
	std::string position = "0";
	position[0] = state.at(x);
	return position;
}
