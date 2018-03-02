#ifndef __SVG_CREATOR_H__
#define __SVG_CREATOR_H__

#include <fstream>
#include <string>
#include <vector>

#include "game_data.h"

typedef std::vector<std::string> Strings;

class SVGCreator {
public:
	SVGCreator();
	~SVGCreator();

	GameData* getGameData() const;

	void setGameData(GameData* gameData);

	void createGameSimulation();
	void init();
	void printLineStr(const std::string& lineStr);

	std::string constructSVGOpenTag() const;
	std::string constructVariable(const std::string& variableName, const std::string& value) const;
	std::string constructStyleStr(const Strings& styleNames, const Strings& styleValues) const;

private:
	GameData* gameData;
	std::ofstream svgHtmlFileStream;
};

#endif // __SVG_CREATOR_H__
