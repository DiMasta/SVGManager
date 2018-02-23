#include <fstream>

#include "parser.h"

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

void Parser::parseGameFiles() {
	parseMainGameFile();
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::parseMainGameFile() {
	ifstream mainGameFile(MAIN_GAME_FILE);
	if (mainGameFile.is_open()) {
		string line;
		while (getline(mainGameFile, line)) {
			handleLine(line);
		}

		mainGameFile.close();
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
	if (TAG_GAME_TURNS == tag) {
		processGameTurns(value);
	}
	else if (TAG_GAME_TURN == tag) {
		processGameTurn(value);
	}
	else if (TAG_SIMULATED_TURNS == tag) {
		processSimulatedTurns(value);
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::processGameTurns(const string& value) const {
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

void Parser::processSimulatedTurns(const string& value) {
	const int simulatedTurnsCount = stoi(value);
	turn->initSimulatedTurns(simulatedTurnsCount);
	simulatedTurn = turn->getSimulatedTurnPtr(0);

	parseSimulatedTurnFiles();
}

//*************************************************************************************************************
//*************************************************************************************************************

void Parser::parseSimulatedTurnFiles() {
	const int simulatedTurnsCount = turn->getSimulatedTurnsCount();
	const int turnId = turn->getId();

	for (int simTurnIdx = 0; simTurnIdx < simulatedTurnsCount; ++simTurnIdx) {
		const string simulatedTurnFile = generateSimTurnFileName(turnId, simTurnIdx);
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
	fileName.append(to_string(turnId));
	fileName.append(to_string(simTurnIdx));
	fileName.append(SIMULATED_TURN_POSTFIX);

	return fileName;
}
