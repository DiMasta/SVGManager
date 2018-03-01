#include <fstream>

#include "parser.h"
#include "point.h"
#include "circle.h"

using namespace std;

Parser::Parser() :
	gameData(nullptr),
	turn(nullptr),
	simulatedTurn(nullptr)
{
}

//*************************************************************************************************************
//*************************************************************************************************************

Parser::~Parser() {

}

//*************************************************************************************************************
//*************************************************************************************************************

GameData* Parser::getGameData() const {
	return gameData;
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::setGameData(GameData* gameData) {
	this->gameData = gameData;
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::parseGameFile(const string& fileName) {
	ifstream gameFile(fileName);
	if (gameFile.is_open()) {
		string line;
		while (getline(gameFile, line)) {
			handleLine(line);
		}

		gameFile.close();
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::handleLine(const string& line) {
	LineType lineType = getLineType(line);

	switch (lineType) {
		case (LineType::TAG_LINE): {
			processTagLine(line);
			break;
		}
		case (LineType::EMPTY_LINE): {
			break;
		}
		default: {
			break;
		}
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processTagLine(const string& line) {
	const size_t delimiterPos = line.find(TAG_VALUE_DELIMITER);
	if (delimiterPos != string::npos) {
		const string tag = line.substr(0, delimiterPos);
		const string value = line.substr(delimiterPos + TAG_VALUE_DELIMITER.length(), line.length());

		processTag(tag, value);
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processTag(const string& tag, const string& value) {
	if (TAG_GAME_TURNS_COUNT == tag) {
		processGameTurnsCount(value);
	}
	else if (TAG_GAME_TURN == tag) {
		processGameTurn(value);
	}
	else if (TAG_SIMULATED_TURNS_COUNT == tag) {
		processSimulatedTurnsCount(value);
	}
	else if (TAG_WORLD_WIDTH == tag) {
		processWorldWidth(value);
	}
	else if (TAG_WORLD_HEIGHT == tag) {
		processWorldHeight(value);
	}
	else if (TAG_WORLD_BACKGROUND_COLOR == tag) {
		processWorldBGColor(value);
	}
	else if (TAG_OBJECTS_COUNT == tag) {
		processObjectsCount(value);
	}
	else if (TAG_OBJECT == tag) {
		processObject(value);
	}
	else if (TAG_OBJECT_TYPE == tag) {
		processObjectType(value);
	}
	else if (TAG_OBJECT_COLOR == tag) {
		processObjectColor(value);
	}
	else if (TAG_OBJECT_CENTER_X == tag) {
		processObjectCenterX(value);
	}
	else if (TAG_OBJECT_CENTER_Y == tag) {
		processObjectCenterY(value);
	}
	else if (TAG_CIRCLE_RADIUS == tag) {
		processCircleRadius(value);
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processGameTurnsCount(const string& value) const {
	const int gameTurns = stoi(value);
	gameData->initTurns(gameTurns);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processGameTurn(const string& value) {
	const int gameTurnIdx = stoi(value);
	turn = gameData->getTurnPtr(gameTurnIdx);
	turn->setId(gameTurnIdx);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processSimulatedTurnsCount(const string& value) {
	const int simulatedTurnsCount = stoi(value);
	turn->initSimulatedTurns(simulatedTurnsCount);
	simulatedTurn = turn->getSimulatedTurnPtr(0);

	parseSimulatedTurnFiles();
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processWorldWidth(const string& value) const {
	const float worldWidth = stof(value);
	gameData->setWorldWidth(worldWidth);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processWorldHeight(const string& value) const {
	const float worldHeight = stof(value);
	gameData->setWorldHeight(worldHeight);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processWorldBGColor(const string& value) const {
	gameData->setBackGroundColor(value);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processObjectsCount(const string& value) const {
	const int objectsCount = stoi(value);
	gameData->initObjects(objectsCount);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processObject(const string& value) {
	const int objectIdx = stoi(value);
	object = gameData->getObjectPtr(objectIdx);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processObjectType(const string& value) {
	if (POINT == value) {
		*object = new Point();
		(*object)->setType(ObjectType::POINT);
	}
	else if (CIRCLE == value) {
		*object = new Circle();
		(*object)->setType(ObjectType::CIRCLE);
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processObjectColor(const string& value) const {
	(*object)->setColor(value);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processObjectCenterX(const string& value) const {
	const float xCoord = stof(value);
	(*object)->setXCoord(xCoord);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processObjectCenterY(const string& value) const {
	const float yCoord = stof(value);
	(*object)->setYCoord(yCoord);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processCircleRadius(const string& value) const {
	const float radius = stof(value);
	
	Circle* circle = dynamic_cast<Circle*>(*object);
	circle->setRadius(radius);
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::parseSimulatedTurnFiles() {
	const int simulatedTurnsCount = turn->getSimulatedTurnsCount();
	const int turnId = turn->getId();

	for (int simTurnIdx = 0; simTurnIdx < simulatedTurnsCount; ++simTurnIdx) {
		const string simulatedTurnFile = generateSimTurnFileName(turnId, simTurnIdx);

		parseGameFile(simulatedTurnFile);
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

LineType Parser::getLineType(const string& line) const {
	LineType lineType = LineType::INVALID_LINE;

	if (line.find(TAG_VALUE_DELIMITER) != string::npos) {
		lineType = LineType::TAG_LINE;
	}
	else if (EMPTY_LINE == line) {
		lineType = LineType::EMPTY_LINE;
	}

	return lineType;
}

//*************************************************************************************************************
//*************************************************************************************************************

string Parser::generateSimTurnFileName(int turnId, int simTurnIdx) const {
	string fileName = SIMULATED_TURN_PREFIX;
	fileName.append(UNDERSCORE);
	fileName.append(to_string(turnId));
	fileName.append(UNDERSCORE);
	fileName.append(to_string(simTurnIdx));
	fileName.append(TXT_FILE_POSTFIX);

	return fileName;
}
