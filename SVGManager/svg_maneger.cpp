#include "svg_manager.h"

using namespace std;

SVGManager::SVGManager() :
	parser(),
	creator(),
	gameData()
{

}

//*************************************************************************************************************
//*************************************************************************************************************

SVGManager::~SVGManager() {
}

//*************************************************************************************************************
//*************************************************************************************************************

void SVGManager::obtainGameSimulation() {
	parser.setScope(Scope::GAME);
	parser.setGameData(&gameData);
	parser.parseGameFile(MAIN_GAME_FILE);

	creator.setGameData(&gameData);
	creator.createGameSimulation();
}