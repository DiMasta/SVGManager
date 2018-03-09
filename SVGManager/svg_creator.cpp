#include "svg_creator.h"
#include "svg_creator_constants.h"
#include "point.h"
#include "circle.h"

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
	printSVGStr(XML_HEADER_LINE);
	printSVGStr(SCRIPT_LINE);
	printSVGStr(constructSVGOpenTag());
	printSVGStr(TEXT_LINE);

	printSVGStr(constructSVGGraphicalObjects(gameData->getObjectsPtr()));

	printSVGStr(constructSVGTurns());

	printSVGStr(constructTag(SVG, EMPTY_STRING, true));
	done();
}

//*************************************************************************************************************
//*************************************************************************************************************

void SVGCreator::init() {
	svgHtmlFileStream.open(SVG_HTML_FILE_NAME, ofstream::out | ofstream::trunc);
}

//*************************************************************************************************************
//*************************************************************************************************************

void SVGCreator::done() {
	if (svgHtmlFileStream.is_open()) {
		svgHtmlFileStream.close();
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

void SVGCreator::printSVGStr(const string& svgStr) {
	svgHtmlFileStream << svgStr << endl;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructSVGOpenTag() const {
	string svgOpenTag = EMPTY_STRING;

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

	svgOpenTag = constructTag(SVG, svgOpenTag, false);

	return svgOpenTag;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructVariable(const string& variableName, const string& value) const {
	string variable = EMPTY_STRING;
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
	string style = EMPTY_STRING;

	const size_t stylesCount = styleNames.size();

	for (size_t styleIdx = 0; styleIdx < stylesCount; ++styleIdx) {
		style.append(styleNames[styleIdx]);
		style += COLON;
		style.append(styleValues[styleIdx]);
		style += SEMICOLON;
	}

	return style;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructTag(const string& tag, const string& value, int closeTag) const {
	string tagStr = EMPTY_STRING;

	tagStr += TAG_OPEN;
	tagStr.append(tag);

	if (EMPTY_STRING != value) {
		tagStr += SPACE;
		tagStr.append(value);
	}

	if (closeTag) {
		tagStr += TAG_BEGIN_CLOSE;
	}

	tagStr += TAG_CLOSE;

	return tagStr;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructGroup(const string& id, const string& style, const string& content) const {
	string groupStr = EMPTY_STRING;
	groupStr.append(constructVariable(ID, id));

	if (EMPTY_STRING != style) {
		groupStr += SPACE;
		groupStr.append(constructVariable(STYLE, style));
	}

	groupStr = constructTag(TAG_GROUP, groupStr, false);

	groupStr += NEW_LINE;
	groupStr.append(content);
	groupStr += NEW_LINE;

	groupStr.append(constructTag(TAG_GROUP, EMPTY_STRING, true));

	return groupStr;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructTurnId(int turnIdx, int simTurnIdx) const {
	string turnId = EMPTY_STRING;

	turnId.append(TURN);
	turnId.append(to_string(turnIdx));

	if (INVALID_ID != simTurnIdx) {
		turnId += UNDERSCORE;
		turnId.append(to_string(simTurnIdx));
	}

	return turnId;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructSVGGraphicalObjects(const Objects* const objects) const {
	string objectsStr = EMPTY_STRING;

	const size_t objectsCount = objects->size();

	for (size_t objIdx = 0; objIdx < objectsCount; ++objIdx) {
		Object* object = objects->at(objIdx);
		const string objStr = constructObjectStr(object);
		objectsStr.append(objStr);

		if (objIdx < objectsCount - 1) {
			objectsStr += NEW_LINE;
		}
	}

	return objectsStr;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructObjectStr(const Object* const object) const {
	string objectStr = EMPTY_STRING;

	const ObjectType objectType = object->getType();

	if (ObjectType::POINT == objectType || ObjectType::CIRCLE == objectType) {
		objectStr = constructCircleStr(object);
	}

	return objectStr;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructObjectStyleVar(const Object* const object) const {
	const string circleColor = object->getColor();
	string fill = NONE;
	if (object->getFill()) {
		fill = object->getColor();
	}

	const Strings styles = { STROKE, FILL, STROKE_WIDTH };
	const Strings stylesValues = { circleColor, fill, to_string(object->getContour()) };
	const string pointStyle = constructStyleStr(styles, stylesValues);

	return constructVariable(STYLE, pointStyle);
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructCircleStr(const Object* const object) const {
	string circleStr = EMPTY_STRING;

	const Circle* circle = dynamic_cast<const Circle*>(object);

	circleStr.append(constructVariable(CIRCLE_X, to_string(circle->getXCoord())));
	circleStr += SPACE;

	circleStr.append(constructVariable(CIRCLE_Y, to_string(circle->getYCoord())));
	circleStr += SPACE;

	circleStr.append(constructVariable(CIRCLE_RADIUS, to_string(circle->getRadius())));
	circleStr += SPACE;

	circleStr.append(constructObjectStyleVar(object));

	circleStr = constructTag(CIRCLE, circleStr, true);

	return circleStr;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructSVGTurns() const {
	string turnsStr = EMPTY_STRING;
	const Turns* const turns = gameData->getTurnsPtr();
	const int turnsCount = static_cast<int>(turns->size());

	for (int turnIdx = 0; turnIdx < turnsCount; ++turnIdx) {
		string turnStr = constructSVGTurn(turnIdx, &turns->at(turnIdx));
		string turnId = constructTurnId(turnIdx);
		string turnStyle = constructStyleStr({ DISPLAY }, { NONE });

		turnsStr.append(constructGroup(turnId, turnStyle, turnStr));

		if (turnIdx < turnsCount - 1) {
			turnsStr += NEW_LINE;
			turnsStr += NEW_LINE;
		}
	}

	return turnsStr;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructSVGTurn(int turnIdx, const Turn* const turn) const {
	string turnStr = EMPTY_STRING;

	const SimulatedTurns* const simulatedTurns = turn->getSimulatedTurnsPtr(turnIdx);
	const int simTurnsCount = static_cast<int>(simulatedTurns->size());

	for (int simTurnIdx = 0; simTurnIdx < simTurnsCount; ++simTurnIdx) {
		string simulatedTurnStr = constructSVGSimulatedTurn(&simulatedTurns->at(simTurnIdx));
		string simTurnId = constructTurnId(turnIdx, simTurnIdx);
		string simTurnStyle = constructStyleStr({ DISPLAY }, { NONE });

		turnStr.append(constructGroup(simTurnId, simTurnStyle, simulatedTurnStr));

		if (simTurnIdx < simTurnsCount - 1) {
			turnStr += NEW_LINE;
			turnStr += NEW_LINE;
		}
	}

	return turnStr;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructSVGSimulatedTurn(const SimulatedTurn* const simTurn) const {
	return constructSVGGraphicalObjects(simTurn->getObjectsPtr());
}
