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

	void handleLine(const std::string& line);
	void parseGameFile(const std::string& fileName);
	void parseSimulatedTurnFiles();
	void processTag(const std::string& tag, const std::string& value);
	void processTagLine(const std::string& line);
	void processGameTurn(const std::string& value);
	void processSimulatedTurnsCount(const std::string& value);
	void processObject(const std::string& value);
	void processObjectType(const std::string& value);

	void processGameTurnsCount(const std::string& value) const;
	void processWorldWidth(const std::string& value) const;
	void processWorldHeight(const std::string& value) const;
	void processWorldBGColor(const std::string& value) const;
	void processObjectsCount(const std::string& value) const;
	void processObjectColor(const std::string& value) const;

	LineType getLineType(const std::string& line) const;

	std::string generateSimTurnFileName(int turnId, int simTurnIdx) const;

private:
	GameData* gameData;

	Turn* turn;
	SimulatedTurn* simulatedTurn;
	Object** object;
};

#endif //__PARSER_H__
