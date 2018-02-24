#ifndef __PARSER_CONSTANTS_H__
#define __PARSER_CONSTANTS_H__

#include <string>

static const std::string MAIN_GAME_FILE = "main_game_file.txt";
static const std::string SIMULATED_TURN_PREFIX = "simulatedTurn";
static const std::string TXT_FILE_POSTFIX = ".txt";
static const std::string TAG_VALUE_DELIMITER = ": ";
static const std::string UNDERSCORE = "_";
static const std::string EMPTY_LINE = "";

// Turn tags
static const std::string TAG_GAME_TURNS_COUNT = "GAME_TURNS_COUNT";
static const std::string TAG_GAME_TURN = "GAME_TURN";
static const std::string TAG_SIMULATED_TURNS_COUNT = "SIMULATED_TURNS_COUNT";

// World tags
static const std::string TAG_WORLD_WIDTH = "WORLD_WIDTH";
static const std::string TAG_WORLD_HEIGHT = "WORLD_HEIGHT";
static const std::string TAG_WORLD_BACKGROUND_COLOR = "WORLD_BACKGROUND_COLOR";

// Objects tags
static const std::string TAG_OBJECTS_COUNT = "OBJECTS_COUNT";
static const std::string TAG_OBJECT = "OBJECT";
static const std::string TAG_OBJECT_TYPE = "OBJECT_TYPE";
static const std::string TAG_OBJECT_COLOR = "OBJRCT_COLOR";

enum class LineType : int {
	INVALID_LINE = -1,
	TAG_LINE = 0,
	EMPTY_LINE,
};

#endif // __PARSER_CONSTANTS_H__
