#ifndef __SVG_CREATOR_CONSTANTS_H__
#define __SVG_CREATOR_CONSTANTS_H__

#include <string>

// Main file that will contain the svg program
static const std::string SVG_HTML_FILE_NAME = "visualDebugTool.html";

// Starting lines
static const std::string XML_HEADER_LINE = "<? xml version = \"1.0\" encoding = \"UTF-8\"?>";
static const std::string SVG_OPENNER = "<svg xmlns = \"http://www.w3.org/2000/svg\" version = \"1.1\"";

// SVG variables
static const std::string WIDTH = "width";
static const std::string HEIGHT = "height";
static const std::string STYLE = "style";

// SVG style variables
static const std::string BACKGROUND = "background";

// HTML strings
static const char TAG_END = '>';

// Common symbols
static const char EQUAL = '=';
static const char QUOTE = '\"';
static const char SPACE = ' ';
static const char COLON = ':';
static const char SEMICOLON = ';';

#endif // __CREATOR_CONSTANTS_H__
