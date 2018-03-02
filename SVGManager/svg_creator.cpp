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
	printSVGStr(constructSVGOpenTag());

	printSVGStr(constructSVGGraphicalObjects(gameData->getObjectsPtr()));

	// print turns data

	printSVGStr(constructCloseTag(SVG));
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

	svgOpenTag = constructTag(SVG, svgOpenTag, false);

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

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructTag(const string& tag, const string& value, int closeTag) const {
	string tagStr = "";

	tagStr += TAG_OPEN;
	tagStr.append(tag);
	tagStr += SPACE;

	tagStr.append(value);
	tagStr += SPACE;

	if (closeTag) {
		tagStr += TAG_BEGIN_CLOSE;
	}

	tagStr += TAG_CLOSE;

	return tagStr;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructCloseTag(const string& tag) const {
	string closeTag = "";

	closeTag += TAG_OPEN;
	closeTag.append(tag);
	closeTag += TAG_BEGIN_CLOSE;
	closeTag += TAG_CLOSE;

	return closeTag;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructSVGGraphicalObjects(const Objects* const objects) const {
	string objectsStr = "";

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
	string objectStr = "";

	const ObjectType objectType = object->getType();

	if (ObjectType::POINT == objectType) {
		objectStr = constructPointStr(object);
	}
	else if (ObjectType::CIRCLE == objectType) {
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

string SVGCreator::constructPointStr(const Object* const object) const {
	string pointStr = "";

	const Point* point = dynamic_cast<const Point*>(object);

	pointStr.append(constructVariable(CIRCLE_X, to_string(point->getXCoord())));
	pointStr += SPACE;

	pointStr.append(constructVariable(CIRCLE_Y, to_string(point->getYCoord())));
	pointStr += SPACE;

	pointStr.append(constructVariable(CIRCLE_RADIUS, to_string(POINT_RADIUS)));
	pointStr += SPACE;

	pointStr.append(constructObjectStyleVar(object));

	pointStr = constructTag(CIRCLE, pointStr, true);

	return pointStr;
}

//*************************************************************************************************************
//*************************************************************************************************************

string SVGCreator::constructCircleStr(const Object* const object) const {
	string circleStr = "";

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
