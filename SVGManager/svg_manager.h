#ifndef __SVG_MANAGER_H__
#define __SVG_MANAGER_H__

#include <iostream>
#include <fstream>
#include <vector>

#include "svg_constants.h"
#include "parser.h"
#include "svg_creator.h"
#include "game_data.h"

class SVGManager {
public:
	SVGManager();
	~SVGManager();

	void obtainGameSimulation();

	std::string constructStrokeForRGB(int r, int g, int b) const;
	std::string constructStrokeWidth(int width) const;
	std::string constructGId(int id) const;
	std::string constructMultiLineTitle(const std::vector<std::string>& titleLines) const;

private:
	GameData gameData;
	Parser parser;
	SVGCreator creator;
};

#endif // __SVG_MANAGER_H__
