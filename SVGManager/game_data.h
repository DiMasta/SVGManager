#ifndef __GAME_DATA_H__
#define __GAME_DATA_H__

#include <vector>

#include "turn.h"

typedef std::vector<Turn> Turns;

class GameData {
public:
	GameData();
	~GameData();

	int getWorldWidth() const;
	int getWorldHeight() const;
	std::string getBackgroundColor() const;

	void setWorldWidth(int worldWidth);
	void setWorldHeight(int worldHeight);
	void setBackGroundColor(const std::string& backgroundColor);

	void initTurns(int gameTurnsCount);

	Turn* getTurnPtr(int gameTurnIdx);

private:
	int worldWidth;
	int worldHeight;
	std::string backgroundColor;
	Turns turns;
};

#endif // __GAME_DATA_H__