#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "game_constants.h"

class Object {
public:
	Object();
	virtual ~Object();

	int getId() const;
	ObjectType getType() const;
	float getXCoord() const;
	float getYCoord() const;

	void setId(int id);
	void setType(ObjectType type);
	void setXCoord(float xCoord);
	void setYCoord(float yCoord);

private:
	int id;
	ObjectType type;
	float xCoord;
	float yCoord;
};

#endif // __OBJECT_H__

