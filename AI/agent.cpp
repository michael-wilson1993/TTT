#include "pch.h"
#include "agent.h"


agent::agent()
{
}

int agent::Play(int state)
{
	return 0;
}

int agent::nextMove(int state)
{
	return 0;
}

int agent::move()
{
	return 0;
}

int agent::rewardAgent(int state, int action, int reward)
{
	return 0;
}

void agent::winner(int rewardPoints)
{
	rewardAgent(last_state, rewardPoints, last_action);
}
