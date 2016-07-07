#include "pch.h"
#include "gameMaster.h"
#include <string>

gameMaster::gameMaster()
{
	p1 = new agent('1');
	p2 = new agent('2');
}

bool gameMaster::clearAgent()
{
	if (p1 != nullptr)
		delete p1;
	if (p2 != nullptr)
		delete p2;
	p1 = new agent('1');
	p2 = new agent('2');
	gamesplayed = 0;

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
	char winnersID = 'x';
	std::string gameState = state;

	for (int x = 0; x < 3; x++)
	{
		if (gameState.at(x * 3) == gameState.at((x * 3) + 1) && gameState.at((x * 3) + 2) == gameState.at((x * 3) + 1) && gameState.at((x * 3) + 1) != '0') // check colums
			winnersID = gameState.at(x * 3);
		if (gameState.at(x) == gameState.at(x + 3) && gameState.at(x + 6) == gameState.at(x + 3) && gameState.at(x + 3) != '0') // checks rows
			winnersID = gameState.at(x);
	}
	if (gameState.at(0) == gameState.at(4) && gameState.at(8) == gameState.at(4) && gameState.at(4) != '0') // checks diagonal
		winnersID = gameState.at(0);
	if (gameState.at(2) == gameState.at(4) && gameState.at(6) == gameState.at(4) && gameState.at(4) != '0') // checks diagonal
		winnersID = gameState.at(0);


	if (winnersID != 'x') // if winnersid != 'x' that means there was a winner
	{
		if (winnersID == '1')
		{
			p1->winner(10);
			p2->punish();
			return true;
		}
		else if (winnersID == '2')
		{
			p2->winner(10);
			p1->punish();
			return true;
		}
	}

	// this part of code checks if the board is complete. if it is full and there is no winner than we have to end the game. this will not punish iether agent
	int tieCounter = 0;
	for (int x = 0; x < gameState.size(); x++)
		if (gameState.at(x) == '0')
			tieCounter++;
	if (tieCounter == 0)
		return true;
	return false;
}
