#ifndef __GAME_TURN_H__
#define __GAME_TURN_H__

#include <vector>

#include "simulated_turn.h"

typedef std::vector<SimulatedTurn> SimulatedTurns;

class Turn {
public:
	Turn();
	~Turn();

	int getId() const;
	void setId(int id);

	int getSimulatedTurnsCount() const;

	void initSimulatedTurns(int simulatedTurnsCount);

	SimulatedTurn* getSimulatedTurnPtr(int simulatedTurnIdx);

private:
	int id;
	SimulatedTurns simulatedTurns;
};

#endif // __GAME_TURN_H__
