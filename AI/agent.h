#pragma once

#include <map>
#include <vector>
#include "QTableComponent.h"
class agent
{
public:
	agent();
	agent(char x) { pID = x; }; // sets the agents id to x
	agent(char p, char o); // sets player id and other player id

	int Play(std::string state); // this will play the move and return the next state
	int nextMove(std::string state); // takes the current state of the board and returns the best move
	std::string move(std::string state, int action); // makes the move and returns the reward and stores the state;
	int rewardAgent(std::string state, int reward); // rewards the agent for the move he did
	double maxQ(std::string state); // returns the best rewarding action for the state
	int checkWinner(std::string state); // checks if the last move done made this agent win.
	void updateStatePrime(std::string state); // updates the Ttable
	

private:
	int c = 1;
	char pID;
	char OtherPID;
	std::string curState, nextState;
	int reward;
	int last_action;
	std::string last_state; // used to reward agent if they win...
	double alpha = 0.8, lambda = 0.8; // lambda is probably a bad name for the discount rate
	std::map<std::string, std::map<int, double> > QTable; // qtable
	std::map<std::string, std::map< int, std::map< std::string, double> > > Rtable; // reward for the action A at state S resulting in S`
	std::map<std::string, std::map < int, std::map < std::string, int> > > Ttable; // counts how many times action A at state S results in S`
	std::map<int, double> defActionTable; // default map of all available actions

};

