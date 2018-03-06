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

//*************************************************************************************************************
//*************************************************************************************************************

string SVGManager::constructStrokeForRGB(int r, int g, int b) const {
	string res = STROKE;
	res.append(RGB_BEGIN);
	res.append(to_string(r));
	res.append(",");
	res.append(to_string(g));
	res.append(",");
	res.append(to_string(b));
	res.append(RGB_END);

	return res;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGManager::constructStrokeWidth(int width) const {
	string res = STROKE_WIDTH;
	res.append(to_string(width));
	return res;
}

//*************************************************************************************************************
//*************************************************************************************************************

std::string SVGManager::constructGId(int id) const {
	string res = ID_BEGIN;
	res.append(to_string(id));
	res.append("\" ");
	return res;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGManager::constructMultiLineTitle(const vector<string>& titleLines) const {
	string res = TITLE_BEGIN;
	for (size_t lineIdx = 0; lineIdx < titleLines.size(); ++lineIdx) {
		res.append(TSPAN_BEGIN);
		res.append(titleLines[lineIdx]);
		res.append(TSPAN_END);
		res.append("\n");
	}
	res.append(TITLE_END);

	return res;
}
