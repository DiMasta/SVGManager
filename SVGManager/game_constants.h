#ifndef __GAME_CONSTATNS_H__
#define __GAME_CONSTATNS_H__

static const int INVALID_ID = -1;

static const float POINT_RADIUS = 5.f;

static const char UNDERSCORE = '_';

enum class ObjectType : int {
	INVALID_OBJECT = -1,
	POINT = 0,
	CIRCLE,
};

#endif // __GAME_CONSTATNS_H__
