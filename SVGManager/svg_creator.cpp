#include "svg_creator.h"
#include "svg_creator_constants.h"

using namespace std;

SVGCreator::SVGCreator() :
	gameData(nullptr),
	svgHtmlFileStream()
{

}

//*************************************************************************************************************
//*************************************************************************************************************

SVGCreator::~SVGCreator() {
	svgHtmlFileStream.close();
}

//*************************************************************************************************************
//*************************************************************************************************************

GameData* SVGCreator::getGameData() const {
	return gameData;
}

//*************************************************************************************************************
//*************************************************************************************************************

void SVGCreator::setGameData(GameData* gameData) {
	this->gameData = gameData;
}

//*************************************************************************************************************
//*************************************************************************************************************

void SVGCreator::createGameSimulation() {
	init();
	printLineStr(XML_HEADER_LINE);
	printLineStr(constructSVGOpenTag());

}

//*************************************************************************************************************
//*************************************************************************************************************

void SVGCreator::init() {
	svgHtmlFileStream.open(SVG_HTML_FILE_NAME, ofstream::out | ofstream::trunc);
}

//*************************************************************************************************************
//*************************************************************************************************************

void SVGCreator::printLineStr(const string& lineStr) {
	svgHtmlFileStream << lineStr << endl;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructSVGOpenTag() const {
	string svgOpenTag = "";

	svgOpenTag.append(SVG_OPENNER);
	svgOpenTag += SPACE;

	const string widthVar = constructVariable(WIDTH, to_string(gameData->getWorldWidth()));
	svgOpenTag.append(widthVar);
	svgOpenTag += SPACE;

	const string heightVar = constructVariable(HEIGHT, to_string(gameData->getWorldHeight()));
	svgOpenTag.append(heightVar);
	svgOpenTag += SPACE;

	const string bgStyle = constructStyleStr({ BACKGROUND }, { gameData->getBackgroundColor() });
	const string bgVariable = constructVariable(STYLE, bgStyle);
	svgOpenTag.append(bgVariable);

	svgOpenTag += TAG_END;

	return svgOpenTag;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructVariable(const string& variableName, const string& value) const {
	string variable = "";
	variable.append(variableName);
	variable += EQUAL;
	variable += QUOTE;
	variable.append(value);
	variable += QUOTE;

	return variable;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructStyleStr(const Strings& styleNames, const Strings& styleValues) const {
	string style = "";

	const size_t stylesCount = styleNames.size();

	for (size_t styleIdx = 0; styleIdx < stylesCount; ++styleIdx) {
		style.append(styleNames[styleIdx]);
		style += COLON;
		style.append(styleValues[styleIdx]);
		style += SEMICOLON;
	}

	return style;
}
