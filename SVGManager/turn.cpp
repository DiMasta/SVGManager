#include "turn.h"

Turn::Turn() :
	simulatedTurns()
{

}

//*************************************************************************************************************
//*************************************************************************************************************

Turn::~Turn() {
	simulatedTurns.clear();
}

//*************************************************************************************************************
//*************************************************************************************************************

int Turn::getId() const {
	return id;
}

//*************************************************************************************************************
//*************************************************************************************************************

void Turn::setId(int id) {
	this->id = id;
}

//*************************************************************************************************************
//*************************************************************************************************************

int Turn::getSimulatedTurnsCount() const {
	return static_cast<int>(simulatedTurns.size());
}

//*************************************************************************************************************
//*************************************************************************************************************

void Turn::initSimulatedTurns(int simulatedTurnsCount) {
	simulatedTurns.reserve(simulatedTurnsCount);
}

//*************************************************************************************************************
//*************************************************************************************************************

SimulatedTurn* Turn::getSimulatedTurnPtr(int simulatedTurnIdx) {
	return &(*(simulatedTurns.begin() + simulatedTurnIdx));
}
