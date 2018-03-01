#ifndef __SVG_CREATOR_H__
#define __SVG_CREATOR_H__

#include "game_data.h"

class SVGCreator {
public:
	SVGCreator();
	~SVGCreator();

	GameData* getGameData() const;

	void setGameData(GameData* gameData);

	void createGameSimulation();

private:
	GameData* gameData;
};

#endif // __SVG_CREATOR_H__
