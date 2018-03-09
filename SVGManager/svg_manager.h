#ifndef __SVG_MANAGER_H__
#define __SVG_MANAGER_H__

#include <iostream>
#include <fstream>
#include <vector>

#include "parser.h"
#include "svg_creator.h"
#include "game_data.h"

class SVGManager {
public:
	SVGManager();
	~SVGManager();

	void obtainGameSimulation();

private:
	GameData gameData;
	Parser parser;
	SVGCreator creator;
};

#endif // __SVG_MANAGER_H__
