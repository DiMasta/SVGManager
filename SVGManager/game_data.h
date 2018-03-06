#ifndef __GAME_DATA_H__
#define __GAME_DATA_H__

#include <vector>

#include "objects_holder.h"
#include "turn.h"

class GameData : public ObjectsHolder {
public:
	GameData();
	~GameData();

	float getWorldWidth() const;
	float getWorldHeight() const;
	std::string getBackgroundColor() const;

	void setWorldWidth(float worldWidth);
	void setWorldHeight(float worldHeight);
	void setBackGroundColor(const std::string& backgroundColor);
	
	const Turns* const getTurnsPtr();

	void initTurns(int gameTurnsCount);

	Turn* getTurnPtr(int gameTurnIdx);

private:
	float worldWidth;
	float worldHeight;
	std::string backgroundColor;

	Turns turns;
};

#endif // __GAME_DATA_H__