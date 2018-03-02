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
	void done();
	void printSVGStr(const std::string& lineStr);

	std::string constructSVGOpenTag() const;
	std::string constructVariable(const std::string& variableName, const std::string& value) const;
	std::string constructStyleStr(const Strings& styleNames, const Strings& styleValues) const;
	std::string constructTag(const std::string& tag, const std::string& value, int closeTag) const;
	std::string constructCloseTag(const std::string& tag) const;
	std::string constructSVGGraphicalObjects(const Objects* const objects) const;
	std::string constructObjectStr(const Object* const object) const;
	std::string constructObjectStyleVar(const Object* const object) const;
	std::string constructPointStr(const Object* const object) const;
	std::string constructCircleStr(const Object* const object) const;


private:
	GameData* gameData;
	std::ofstream svgHtmlFileStream;
};

#endif // __SVG_CREATOR_H__
