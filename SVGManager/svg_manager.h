#ifndef __SVG_MANAGER_H__
#define __SVG_MANAGER_H__

#include <iostream>
#include <fstream>
#include <vector>

#include "svg_constants.h"
#include "parser.h"
#include "creator.h"
#include "game_data.h"

class SVGManager {
public:
	SVGManager();
	~SVGManager();

	void fileInit();
	void fileDone();
	void fileClose();
	void filePrintStr(std::string strToPrint);
	void obtainGameSimulation();

	std::string constructStrokeForRGB(int r, int g, int b) const;
	std::string constructStrokeWidth(int width) const;
	std::string constructGId(int id) const;
	std::string constructMultiLineTitle(const std::vector<std::string>& titleLines) const;

private:
	std::ofstream svgHtmlFileStream;

	GameData gameData;
	Parser parser;
	Creator creator;
};

#endif // __SVG_MANAGER_H__
