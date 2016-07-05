#pragma once
#include "agent.h"
#include <string>
class gameMaster
{
public:
	gameMaster();
	bool clearAgent(); // clear agent will delete the current agents and recreates fresh ones
	int playgame(); // plays a single game with the two agents and will return the state of the game after it is complete
	int playMultiGames(int amountOfGames); // plays a number of games then return the state of the last game
	int humanVsPCMove(int state);
	int CheckWinner(int state, int pID); // returns 0 if games is on still, 1 if p1 wins, 2 if p2 wins

private:
	agent *p1, *p2;
	int current_state;
};
