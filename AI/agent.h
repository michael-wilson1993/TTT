#pragma once

#include <map>
#include <vector>
#include "QTableComponent.h"
class agent
{
public:
	agent();
	agent(char x) { pID = x; }; // sets the agents id to x
	std::string Play(std::string state); // this will play the move and return the next state
	int nextMove(std::string state); // takes the current state of the board and returns the best move
	std::string move(std::string state, int action); // makes the move and returns the reward and stores the state;
	int rewardAgent(std::string state, int action, int reward); // rewards the agent for the move he did
	void winner(int rewardPoints); // call this when this agent wins
	double maxQ(std::string state); // returns the best rewarding action for the state
	int findReward(std::string state, int action); // returns the reward for the action at that state.
	int checkWinner(std::string state); // checks if the last move done made this agent win.
	void punish(); // punishes the agent if it loses.
	int bestMove(std::string state); // gets the best move the for the state

private:
	char pID;
	std::string curState, nextState;
	int reward;
	int last_action;
	std::string last_state; // used to reward agent if they win...
	double alpha = 0.8, lambda = 0.8; // lambda is probably a bad name for the discount rate
	std::vector< QTableComponent > QTable;

};

