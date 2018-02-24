#include "game_data.h"

using namespace std;

GameData::GameData() :
	turns(0)
{

}

//*************************************************************************************************************
//*************************************************************************************************************

GameData::~GameData() {
	turns.clear();
}

//*************************************************************************************************************
//*************************************************************************************************************

int GameData::getWorldWidth() const {
	return worldWidth;
}

//*************************************************************************************************************
//*************************************************************************************************************

int GameData::getWorldHeight() const {
	return worldHeight;
}

//*************************************************************************************************************
//*************************************************************************************************************

string GameData::getBackgroundColor() const {
	return backgroundColor;
}

//*************************************************************************************************************
//*************************************************************************************************************

void GameData::setWorldWidth(int worldWidth) {
	this->worldWidth = worldWidth;
}

//*************************************************************************************************************
//*************************************************************************************************************

void GameData::setWorldHeight(int worldHeight) {
	this->worldHeight = worldHeight;
}

//*************************************************************************************************************
//*************************************************************************************************************

void GameData::setBackGroundColor(const string& backgroundColor) {
	this->backgroundColor = backgroundColor;
}

//*************************************************************************************************************
//*************************************************************************************************************

void GameData::initTurns(int gameTurnsCount) {
	turns.resize(gameTurnsCount);
}

//*************************************************************************************************************
//*************************************************************************************************************

Turn* GameData::getTurnPtr(int gameTurnIdx) {
	return turns.data() + gameTurnIdx;
}
