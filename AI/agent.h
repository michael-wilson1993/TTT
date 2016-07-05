#pragma once
class agent
{
public:
	agent();
	int Play(int state); // this will play the move and return the next state
	int nextMove(int state); // takes the current state of the board and returns the best move
	int move(); // makes the move and returns the reward and stores the state;
	int rewardAgent(int state, int action, int reward); // rewards the agent for the move he did
	void winner(int rewardPoints); // call this when this agent wins

private:
	int curState, nextState, reward;
	int last_action, last_state; // used to reward agent if they win...
};

