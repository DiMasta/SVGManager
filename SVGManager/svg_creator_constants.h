#ifndef __SVG_CREATOR_CONSTANTS_H__
#define __SVG_CREATOR_CONSTANTS_H__

#include <string>

// Main file that will contain the svg program
static const std::string SVG_HTML_FILE_NAME = "visualDebugTool.html";

// Starting lines
static const std::string XML_HEADER_LINE = "<? xml version=\"1.0\" encoding=\"UTF-8\"?>";
static const std::string SVG_OPENNER = "xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"";

// SVG variables
static const std::string ID = "id";
static const std::string WIDTH = "width";
static const std::string HEIGHT = "height";
static const std::string STYLE = "style";
static const std::string CIRCLE_X = "cx";
static const std::string CIRCLE_Y = "cy";
static const std::string CIRCLE_RADIUS = "r";

// SVG style variables
static const std::string BACKGROUND = "background";
static const std::string STROKE = "stroke";
static const std::string STROKE_WIDTH = "stroke-width";
static const std::string FILL = "fill";
static const std::string DISPLAY = "display";

// SVG style values
static const std::string NONE = "none";

// SVG tags
static const std::string SVG = "svg";
static const std::string CIRCLE = "circle";

// HTML strings
static const char TAG_OPEN = '<';
static const char TAG_BEGIN_CLOSE = '/';
static const char TAG_CLOSE = '>';

static const std::string TAG_GROUP = "g";

// Common symbols
static const char EQUAL = '=';
static const char QUOTE = '\"';
static const char SPACE = ' ';
static const char COLON = ':';
static const char SEMICOLON = ';';
static const char NEW_LINE = '\n';

static const std::string EMPTY_STRING = "";

// Helper strings
static std::string TURN = "turn";

#endif // __CREATOR_CONSTANTS_H__
