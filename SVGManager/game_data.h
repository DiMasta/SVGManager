#ifndef __GAME_DATA_H__
#define __GAME_DATA_H__

#include <vector>

#include "turn.h"

typedef std::vector<Turn> Turns;

class GameData {
public:
	GameData();
	~GameData();

	void initTurns(int gameTurnsCount);

	Turn* getTurnPtr(int gameTurnIdx);

private:
	// Game objects
	// All turns array

	Turns turns;
};

#endif // __GAME_DATA_H__