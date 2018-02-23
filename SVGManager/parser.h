#ifndef __PARSER_H__
#define __PARSER_H__

#include "parser_constants.h"
#include "game_data.h"

class Parser {
public:
	Parser();
	~Parser();

	GameData* getGameData() const;
	void setGameData(GameData* gameData);

	void processGameTurns(const std::string& value) const;

	void handleLine(const std::string& line);
	void parseGameFiles();
	void parseMainGameFile();
	void processTag(const std::string& tag, const std::string& value);
	void processTagLine(const std::string& line);
	void processGameTurn(const std::string& value);
	void processSimulatedTurns(const std::string& value);
	void parseSimulatedTurnFiles();

	LineType getLineType(const std::string& line) const;

	std::string generateSimTurnFileName(int turnId, int simTurnIdx) const;

private:
	GameData* gameData;
	Turn* turn;
	SimulatedTurn* simulatedTurn;
};

#endif //__PARSER_H__
