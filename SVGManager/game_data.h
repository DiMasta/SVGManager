#ifndef __GAME_DATA_H__
#define __GAME_DATA_H__

#include <vector>

#include "turn.h"
#include "object.h"

typedef std::vector<Turn> Turns;
typedef std::vector<Object*> Objects;

class GameData {
public:
	GameData();
	~GameData();

	float getWorldWidth() const;
	float getWorldHeight() const;
	std::string getBackgroundColor() const;

	void setWorldWidth(float worldWidth);
	void setWorldHeight(float worldHeight);
	void setBackGroundColor(const std::string& backgroundColor);

	void initTurns(int gameTurnsCount);
	void initObjects(int objectsCount);

	Turn* getTurnPtr(int gameTurnIdx);
	Object* getObjectPtr(int objectIdx);

private:
	float worldWidth;
	float worldHeight;
	std::string backgroundColor;

	Objects objects;
	Turns turns;
};

#endif // __GAME_DATA_H__