#ifndef __GAME_TURN_H__
#define __GAME_TURN_H__

#include <vector>

#include "simulated_turn.h"

class Turn {
public:
	Turn();
	~Turn();

	int getId() const;
	void setId(int id);

	int getSimulatedTurnsCount() const;

	void initSimulatedTurns(int simulatedTurnsCount);

	SimulatedTurn* getSimulatedTurnPtr(int simulatedTurnIdx);

	const SimulatedTurns* const getSimulatedTurnsPtr(int simulatedTurnIdx) const;

private:
	int id;
	SimulatedTurns simulatedTurns;
};

typedef std::vector<Turn> Turns;

#endif // __GAME_TURN_H__
