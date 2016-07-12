#pragma once
#include "agent.h"
#include <string>
class gameMaster
{
public:
	gameMaster();
	bool clearAgent(); // clear agent will delete the current agents and recreates fresh ones
	std::string  playgame(); // plays a single game with the two agents and will return the state of the game after it is complete
	std::string  playMultiGames(int amountOfGames); // plays a number of games then return the state of the last game
	int humanVsPCMove(int state); // human vs computer ---- still have to make everything for the agent side
	bool CheckWinner(std::string state); // returns 0 if games is on still, 1 if p1 wins, 2 if p2 wins
	int getGamesPlayed() { return gamesplayed; }; // returns the games played
	std::string getPos(int x); // get the value at x coor on the board
private:
	std::string state;
	agent *p1, *p2;
	int current_state;
	int gamesplayed = 0;
};

