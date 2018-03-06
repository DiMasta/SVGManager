#ifndef __SIMULATED_TURN_H__
#define __SIMULATED_TURN_H__

#include <vector>

#include "objects_holder.h"

class SimulatedTurn : public ObjectsHolder {
public:
	SimulatedTurn();
	~SimulatedTurn();

private:
};

typedef std::vector<SimulatedTurn> SimulatedTurns;

#endif // __SIMULATED_TURN_H__
